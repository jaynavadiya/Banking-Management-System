#include <bits/stdc++.h>

using namespace std;

#ifndef UNTITLED15_BANK_H
#define UNTITLED15_BANK_H

class details{
public:
    int accountNum;
    string name;
    long long num;
    long long aadhar;
    string dob;
    string account_type;
    string password;
    float balance;
    int req;
    int amountLoan;
    float recent[3]={0,0,0};

};

class Bank{

private:
    details d;
    Bank *next;
    Bank *head;
    int count;


public:
    Bank();
    void create();
    void insert(int,string,long long,long long,string,string,string,float,int,int,float,float,float );
    void displayAcc();
    void modify();
    void deposit();
    void withdraw_money();
    Bank* login();
    void show_balance();
    void searchAcc();

    void Transfer_money();

    void Create_txt();
    void writetofile();
    void readFromFile();
    void delete_ac();
    void request();
    string getPassword();
    void showReq();
    void reqLoan();
    void interest();
    void penalty();
    void display();
    void encrypt();
    void decrypt();
    void recentTransactions(float);
    void recentshow();
    void AprroveReq();
    string id="ADMIN";
    string adminpass="Employee@123";
};

bool checkPass(string);


#endif //UNTITLED15_BANK_H
