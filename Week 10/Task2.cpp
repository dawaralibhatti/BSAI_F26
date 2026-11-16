#include<iostream>
using namespace std;
int main()
{
    int marks[10];
    int total = 0;

    for (int i = 0; i < 10; i++)
    {
        cout<<"Enter quiz marks of student "<<i+1<<": ";
        cin>>marks[i];
    }

    for (int i = 0; i < 10; i++)
    {
        total = total + marks[i];
    }

    float average = total / 10.0;

    cout<<endl;
    cout<<"Total marks: "<<total<<endl;
    cout<<"Average marks: "<<average<<endl;

    return 0;
}
