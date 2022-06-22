#include <bits/stdc++.h>
#include "Bank.h"
#include <conio.h>
#define TAB "\t\t\t\t\t\t\t\t\t"
using namespace std;


// In this implementation file, we have tried to keep the order of the functions as they are called in the driver code.

int acno = 1; // this global variable is used to assign account number when the account is created.

// also we will assign account number as 1,2,3.. and so on...

//Constructor of the class Bank will make the head NULL.
Bank::Bank() {
    head = NULL;
    count = 0; // doubtful why is it here?
    cout<<fixed;
}

//create function will create account by asking several details that are required for creating a account.
void Bank::create() {
    Bank *temp = new Bank; //doubtful, why is it here?
    details data; //made a object of class details ( used to store data of customer )

    //if the name is written in any other format, that will cause issues, so please write in the form mentioned.
    cout << TAB"Enter your name(first-name middle-name last-name): ";
    cin.ignore();
    getline(cin, data.name);
    cout << TAB"Enter your birth-date: ";
    cin >> data.dob;
    cout << TAB"Enter your number: ";
    cin >> data.num;
    cout << TAB"Enter your aadhar: ";
    cin >> data.aadhar;
    cout << TAB"Enter your account type: " << endl;
    cout << TAB"(S for savings account or C for current account): ";
    cin >> data.account_type;
    cout << TAB"Enter the password: ";
    data.password = getPassword(); // this function will take password with astericks
    while (1) {
        if (checkPass(data.password)) {
            break;
        } else {
            cout << TAB"Enter the password: ";
            data.password = getPassword();
        }
    }
    if (data.account_type == "S") {
        cout << TAB"Enter the money you want to deposit (minimum 250): ";
        float money;
        cin>>money;
        while(1){
            if(money>=250){
                break;
            }else{
                cout<<TAB"You must deposit more than 250 rupees.\n";
                cout <<TAB"Enter the money you want to deposit (minimum 250): ";
                cin>>money;
            }
        }
        data.balance = money;
    } else {
        cout << TAB"Enter the money you want to deposit (minimum 1000): ";
        float money;
        cin>>money;
        while(1){
            if(money>=(float)1000){
                break;
            }else{
                cout<<TAB"You must deposit more than 1000 rupees.\n";
                cout <<TAB"Enter the money you want to deposit (minimum 1000): ";
                float money;
                cin>>money;
            }
        }
        data.balance = money;
    }

    data.accountNum = acno;

    data.req = 0;
    data.amountLoan = 0;
    //calls insert function and it will insert details in a node of customer.
    insert(data.accountNum, data.name, data.num, data.aadhar, data.dob, data.account_type, data.password, data.balance,
           data.req, data.amountLoan,data.recent[0],data.recent[1],data.recent[2]);
    count++;
    cout << TAB"New account created successfully." << endl;
    cout << TAB"Your Account Number is " << acno <<"."<< endl;
    acno++;

}


//it will insert the details of in a node of the customer.
//will assign head to the node of the first customer.
void Bank::insert(int acc, string s1, long long l1, long long l2, string s2, string s3, string s4, float i2,
             int req_us, int amount,float arr1,float arr2,float arr3) {
    Bank *temp = new Bank;
    temp->next = NULL;
    temp->d.accountNum = acc;
    temp->d.name = s1;
    temp->d.num = l1;
    temp->d.aadhar = l2;
    temp->d.dob = s2;
    temp->d.account_type = s3;
    temp->d.password = s4;
    temp->d.balance = i2;
    temp->d.req = req_us;
    temp->d.amountLoan = amount;

    temp->d.recent[0]=arr1;
    temp->d.recent[1]=arr2;
    temp->d.recent[2]=arr3;
    if (head == NULL) {
        head = temp;
    } else {
        Bank *it =head;

        while (it->next != NULL) {
            it = it->next;
        }
        it->next = temp;
    }

}
//login function which will ask for A/C No. ANd check Weather the password
//If the password is right then it will return node of that particular customer.
//Note: This Function is Called Internally from some other Functions s/insert funciton will insert details of customers which need customer details.
Bank *Bank::login() {
    cout << TAB"Enter your Account Nubmer: ";
    int ac;
    cin >> ac;
    Bank *temp = head;
    //Check Weather the dob is in database or not
    bool flag = false;
    int no = 1;

    while (temp != NULL) {
        if (ac == temp->d.accountNum) {
            cout << TAB"Enter your password: ";
            string pass;
            pass = getPassword();
            int tries = 4;
            // this will run 5 times and if the customer don't enter the right password
            while (1) {
                if (pass == temp->d.password) {
                    return temp;
                } else {
                    cout << TAB"Password was incorrect, Try again. (" << tries << " tries remaining)" << endl;
                    cout << TAB"Enter your password: ";
                    pass = getPassword();
                }
                tries--;
                if (tries == 0) {
                    cout << TAB"Try again later some time." << endl;
                    break;
                }

            }
            flag = true;
        }
        temp = temp->next;
        no++;
    }
    if (flag == false) {
        temp = NULL;
    }
    return temp;
}

//with the help of conio.h and getch it will take paswword from user int the from of ***

string Bank::getPassword() {
    int BACK = 8; //ascii value of backspace
    int RET = 13; //ascii value of enter
    char sp = '*';

    string password = "";
    char input;

    while (1) {

        input = getch();

        if (input == RET) {
            //If enter pressed exit
            cout << endl;
            return password;
        } else if (input == BACK && password.length() != 0) {
            password.pop_back();

            //it will is used to remove printed number on console
            cout << "\b \b";

            continue;
        } else if (input == BACK && password.length() == 0){
            continue;
        }
        password.push_back(input);
        cout << sp;
    }
}
//check Password weather the password is satisfying the conditions or Not
bool checkPass(string pass) {
    bool upper = false, lower = false, special = false, digit = false;
    if (pass.length() >= 8) {
        for (int i = 0; i < pass.length(); i++) {
            if (pass[i] <= 90 && pass[i] >= 65) {
                upper = true;
            } else if (pass[i] <= 122 && pass[i] >= 97) {
                lower = true;
            } else if (pass[i] <= 57 && pass[i] >= 48) {
                digit = true;
            } else if (pass[i] == 64 || pass[i] == 35 || pass[i] == 42) {
                special = true;
            }
        }
        if (upper == true && lower == true && special == true && digit == true) {
            return true;
        } else {
            // requirements of password
            cout << TAB"Invalid Password.\n"
                    TAB"Your password must fulfill the following criteria:\n"
                    TAB"at least 1 upper case character\n"
                    TAB"at least 1 digit from 0 to 9\n"
                    TAB"at least 1 lower case character\n"
                    TAB"at least 1 special character(#, @ or *)\n";
            return false;
        }
    } else {
        cout << TAB"Password should be of minimum 8 characters.\n";
        return false;
    }
}


//For Customer to show his/her account details
void Bank::displayAcc() {
    Bank *temp = login();
    if (temp == NULL) {
        cout << "error" << endl;
    } else {
        cout<<endl;
        cout << TAB"Account No. " << temp->d.accountNum << endl << TAB"Name :" << temp->d.name << endl
             << TAB "Date of birth: "
             << temp->d.dob << endl << TAB"Mobile Number: " << temp->d.num << endl << TAB"Aadhar Number: "
             << temp->d.aadhar
             << endl << TAB"Current Balance: " <<setprecision(2)<< temp->d.balance << endl;
             if(temp->d.account_type=="S"){
                cout<<TAB"Account Type: Saving Account"<<endl;
             }
             else{
                cout<<TAB"Account Type: Current Account"<<endl;
             }

    }
}

// For Customer to modify his A/C details.
void Bank::modify() {
    Bank *temp = login();
    cout << TAB"--> Modification Menu <---" << endl;
    cout << TAB"Enter 1 to modify Name.\n"
            TAB"Enter 2 to modify DOB.\n"
            TAB"Enter 3 to modify Mobile No.\n"
            TAB"Enter 4 to modify Aadhar No.\n"
            TAB"Enter 0 to go back.\n";
    int modChoice=1;
    while(modChoice) {
        cout<<TAB"Enter your choice from the Modification Menu: ";
        cin >> modChoice;
        if (modChoice == 1) {
            cout<<TAB"Enter New Name: ";
            cin.ignore();
            getline(cin, temp->d.name);
            cout << TAB"Name modified successfully\n";
        } else if (modChoice == 2) {
            cout<<TAB"Enter New Birth-Date: ";
            cin >> temp->d.dob;
            cout << TAB"dob changed successfully" << endl;
        } else if (modChoice == 3) {
            cout<<"Enter New Number: ";
            cin >> temp->d.num;
            cout << TAB"Mobile number changed successfully." << endl;
        } else if (modChoice == 4) {
            cout<<TAB"Enter Addhar Number: ";
            cin >> temp->d.aadhar;
            cout << TAB"aadhar number updated successfully." << endl;
        } else if (modChoice == 0) {
            return;
        } else {
            cout << TAB"Enter from 0 to 5.\n";
        }
    }
}


//To deposit Money into the account
void Bank::deposit() {
    Bank *temp = login();
    float money;
    cout << TAB"Enter the Amount of Money You Want to Deposit: ";
    cin >> money;
    temp->d.balance += money;
    cout <<TAB<<setprecision(2)<<money<<" Rupees deposited into your account.\n";

   temp->recentTransactions(money);
}

//Show the customer balance
void Bank::show_balance() {
    Bank *temp = login();
    cout << TAB <<"Balance of your account: "<<setprecision(2)<<temp->d.balance<<endl;
}

//To withdraw Money
void Bank::withdraw_money() {
    Bank *temp = login();
    float money;
    cout << TAB"Enter the Amount of Money You Want to Withdraw: ";
    cin >> money;
    //Max Trans Limit is 50k for saving accounts
    if (temp->d.account_type == "S") {
        if (money > 50000){
            cout << TAB"You Can't Withdraw More than 50,000 Rupees in Single Transaction.\n";
        }
        if (temp->d.balance < money) {
        cout << TAB"Money Can't Be Withdrawn Due to insufficient Funds.\n";
        }
    }

    temp->d.balance -= money;
   temp->recentTransactions(-money);

    cout << TAB <<setprecision(2)<< money << " Rupees withdrawn from your account.\n";
}

//Transfer Money from One A/C to another A/C.
void Bank::Transfer_money() {
    Bank *temp = login();
    int num;
    float money;
    cout << TAB"Enter the Account Number of Reciever: ";
    cin >> num;
    cout << TAB"Enter the Amount of Money You Want to Send: ";
    cin >> money;
    Bank *tp = head;

    while (tp->d.accountNum != num) {
        tp = tp->next;
    }

    if (temp->d.balance < money) {
        cout << TAB"Money Can't Be transferred Due to insufficient Funds.\n";
        return;
    }
    temp->d.balance -= money;

    temp->recentTransactions(-money);
    tp->d.balance += money;
    tp->recentTransactions(money);
    cout<<TAB"Money Has Been Successfully Transferred from A/C No. "<<temp->d.accountNum<<" To A/C No. "<<tp->d.accountNum<<endl;
}

//Request Portal For Credit card,debit card And to display current pending Request.
void Bank::request() {
    Bank *cus = login();
    cout<<endl;
    cout << TAB"-->Welcome To The Request Portal For Cards\n"
            TAB"Enter 1 for new request.\n"
            TAB"Enter 2 for seeing current requests.\n"
            TAB"Enter 0 for logging out...\n";
    cout<<TAB;
    int n1 = 0, n2 = 0;
    cin >> n1;

//1 for credit card || 2 for debit card || 3 for loan || 4 for approve || 5 for reject ||0 for no req
    if (n1 == 1 && (cus->d.req == 5 || cus->d.req == 4 || cus->d.req == 0)) {
        cout << TAB"Enter 1 for credit card request.\n"
                TAB"Enter 2 for debit card request.\n";
        cout<<TAB;
        cin >> n2;
        if (n2 == 1) {
            //  cus->d.debReq=false;
            cus->d.req = 1;
            //1 for credit card
        } else if (n2 == 2) {
            // cus->d.credReq=false;
            cus->d.req = 2;
        }


        cout<<TAB"Request Sent to Bank\n";

    } else if (n1 == 2) {
        if (cus->d.req == 4) {
            cout << TAB"Latest Request was approved by bank\n";
        } else if (cus->d.req == 0) {
            cout << TAB"No Request From you has been received by bank\n";
        } else if (cus->d.req == 5) {
            cout << TAB"latest Request Was Rejected By Bank!!\n";
        } else if (cus->d.req == 1) {
            cout << TAB"Your request For Credit Card is Pending\n";
        } else if (cus->d.req == 2) {
            cout << TAB"Your request For Debit Card is Pending\n";
        } else {
            cout << TAB"Your request for Loan is pending.\n";
        }

    }

}

//To delete A particular Account
void Bank::delete_ac() {
    Bank *temp = login();
    Bank *prev = head;
    if (temp = head) {
        head = temp->next;
        free(temp);
    } else {
        while (1){
            if (prev->next == temp)
                break;
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    cout << TAB"Account Deleted!!!\n";
}

//Loan Request Portal For Customer.
void Bank::reqLoan() {
    Bank *cus = login();
    cout << TAB"Enter the amount of money you want to take for loan (Enter 0 for going back): " << endl;
    int rupee;
    cin >> rupee;
    if (rupee != 0 && cus->d.req!=1 && cus->d.req!=2) {
        cus->d.amountLoan = rupee;
        cus->d.req = 3;
    }
    if(cus->d.req==1 || cus->d.req==2){
        cout<<"Your Current Request is Still Pending You Can not Apply For Loan\n";
        return;
    }
}
//Note:Only Valid For Saving A/c
//It will show how much interest Particular Customer will get after Number of Years.
void Bank::interest() {
    Bank *cus=login();
   if(cus->d.account_type=="C"){
       cout<<TAB"Sorry!! Your Account Type is Current This Feature is Not Included"<<endl;
   }
       cout << TAB"Note: This function is currently on its beta test." << endl;
       cout << TAB"Note: from this Feature you can know how much interest you will get after no. of years." << endl;
       cout << endl;
       cout << TAB"Enter the No. of years: ";
       int years;
       cin >> years;
       float interest = cus->d.balance * 4.0 * years / 100;
       cout << TAB"Your Current Balance is " << cus->d.balance << endl;
       cout << TAB"As Per your Current balance will get " << interest << " rupees as interest after " << years
            << " years." << endl;

}

//Note:Penalty function is Only Valid For Current A/c
//If A/C is Current then only it will work.
/*
 if current account holders do not maintain minimum balance (i.e. 1000 rupees) then account holder will be able to know
 how much penalty he/she will get after no. of months.
*/

void Bank::penalty() {
    Bank *cus=login();
    if(cus->d.account_type=="S"){
        cout<<TAB"Your account is of Savings account, Only current accounts get penalty in certain conditions."<<endl;
        return;
    }
    cout << TAB"Note: This function is currently on its beta test." << endl;
    cout<<TAB"Note: From this feature you will get to know how much penalty you got in rupees after no. of months."<<endl;
        if (cus->d.balance < 1000) {
            cout<<TAB"Enter the No. of months: ";
            int months;
            cin>>months;
            float penalty=cus->d.balance*months/10.0;
            cout<<TAB"you will be fined "<<abs(penalty)<<" after "<<months<<" months in rupees."<<endl;
        } else {
            cout << TAB"You have no penalty as you have maintained minimum balance in your account." << endl;
        }
}


//this Will show latest 3 Transactions by the customer.
// This Function will not call in main.cpp
//It will be called internally During Transfer Functions.

void Bank::recentTransactions(float trans) {
    static int xx=0;
    //This part of code will kind of work like Infinite loop and it will keep track of latest three Transaction
    if(xx==2){
        this->d.recent[2]=trans;
        xx=0;

        return;
    }

    else if(xx==1){
        this->d.recent[1]=trans;
        xx=2;
        return;
    }

   else if(xx==0){
        this->d.recent[0]=trans;
        xx=1;
        return;
    }
}

//It will show Recent Transactions on the display
void Bank::recentshow(){
    Bank *temp=login();
cout<<endl;
cout<<endl;
    for(int j=2;j>=0;j--){
        if(temp->d.recent[j]<(float)0){
            //if recent[j] is lesser than zero that means money has been deducted from particular A/C
            cout<<TAB<<setprecision(2)<<abs(temp->d.recent[j])<<" Money Debited From Your Account\n";
        }
        if(temp->d.recent[j]>(float)0){
            //if recent[j] is greater than zero that means money has been Added t particular A/C
            cout<<TAB<<setprecision(2)<<abs(temp->d.recent[j])<<" Money Added To Your Account\n";
        }
    }
}
