#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    // declaration/initialization of variables
    int loop=0, a, final=0, ticket_count=0, age, amount, discount=0;

    // messages
    string age_message="Please enter your age: ";
    string amount_message="Please enter no. of tickets: ";
    string eligible_message="You are eligible to watch this movie.";
    string not_eligible_message="You are not eligible to watch this movie.";
    
    // cinema ticket booking system
    cout<<"Welcome to our cinema ticket booking system!"<<endl;
    cout<<setw(44)<<setfill('=')<<""<<endl;

    // selection of movies and calculation of total amount
    do
    {
        cout<<"1\tAction Hero\t\t800rs\t18+"<<endl;
        cout<<"2\tFunny Friends\t\t500rs\tAll"<<endl;
        cout<<"3\tSpace Adventure\t\t700rs\t13+"<<endl;
        cout<<"4\tMagic Kingdom\t\t600rs\tAll"<<endl;
        cout<<"5\tHorror Night\t\t900rs\t18+"<<endl;
        cout<<setw(44)<<setfill('=')<<""<<endl;

        cout<<"Please select a movie (1-5): ";
        cin>>a;

        switch(a)
        {
            case 1:
                cout<<age_message; cin>>age;
                if(age>=18) 
                { 
                    cout << setfill('-') << setw(7) << "" << "You have selected Action Hero" << setw(8) << "" << endl;
                    cout<<amount_message; cin>>amount;
                    final+=800*amount; ticket_count++; 
                    if (age>60) 
                    {
                        final=final-final*0.15;
                        cout<<"You are eligible for a discount. (-15%)"<<endl;
                    }
                }
                else cout<<not_eligible_message<<endl;
                break;
            case 2:
                cout << setfill('-') << setw(6) << "" << "You have selected Funny Friends" << setw(7) << "" << endl;
                cout<<age_message; cin>>age;
                cout<<amount_message; cin>>amount;
                final+=500*amount; ticket_count++;
                if (age>60) { cout<<"You are eligible for a discount. (-15%)"<<endl; final=final-final*0.15; }
                else if (age<12){ cout<<"You are eligible for a discount. (-20%)"<<endl; final=final-final*0.20; }

                break;
            case 3:
                cout<<age_message; cin>>age;
                if(age>=13) 
                {
                    cout << setfill('-') << setw(5) << "" << "You have selected Space Adventure" << setw(6) << "" << endl;
                    cout<<amount_message; cin>>amount;
                    final+=700*amount; 
                    if (age>60) 
                    { 
                        cout<<"You are eligible for a discount. (-15%)"<<endl; final=final-final*0.15; 
                    }
                    ticket_count++;
                }
                else cout<<not_eligible_message<<endl;
                break;
            case 4:
                cout << setfill('-') << setw(6) << "" << "You have selected Magic Kingdom" << setw(7) << "" << endl;
                cout<<amount_message; cin>>amount;
                final+=600*amount;
                cout<<age_message; cin>>age;
                if (age>60) { cout<<"You are eligible for a discount. (-15%)"<<endl; final=final-final*0.15; }
                else if (age<12){ cout<<"You are eligible for a discount. (-20%)"<<endl; final=final-final*0.20; }
                ticket_count++;
                break;
            case 5:
                
                cout<<age_message; cin>>age;
                if(age>=18) 
                { 
                    cout << setfill('-') << setw(7) << "" << "You have selected Horror Night" << setw(7) << "" << endl;
                    cout<<amount_message;
                    cin>>amount;
                    final+=900*amount; 
                    ticket_count++; 
                    if (age>60) 
                    {
                        final=final-final*0.15;
                        cout<<"You are eligible for a discount. (-15%)"<<endl;
                    }
                }
                else cout<<not_eligible_message<<endl;
                break;
            default:
                cout<<"Invalid selection. Please try again."<<endl;
        }

        // prompt user to continue or exit
        cout<<setw(44)<<setfill('=')<<""<<endl;
        cout<<"Press 1 to exit, press 2 to continue: "; cin>>loop;
        cout<<setw(44)<<setfill('=')<<""<<endl;
        if (loop==1) cout<<"Thanks for using our service!"<<endl;
        if (ticket_count>5) discount=0.10;
    }
    while(loop!=1);

    if (discount!=0) cout<<"Total amount to be paid: (D)"<<final-final*discount<<"rs"<<endl;
    else cout<<"Total amount to be paid: (ND)"<<final<<"rs"<<endl;


    return 0;
}
