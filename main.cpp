#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void log_in();
void registr();
void forgot();

main()
{
    int choice;
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"                                      Welcome  to log-in page                                        "<<endl;

    cout<<"*****************************************      MANUE       ************************************************************"<<endl;
    cout<<"                       1) LOGIN                                                                "<<endl;
    cout<<"                       2) REGISTER                                                              "<<endl;
    cout<<"                       3) FORGOT PASSWORD or USERNAME                                           "<<endl;
    cout<<"                       4) EXIT                                                             "<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case  1:
            log_in();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thanks for using this programe\nthis programe is created by jessy...."<<endl;
            break;
        default:
            system("cls");
            cout<<"You have entered wrong information !! "<<endl;
            break;
        main();
    }
}

void log_in()
{
    int count;
    string user ,pass,u ,p ;

    system("cls");

    cout<<"please enter the following details :- "<<endl;
    cout<<"username : ";cin>>user;
    cout<<"\npassword : ";cin>>pass;

    ifstream input("database.txt");

    while(input>>u>>p){
        if(u == user && p == pass){
            count =1;
            system("cls");
        }
    }

    input.close();
    if(count == 1)
    {
        cout<<"Hello " <<user <<"\nLog-in success :-\nWe are glad that you are here.\nThanks for loggoing in  :- \n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout<<"\nLog-in error!!\nPlease check youor name or password !";
        main();
    }
}

void registr()
{
    string regusr ,regpas,ru,rp;
    system("cls");
    cout<<"Enter the user name : ";cin>>regusr;
    cout<<"\nEnter the password : ";cin>>regpas;

    ofstream reg("database.txt",ios::app);
    reg<<regusr<<" "<<regpas<<endl;
    system("cls");
    cout<<"\nRegistration Successfull . "<<endl;
    main();
}

void forgot()
{

    int ch;
    system("cls");
    cout<<"Forgotten ?? We're here to help you\n";
    cout<<"1.Search your id by username \n2.Search your id by password \n3.Main manue \nEnter your choice :";
    cin>>ch;

    switch(ch)
    {
    case 1:
        {
            int count =0;
            string searchusr,su,sp;
            cout<<"\nenter your remembered username : ";cin>>searchusr;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp){
                if(searchusr == su){
                    count = 1;
                }
            }
            searchu.close();
            if(count == 1)
            {

                cout<<"\nHurray!! account found!!"<<endl;
                cout<<"your password is  : " <<sp;
                cin.get();
                cin.get();
                main();
            }
            else
            {
                cout<<"\nSorry!! your userID is not found in database ..\nOr ,you may entered wrong information!!";
                cin.get();
                cin.get();
                main();
            }
            break;
        }
    case 2:
        {
           int count=0;
           string searchpass,su2,sp2;
           cout<<"Enter the remembered password : ";cin>>searchpass;

           ifstream searchp("database.txt");

           while(searchp>>su2>>sp2)
           {
               if(sp2 == searchpass)
               {
                   count =1;
               }
           }
           searchp.close();
           if(count ==1)
           {
               cout<<"Hurray!! your account got found !!\nYour user ID is : " <<su2;
               cin.get();
               cin.get();
               system("cls");
               main();
           }
           else
           {

               cout<<"ops! Sorry ..we cann't find any password in our database\nkindly check your entered information !!";
               cin.get();
               cin.get();
               main();
           }
           break;
        }
    case 3:
        {
            cin.get();
            main();
        }
    default:
        cout<<"Sorry ,You entered rong information ..plz chk before enter --"<<endl;
        forgot();
    }
}
