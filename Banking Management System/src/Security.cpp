// this function will write details of every customer in a file named input.dat
// by doing so, we will have the details stored even after we end the programme.
#include <bits/stdc++.h>
#include "Bank.h"
#include <conio.h>
#define TAB "\t\t\t\t\t\t\t\t\t"
using namespace std;
extern int acno;

void Bank::writetofile(){

    ofstream f;
    decrypt();  //this decrypts the file before writing also

    f.open("input.dat", ios::binary);
    Bank *temp = head;

    while (temp->next != NULL) {
        f << endl << temp->d.accountNum << " " << temp->d.name << " "
          << temp->d.dob << " " << temp->d.num << " " << temp->d.aadhar
          << " " << temp->d.balance << " " << temp->d.password << " " << temp->d.account_type << " " << temp->d.req
          << " " << temp->d.amountLoan<<" "<<temp->d.recent[0]<<" "<<temp->d.recent[1]<<" "<<temp->d.recent[2]
          << endl;

        temp = temp->next;

    }
    f << temp->d.accountNum << " " << temp->d.name << " "
      << temp->d.dob << " " << temp->d.num << " " << temp->d.aadhar
      << " " << temp->d.balance << " " << temp->d.password << " " << temp->d.account_type << " " << temp->d.req << " "
      << temp->d.amountLoan <<" "<<temp->d.recent[0]<<" "<<temp->d.recent[1]<<" "<<temp->d.recent[2];


    f.close();
    encrypt();  // this encrypts the file after writing to the file
}

// this will read data from file and store details in nodes.
// we will call it in the start of the driver, so that if there were any accounts created when the programme ran the last time... they will be stored in linkedlist this time too.

void Bank::readFromFile() {
    fstream f;

    f.open("input.dat", ios::binary | ios::in | ios::out);
    if (!f)
        return;
    decrypt();   // this decrypts the file before reading from file.
    int ac=5;
    string nm;
    string DOB;
    long long mobilenum;
    long long adharnum;
    float bal;
    string fnm,lnm;
    string ac_type;
    string pass;
    int amc;
    int amount;
    float arr1,arr2,arr3;
    string mess;
    this->head=NULL;
    while (!f.eof()) {

        f >> ac >> nm >>fnm>>lnm>> DOB >> mobilenum >> adharnum >> bal >> pass >> ac_type >> amc >> amount
           >> arr1 >> arr2 >> arr3;
    nm=nm+" "+fnm+" "+lnm;
        insert(ac, nm, mobilenum, adharnum, DOB, ac_type, pass, bal, amc, amount,arr1,arr2,arr3);
        acno++;
    }
    f.close();

    //this will encrypt the file after reading is done.
    encrypt();
}

// this will encrypt data of input.dat file, so that no one can read what has been written in the file.
// we will use if after we write the data to the file.

void Bank::encrypt() {
    char ch;
    fstream file1, file2;

    file1.open("input.dat", fstream::in);
    if (!file1) {
        return;
    }
    file2.open("temp.txt", fstream::out);
    if (!file2) {
        return;
    }
    while (file1 >> noskipws >> ch) {
        ch = ch + 96;
        file2 << ch;
    }
    file1.close();
    file2.close();
    file1.open("input.dat", fstream::out);
    if (!file1) {
        return;
    }
    file2.open("temp.txt", fstream::in);
    if (!file2) {
        return;
    }
    while (file2 >> noskipws >> ch)
        file1 << ch;
    file1.close();
    file2.close();
    cout << "\nFile Encrypted Successfully!";
    cout << endl;
}

// this will decrypt the data of input.dat file
/* this function will be called before reading the data and storing in the nodes, because we will have to first decrypt the
encrypted data in order to read the correct data.
*/

void Bank::decrypt() {

    char ch='\0';
    fstream file1,file2;
    file1.open("input.dat", fstream::out);
    if (!file1){
        return;
    }
    file2.open("temp.txt", fstream::in);
    if (!file2) {
        return;
    }
    while (file2 >> noskipws >> ch) {
        ch = ch - 96;
        file1 << ch;
    }
    file1.close();
    file2.close();
    cout << "\nFile Decrypted Successfully!";
    cout << endl;

}
