<?php
// Shared leaderboard for the quizzes. Stores one best score per SAP ID per quiz
// in scores_data/scores_<quiz>.json (folder is created automatically and blocked from direct web access).
header('Content-Type: application/json; charset=utf-8');
header('Cache-Control: no-store');

const QUIZZES = ['cpp', 'english'];
const KEEP = 1000;   // max rows stored per quiz
const SHOW = 100;    // max rows returned

$dir = __DIR__ . '/scores_data';
if (!is_dir($dir)) { @mkdir($dir, 0755, true); }
$ht = $dir . '/.htaccess';
if (is_dir($dir) && !is_file($ht)) {
    @file_put_contents($ht, "<IfModule mod_authz_core.c>\nRequire all denied\n</IfModule>\n<IfModule !mod_authz_core.c>\nDeny from all\n</IfModule>\n");
}
if (!is_dir($dir) || !is_writable($dir)) {
    http_response_code(500);
    echo json_encode(['error' => 'storage not writable']);
    exit;
}

function fail($code, $msg) { http_response_code($code); echo json_encode(['error' => $msg]); exit; }
function sort_rows(array &$rows) {
    usort($rows, function ($a, $b) {
        return ($b['score'] <=> $a['score']) ?: ($a['secs'] <=> $b['secs']);
    });
}

$method = $_SERVER['REQUEST_METHOD'] ?? 'GET';

if ($method === 'GET') {
    $quiz = $_GET['quiz'] ?? '';
    if (!in_array($quiz, QUIZZES, true)) fail(400, 'bad quiz');
    $file = "$dir/scores_$quiz.json";
    $rows = is_file($file) ? json_decode((string)file_get_contents($file), true) : [];
    if (!is_array($rows)) $rows = [];
    sort_rows($rows);
    echo json_encode(array_slice($rows, 0, SHOW));
    exit;
}

if ($method !== 'POST') fail(405, 'method not allowed');

$in = json_decode((string)file_get_contents('php://input'), true);
if (!is_array($in)) fail(400, 'bad json');

$quiz = $in['quiz'] ?? '';
if (!in_array($quiz, QUIZZES, true)) fail(400, 'bad quiz');

$name = trim(preg_replace('/[\x00-\x1F\x7F]+/u', ' ', (string)($in['name'] ?? '')));
$name = function_exists('mb_substr') ? mb_substr($name, 0, 60) : substr($name, 0, 60);
$sap  = substr(preg_replace('/[^A-Za-z0-9_-]/', '', (string)($in['sap'] ?? '')), 0, 20);
$max  = (int)($in['max'] ?? 0);
$score = round((float)($in['score'] ?? -1), 2);
$secs = (int)($in['secs'] ?? -1);
if ($name === '' || $sap === '') fail(400, 'name and sap required');
if ($max < 1 || $max > 200) fail(400, 'bad max');
if ($score < 0 || $score > $max) fail(400, 'bad score');
if ($secs < 0 || $secs > 86400) fail(400, 'bad time');

$file = "$dir/scores_$quiz.json";
$fh = fopen($file, 'c+');
if (!$fh) fail(500, 'cannot open store');
flock($fh, LOCK_EX);
$rows = json_decode((string)stream_get_contents($fh), true);
if (!is_array($rows)) $rows = [];

$found = false;
foreach ($rows as &$r) {
    if (($r['sap'] ?? '') === $sap) {
        $found = true;
        if ($score > $r['score'] || ($score == $r['score'] && $secs < $r['secs'])) {
            $r = ['name' => $name, 'sap' => $sap, 'score' => $score, 'max' => $max, 'secs' => $secs];
        }
        break;
    }
}
unset($r);
if (!$found) $rows[] = ['name' => $name, 'sap' => $sap, 'score' => $score, 'max' => $max, 'secs' => $secs];

sort_rows($rows);
$rows = array_slice($rows, 0, KEEP);
ftruncate($fh, 0);
rewind($fh);
fwrite($fh, json_encode($rows));
fflush($fh);
flock($fh, LOCK_UN);
fclose($fh);

echo json_encode(array_slice($rows, 0, SHOW));
