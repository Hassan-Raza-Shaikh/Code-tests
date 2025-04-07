#include <iostream>
#include <string>
using namespace std;

class user {
protected:
    string username;
    string password;
};

class bankaccount : public user {
private:
    float balance;

public:
    bankaccount(float b) {
        username = "john";
        password = "lol";
        balance = b;
    }

    void display() const
    {
        cout << "Login Successful!" << endl;
        cout << "Account balance: " << balance << endl;
    }

    friend void validateLogin(const bankaccount&, const string&, const string&);
};

void validateLogin(const bankaccount& acc, const string& u, const string& p) {
    if (acc.username == u && acc.password == p) 
    {
       acc.display();
    } else 
    {
        cout << "Login failed!" << endl;
        cout << "Invalid username or password." << endl;
    }
}

int main() {
    string u, p;
    bankaccount bank(1000);

    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;

    validateLogin(bank, u, p);

    return 0;
}
