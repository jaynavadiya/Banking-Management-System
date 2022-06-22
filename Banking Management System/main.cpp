#include<bits/stdc++.h>
#include<conio.h>
#include "Bank.h"
#include<windows.h>
#define TAB "\t\t\t\t\t\t\t\t\t"
using namespace std;
//Open the Terminal in full window for better experience.
int main(){
    Bank b;
system("color 71");

    b.readFromFile();
    string c;
    int choice;
    do{  cout<<TAB"\t|===========  Banking Management System  ==========|\n";
        cout <<TAB"\t|==================================================|\n";
        cout <<TAB"\t| Enter C if you are a customer to this bank.      |\n"<<
               TAB"\t| Enter E if you are an employee to this bank.     |\n"<<
               TAB"\t| Enter END to end the programme.                  |\n";
        cout <<TAB"\t|==================================================|\n";
         cout<<TAB"\t|Enter here: ";

        cin>>c;
        if(c=="C"){

            choice = 1;
            do {cout<<TAB"================   Banking Management System   ====================\n";
                cout<<TAB"===================================================================\n";
                cout<<TAB"||\tMenu for Customers:                                      ||\n";
                cout<<TAB"||\tEnter 1 to create account.                               ||\n";
                cout<<TAB"||\tEnter 2 to modify account details.                       ||\n";
                cout<<TAB"||\tEnter 3 to show your account info.                       ||\n";
                cout<<TAB"||\tEnter 4 To add money.                                    ||\n";
                cout<<TAB"||\tEnter 5 for Balance.                                     ||\n";
                cout<<TAB"||\tEnter 6 to withdraw money.                               ||\n";
                cout<<TAB"||\tEnter 7 for transfer money.                              ||\n";
                cout<<TAB"||\tEnter 8 to request for cards.                            ||\n";
                cout<<TAB"||\tEnter 9 to request for loan.                             ||\n";
                cout<<TAB"||\tEnter 10 to Delete Account.                              ||\n";
                cout<<TAB"||\tEnter 11 to check recent transactions.                   ||\n";
                cout<<TAB"||\tEnter 12 to check interest.                              ||\n";
                cout<<TAB"||\tEnter 13 To check for Any Penalty.                       ||\n";
                cout<<TAB"||\tEnter 0 to log out.                                      ||\n";
                cout<<TAB"===================================================================\n";
                cout<<TAB"->\tEnter your choice from Menu: ";
                cin >> choice;
                if (choice == 1) {
                    b.create();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if (choice == 2){
                    b.modify();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if (choice == 3) {
                    b.displayAcc();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if(choice ==4){
                    b.deposit();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if(choice==5){
                    b.show_balance();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if(choice == 6){
                    b.withdraw_money();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice==7){
                    b.Transfer_money();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice==8){
                    b.request();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice == 9){
                    cout<<TAB"Press Any Key to Continue\n";
                    b.reqLoan();
                    getch();
                    system("cls");
                }
                else if(choice==10){
                    b.delete_ac();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }
                else if(choice==11){
                    b.recentshow();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice==12){
                    b.interest();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice==13) {
                    b.penalty();
                    cout << TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if (choice == 0) {
                    cout << TAB"You have logged out successfully.\n" << endl;
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                    break;
                }
            }while(choice!=0);

        }else if(c=="E"){
//Asks Employee for Login Details
            while(1){
                string emPass;
                string id;
                int co=5;
                cout<<TAB"Enter branch unique id: ";
                cin>>id;
                cout<<TAB"Enter employee password: ";
                emPass=b.getPassword();
                if(id==b.id){
                    if (emPass == b.adminpass) {
                        break;
                    }else{
                        co--;
                        cout<<TAB"Wrong Password, Try Again\n";
                        cout<<TAB<<co<<" Tries remaining.\n";
                    }
                }else{
                    cout<<TAB"Enter a valid unique id.\n";
                }

                if(co==0)
                    return 0;
            }
            choice = 1;
            do {cout<<TAB"==================   Banking Management System   ====================\n";
                cout<<TAB"=====================================================================\n";
                cout<<TAB"||\tMenu for Employees:                                        ||\n";
                cout<<TAB"||\tEnter 1 to Display all account details.                    ||\n";
                cout<<TAB"||\tEnter 2 to search accounts by name.                        ||\n";
                cout<<TAB"||\tEnter 3 to show requests from customer                     ||\n";
                cout<<TAB"||\tEnter 4 Download data of Customers in form of txt file.    ||\n";
                cout<<TAB"||\tEnter 0 to Log out...                                      ||\n";
                cout<<TAB"=====================================================================\n";
                cout <<TAB"->\tEnter your choice from Menu: ";
                cin >> choice;
                if (choice == 1) {
                    system("cls");
                    b.display();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                } else if (choice == 2) {
                    b.searchAcc();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice == 3){
                    b.AprroveReq();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }else if(choice==4){
                    b.Create_txt();
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                }
                else if (choice == 0) {
                    cout << TAB"You have exited successfully." << endl;
                    cout<<TAB"Press Any Key to Continue\n";
                    getch();
                    system("cls");
                    break;
                }
            }while(choice!=0);
        }else if(c=="END"){
            cout<<TAB"You have successfully ended the programme."<<endl;
            cout<<TAB"Press Any Key to Continue\n";

            getch();
            system("cls");
            b.writetofile();
            break;
        }
        else{
            cout<<TAB"Invalid input."<<endl;
            cout<<TAB"Please Enter C if you are customer or Enter E if you are employee, Enter END for ending the programme."<<endl;
        }
    }while(c!="END");


    return 0;
}
