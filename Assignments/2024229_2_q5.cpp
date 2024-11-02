#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ACCOUNTS = 100;
const int START_ACCOUNT_NUMBER = 1001;

int accountNumbers[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];      
bool isOpen[MAX_ACCOUNTS];          
int totalAccounts = 0;              

void openAccount(double initialDeposit) 
{
    if (totalAccounts < MAX_ACCOUNTS) 
    {
        accountNumbers[totalAccounts] = START_ACCOUNT_NUMBER + totalAccounts;
        balances[totalAccounts] = initialDeposit;
        isOpen[totalAccounts] = true;
        cout << "Account opened successfully. Account Number: " << accountNumbers[totalAccounts] << endl;
        totalAccounts++;
    } 
    else 
    {
        cout << "Cannot open new account. Maximum limit reached." << endl;
    }
}

void balanceInquiry(int accountNumber) 
{
    for (int i = 0; i < totalAccounts; i++) 
    {
        if (accountNumbers[i] == accountNumber && isOpen[i]) 
        {
            cout << "Account Number: " << accountNumber << ", Balance: $" << balances[i] << endl;
            return;
        }
    }
    cout << "Account not found or closed." << endl;
}

void deposit(int accountNumber, double amount) 
{
    for (int i = 0; i < totalAccounts; i++) 
    {
        if (accountNumbers[i] == accountNumber && isOpen[i])
        {
            balances[i] += amount;
            cout << "Deposit successful. New Balance: $" << balances[i] << endl;
            return;
        }
    }
    cout << "Account not found or closed." << endl;
}

void withdraw(int accountNumber, double amount) 
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accountNumber && isOpen[i]) 
        {
            if (balances[i] >= amount) 
            {
                balances[i] -= amount;
                cout << "Withdrawal successful. New Balance: $" << balances[i] << endl;
            } 
            else 
            {
                cout << "Insufficient funds." << endl;
            }
            return;
        }
    }
    cout << "Account not found or closed." << endl;
}

void closeAccount(int accountNumber) 
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (accountNumbers[i] == accountNumber && isOpen[i]) 
        {
            isOpen[i] = false;
            cout << "Account " << accountNumber << " closed successfully." << endl;
            return;
        }
    }
    cout << "Account not found or already closed." << endl;
}

void computeInterest(double interestRate) 
{
    for (int i = 0; i < totalAccounts; i++) 
    {
        if (isOpen[i]) 
        {
            balances[i] += balances[i] * (interestRate / 100);
        }
    }
    cout << "Interest applied at " << interestRate << "% to all accounts." << endl;
}

void printAllAccounts() 
{
    cout << "Account Numbers and Balances:" << endl;
    for (int i = 0; i < totalAccounts; i++) 
    {
        if (isOpen[i]) 
        {
            cout << "Account Number: " << accountNumbers[i] << ", Balance: $" << balances[i] << endl;
        }
    }
}

int main() 
{
    char transactionType;
    int accountNumber;
    double amount, interestRate;

    while (true) 
    {
        cout << "Transaction type?: ";
        cin >> transactionType;

        switch (transactionType) 
        {
            case 'O':
                cout << "Initial deposit?: ";
                cin >> amount;
                openAccount(amount);
                break;

            case 'B':
                cout << "Account number?: ";
                cin >> accountNumber;
                balanceInquiry(accountNumber);
                break;

            case 'D':
                cout << "Account number?: ";
                cin >> accountNumber;
                cout << "Amount?: ";
                cin >> amount;
                deposit(accountNumber, amount);
                break;

            case 'W':
                cout << "Account number?: ";
                cin >> accountNumber;
                cout << "Amount?: ";
                cin >> amount;
                withdraw(accountNumber, amount);
                break;

            case 'C':
                cout << "Account number?: ";
                cin >> accountNumber;
                closeAccount(accountNumber);
                break;

            case 'I':
                cout << "Interest rate?: ";
                cin >> interestRate;
                computeInterest(interestRate);
                break;

            case 'P':
                printAllAccounts();
                break;

            case 'E':
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid transaction type." << endl;
        }
    }
    return 0;
}