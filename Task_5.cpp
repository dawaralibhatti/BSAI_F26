#include <iostream>
using namespace std;

int main()
{
    int num, start, end, step;

    cout << "Enter the table number: ";
    cin >> num;

    cout << "Enter starting value: ";
    cin >> start;

    cout << "Enter ending value: ";
    cin >> end;

    cout << "Enter step: ";
    cin >> step;

    if (step <= 0)
    {
        step = 1;
    }

    cout << "\n--- Multiplication Table of " << num << " ---\n";
    for (int j = start; j <= end; j += step)
    {
        cout << num << " x " << j << " = " << num * j << endl;
    }

    return 0;
}

