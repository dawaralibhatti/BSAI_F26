#include<iostream>
using namespace std;
int main()
{
    int salary[6];
    for (int i = 0; i < 6; i++)
    {
        cout<<"Enter salary of person "<<i+1<<": ";
        cin>>salary[i];
    }
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<"Salary of person "<<i+1<<" is: "<<salary[i]<<endl;
    }

    return 0;
}
