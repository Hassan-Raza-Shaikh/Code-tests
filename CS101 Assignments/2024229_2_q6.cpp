#include <iostream>
#include <iomanip>  // for fixed and setprecision
using namespace std;

const int MAX_ACCOUNTS = 100;
int accounts[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
bool open_status[MAX_ACCOUNTS];
int pins[MAX_ACCOUNTS];

int current_account_count = 0;
const int managerPin = 2004;

void openAccount(double initial_deposit, int pin)
{
    if (current_account_count < MAX_ACCOUNTS)
    {
        accounts[current_account_count] = 1001 + current_account_count;
        balances[current_account_count] = initial_deposit;
        pins[current_account_count] = pin;
        open_status[current_account_count] = true;
        cout << "Account opened. Account number: " << accounts[current_account_count] << endl;
        current_account_count++;
    }
    else
    {
        cout << "Cannot open more than " << MAX_ACCOUNTS << " accounts." << endl;
    }
}

void balanceInquiry(int account_number, int pin)
{
    for (int i = 0; i < current_account_count; ++i)
    {
        if (accounts[i] == account_number && open_status[i] && pins[i] == pin)
        {
            cout << "Account number: " << account_number << " Balance: $" << fixed << setprecision(2) << balances[i] << endl;
            return;
        }
    }
    cout << "Invalid account or PIN." << endl;
}

void deposit(int account_number, double amount, int pin)
{
    for (int i = 0; i < current_account_count; ++i)
    {
        if (accounts[i] == account_number && open_status[i] && pins[i] == pin)
        {
            balances[i] += amount;
            cout << "Deposited $" << fixed << setprecision(2) << amount << " to account " << account_number << endl;
            cout << "New Balance: $" << fixed << setprecision(2) << balances[i] << endl;
            return;
        }
    }
    cout << "Invalid account or PIN." << endl;
}

void withdraw(int account_number, double amount, int pin)
{
    for (int i = 0; i < current_account_count; ++i)
    {
        if (accounts[i] == account_number && open_status[i] && pins[i] == pin)
        {
            if (balances[i] >= amount)
            {
                balances[i] -= amount;
                cout << "Withdrew $" << fixed << setprecision(2) << amount << " from account " << account_number << endl;
                cout << "New Balance: $" << fixed << setprecision(2) << balances[i] << endl;
            }
            else
            {
                cout << "Insufficient funds." << endl;
            }
            return;
        }
    }
    cout << "Invalid account or PIN." << endl;
}

void closeAccount(int account_number, int pin)
{
    for (int i = 0; i < current_account_count; ++i)
    {
        if (accounts[i] == account_number && open_status[i] && pins[i] == pin)
        {
            open_status[i] = false;
            cout << "Account " << account_number << " closed." << endl;
            return;
        }
    }
    cout << "Invalid account or PIN." << endl;
}

void computeInterest(double rate, int managerPinInput)
{
    if (managerPinInput == managerPin)
    {
        for (int i = 0; i < current_account_count; ++i)
        {
            if (open_status[i])
            {
                balances[i] += balances[i] * (rate / 100);
            }
        }
        cout << "Interest applied to all open accounts." << endl;
    }
    else
    {
        cout << "Invalid Manager PIN." << endl;
    }
}

void printAllAccounts(int managerPinInput)
{
    if (managerPinInput == managerPin)
    {
        cout << "All Open Accounts:" << endl;
        for (int i = 0; i < current_account_count; ++i)
        {
            if (open_status[i])
            {
                cout << "Account: " << accounts[i] << " Balance: $" << fixed << setprecision(2) << balances[i] << endl;
            }
        }
    }
    else
    {
        cout << "Invalid Manager PIN." << endl;
    }
}

int main()
{
    char transaction;
    int account_number, pin, managerPinInput;
    double amount, interest_rate;

    while (true)
    {
        cout << "Transaction type (O, B, D, W, C, S (I, P, E) )?: ";
        cin >> transaction;

        if(transaction == 'O')
        {
            cout << "Initial deposit?: ";
            cin >> amount;
            cout << "Set a 4-digit PIN: ";
            cin >> pin;
            openAccount(amount, pin);
        }
        else if(transaction == 'B')
        {
            cout << "Account number?: ";
            cin >> account_number;
            cout << "Enter your PIN: ";
            cin >> pin;
            balanceInquiry(account_number, pin);
        }
        else if(transaction == 'D')
        {
            cout << "Account number?: ";
            cin >> account_number;
            cout << "Amount?: ";
            cin >> amount;
            cout << "Enter your PIN: ";
            cin >> pin;
            deposit(account_number, amount, pin);
        }
        else if(transaction == 'W')
        {
            cout << "Account number?: ";
            cin >> account_number;
            cout << "Amount?: ";
            cin >> amount;
            cout << "Enter your PIN: ";
            cin >> pin;
            withdraw(account_number, amount, pin);
        }
        else if(transaction == 'C')
        {
            cout << "Account number?: ";
            cin >> account_number;
            cout << "Enter your PIN: ";
            cin >> pin;
            closeAccount(account_number, pin);
        }
        else if(transaction == 'S')
        {
            if(transaction == 'I')
            {
            cout << "Interest rate?: ";
            cin >> interest_rate;
            cout << "Manager PIN?: ";
            cin >> managerPinInput;
            computeInterest(interest_rate, managerPinInput);
            }
            else if(transaction == 'P')
            {
            cout << "Manager PIN?: ";
            cin >> managerPinInput;
            printAllAccounts(managerPinInput);
            }
            else if(transaction == 'E')
            {
                cout << "Exiting program..." << endl;
                return 0;
            }
            else
            {
                cout << "Invalid transaction type!" << endl;
            }
        }
        else
        {
            cout << "Invalid transaction type!" << endl;
        }
    }

    return 0;
}
