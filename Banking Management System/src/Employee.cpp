#include <bits/stdc++.h>
#include "Bank.h"
#include <conio.h>
#define TAB "\t\t\t\t\t\t\t\t\t"
#define tab "\t\t\t\t\t"
using namespace std;


//for employee.. shows every account's details
void Bank::display() {
    Bank *temp = head;
    cout <<"\n\n"<<TAB"\t\tACCOUNT HOLDER LIST\n";

    cout<< tab"==========================================================================================================================\n";
    cout<< tab"   A/c no.  ||           NAME                \t || A/C Type  ||         Mobile No.    ||      Aadhar No.  ||    Balance\n"
           tab"==========================================================================================================================\n";
    while (temp != NULL) {


        cout <<tab "   " << temp->d.accountNum << "  ||\t" << temp->d.name << " \t\t||" << temp->d.account_type << "  ||\t\t  "
             << temp->d.num << "   ||\t         " << temp->d.aadhar << "  ||\t     " << setprecision(2) <<temp->d.balance << endl;
        temp = temp->next;

       /* cout <<tab "   " << temp->d.accountNum << "\t\t" << temp->d.name << " \t\t" << temp->d.account_type << " \t\t   "
             << temp->d.num << "\t         " << temp->d.aadhar << "\t       " << setprecision(2) <<temp->d.balance << endl;
        temp = temp->next;*/
    }
}

//Search In database by name weather the A/C exists or not.
void Bank::searchAcc() {
    Bank *temp = head;
    cout << TAB"Search by Name: ";
    string str;
    cin >> str;
    int count = 0;
    cout<<endl;

  while (temp != NULL) {
        //used find function.
        if (temp->d.name.find(str) != string::npos) {
            cout<<TAB<<"Account No: "<<temp->d.accountNum<<endl;
            cout <<TAB<<"Name: "<<temp->d.name << endl;
        cout<<endl;
            count++;
        }
        temp = temp->next;
    }
    cout << TAB<< count <<" Entries found in database." << endl;
}


//Employee Function
//To Approve or Reject Request Made by Customer
void Bank::AprroveReq() {
    showReq();
    char c1;
    while(1) {
        cout<<TAB"Press Y For Approving or rejecting the requests."<<endl;
        cout<<TAB"Press N for going back..."<<endl;
        cin>>c1;
        if(c1=='Y') {
            int cus;
            cout << TAB "Enter the Account Number of Customer: ";
            cin >> cus;
            Bank *temp = head;
            while (temp->d.accountNum != cus) {
                temp = temp->next;
            }
            cout<<TAB"Press A for approving the request: "<<endl;
            cout<<TAB"Press R for rejecting the request: "<<endl;
            cout<<TAB"Enter your choice: ";
            cin>>c1;
            while(1) {
                if (c1 == 'A') {
                    temp->d.req = 4;
                    cout << TAB"You Have Approved the Customer's Request\n";
                    return;
                } else if (c1 == 'R') {
                    temp->d.req = 5;
                    cout << TAB"Your Have rejected the customer's request." << endl;
                    return;
                } else {
                    cout << "Enter valid choice" << endl;
                }
            }
        }else if(c1=='N'){
            return;
        }
    }
}

//For Employee
//Print the Basic Info of all the Customers into A file named Info.txt
void Bank::Create_txt() {

    fstream file;
    file.open("Info.txt", ios::out);
    Bank *temp = head;

    while (temp != NULL) {
        file << "Account No. " << temp->d.accountNum << endl << "Name :" << temp->d.name << endl << "Date of birth: "
             << temp->d.dob << endl << "Mobile Number: " << temp->d.num << endl << "Aadhar Number: " << temp->d.aadhar
             << endl << "Current Balance: " << temp->d.balance << endl<<endl;
        temp = temp->next;
    }

    file.close();

}

void Bank::showReq() {
    Bank *temp = head;
    while (temp != NULL && temp->d.req != 5 && temp->d.req != 4 && temp->d.req != 0) {
        if (temp->d.req == 2) {
            cout << TAB"Account No: " << temp->d.accountNum << ". \n" << "Name : " << temp->d.name
                 << TAB"Requested for debit card." << endl;
        } else if (temp->d.req == 1) {
            cout << TAB"Account No: " << temp->d.accountNum << ". \n" << temp->d.name << "Requested for credit card."
                 << endl;
        } else if (temp->d.req == 3) {
            cout << TAB"Account No: " << temp->d.accountNum << ". \n " << temp->d.name << " Requested for Loan." << endl;
            cout << TAB"Loan Money: " << temp->d.amountLoan << endl;
        }
        temp = temp->next;
    }
}
