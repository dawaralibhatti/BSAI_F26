<?php
// Lists every .html in this folder and every .pdf in PDF/ so index.html can show them automatically.
header('Content-Type: application/json; charset=utf-8');
header('Cache-Control: no-store');
$out = [];
foreach (glob(__DIR__ . '/*.{html,htm,HTML,HTM}', GLOB_BRACE) as $f) {
    $b = basename($f);
    if (strtolower($b) !== 'index.html') $out[] = $b;
}
foreach (glob(__DIR__ . '/PDF/*.{pdf,PDF}', GLOB_BRACE) as $f) {
    $out[] = 'PDF/' . basename($f);
}
echo json_encode($out);
