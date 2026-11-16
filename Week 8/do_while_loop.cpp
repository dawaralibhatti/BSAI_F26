#include<iostream>
using namespace std;
int main()
{
    int i=2,j=1;
    do
    {
        cout<<i<<"x"<<j<<"="<<i*j<<endl;
        j++;
    } while(j<=10);
    return 0;
}