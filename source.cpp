#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    string* accountHolderName;
    double balance;
    static int totalAccount;
public:
    BankAccount(int accNo, string accHolderName, double bal)  : accountHolderName(new string){
        accountNumber = accNo;
        balance = bal;
        *accountHolderName = accHolderName;
        totalAccount++;
    }
    ~BankAccount() {
        delete accountHolderName;
    }
    static void displayTotalAccounts() {
        cout << "Total number of accounts: " << totalAccount<< endl;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }
    BankAccount& operator+(BankAccount& other) {
        double amountToTransfer = 0;
        cout << "Enter amount to transfer from account " << accountNumber << " to account " << other.accountNumber << ": ";
        cin >> amountToTransfer;
        if (balance >= amountToTransfer) {
            balance -= amountToTransfer;
            other.balance += amountToTransfer;
        }
        else {
            cout << "Insufficient balance for transfer!" << endl;
        }
        return *this;
    }
    bool operator==( BankAccount& other)  {
        return balance == other.balance;
    }
    friend void displayAccountDetails( BankAccount& account);
};
int BankAccount::totalAccount = 0;
void displayAccountDetails( BankAccount& account) {
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder: " << *(account.accountHolderName) << endl;
    cout << "Balance: $" << account.balance << endl;
}
int main() {
    int accNo1, accNo2;
    char name1[100], name2[100];
    double balance1, balance2;
    cout << "Enter details for first account:\n";
    cout << "Account Number: ";
    cin >> accNo1;
    cout << "Account Holder Name: ";
    cin.ignore();
    cin.getline(name1, 100);
    cout << "Initial Balance: ";
    cin >> balance1;
    BankAccount account1(accNo1, name1, balance1);
    cout << "\nEnter details for second account:\n";
    cout << "Account Number: ";
    cin >> accNo2;
    cout << "Account Holder Name: ";
    cin.ignore();
    cin.getline(name2, 100);
    cout << "Initial Balance: ";
    cin >> balance2;
    BankAccount account2(accNo2, name2, balance2);
    cout << "\nInitial account details: " << endl;
    displayAccountDetails(account1);
    displayAccountDetails(account2);
    double depositAmount, withdrawAmount;
    cout << "\nEnter deposit amount for account 1: ";
    cin >> depositAmount;
    account1.deposit(depositAmount);
    cout << "Enter withdrawal amount for account 1: ";
    cin >> withdrawAmount;
    account1.withdraw(withdrawAmount);
    cout << "\nEnter deposit amount for account 2: ";
    cin >> depositAmount;
    account2.deposit(depositAmount);
    cout << "Enter withdrawal amount for account 2: ";
    cin >> withdrawAmount;
    account2.withdraw(withdrawAmount);
    cout << "\nAccount details after transactions: " << endl;
    displayAccountDetails(account1);
    displayAccountDetails(account2);
    account1 + account2;
    cout << "\nAccount details after money transfer: " << endl;
    displayAccountDetails(account1);
    displayAccountDetails(account2);
    if (account1 == account2) {
        cout << "\nBoth accounts have the same balance." << endl;
    }
    else {
        cout << "\nBoth accounts have different balances." << endl;
    }
    BankAccount::displayTotalAccounts();
    return 0;
}
