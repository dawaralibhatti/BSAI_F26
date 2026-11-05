#include <iostream>
using namespace std;

int main()
{
    int x, sum=0;
    cout<< "Enter a number: ";
    cin >> x;
    int Reversed = 0;

    while (x > 0)
    {
        int LastDigit = x % 10;                
        Reversed = (Reversed * 10) + LastDigit;
        x = x / 10;
        sum+=LastDigit;
    }

    cout << "Reversed Number: " << Reversed << endl;
    cout << "Sum of digits: " << sum << endl;

    return 0;
}