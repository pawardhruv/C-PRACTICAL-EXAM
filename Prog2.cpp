// ~~~ QUESTION 2: Encapsulation (BankAccount) ~~~ //

#include <iostream>

using namespace std;

const int Name_Length = 50; 

class BankAccount {
private:

    long accountNumber;
    double balance;
    char ownerName[Name_Length];

public:
    
    BankAccount(long accNum, const char* owner) : accountNumber(accNum), balance(0.0) {
        

        int i = 0;
        while (owner[i] != '\0' && i < Name_Length - 1) { 
            ownerName[i] = owner[i]; 
            i++; 
        }
        ownerName[i] = '\0'; 
    }


    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
    
            cout << "  Credit successful. Deposited $" << amount << "." << endl;
        } else {
            cout << "  Error: Credit amount must be positive." << endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "  Debit successful. Withdrew $" << amount << "." << endl;
        } else if (amount > balance) {
            cout << "  Error: Insufficient funds for withdrawal of $" << amount << "." << endl;
        } else {
            cout << "  Error: Debit amount must be positive." << endl;
        }
    }


    void displayBalance() const {
        cout << "  Account (" << ownerName << "): Current Balance = $" 
             << balance << endl;
    }


    long getAccountNumber() const {
        return accountNumber;
    }
};

void Que2_demo() {
    cout << "--- Task 2: BankAccount Encapsulation Demo ---" << endl;
    

    BankAccount account(987654321, "the onlypawar");
    

    account.displayBalance(); 
    
    
    cout << "Performing credit and debit operations:" << endl;
    account.credit(99999); 
    account.debit(9999); 
    

    account.debit(10000); 
    

    account.displayBalance();
    

    cout << "  Accessing non-sensitive info via Getter: Acc# " << account.getAccountNumber() << endl;
    cout << endl;
}

int main() {

    Que2_demo(); 
    
    return 0;
}