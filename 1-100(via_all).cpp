#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
        cout << i <<endl;
    cout << "\n\n";

    int j = 1;
    while (j <= 10)
    {
        cout << j <<endl;
        j++;
    }
    cout << "\n\n";

    int k = 1;
    do
    {
        cout << k <<endl;
        k++;
    } while (k <= 10);

    return 0;
}

