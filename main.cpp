#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;


int findAccount(const int accountNumbers[], int numberOfUsers, int accountNumber) {
    for (int i = 0; i < numberOfUsers; i++) {
        if (accountNumbers[i] == accountNumber) {
            return i;
        }
    }
    return -1;
}


int readInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


int displayMenu() {
    cout << "\n========== GCC BANK ==========\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Send Cash\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "==============================\n";
    return readInteger("Enter choice: ");
}


double deposit(double balance) {
    double amount;
    cout << "Enter amount to deposit (R): ";
    while (!(cin >> amount) || amount <= 0) {
        cout << "Invalid amount. Enter an amount greater than R0.00: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    balance += amount;
    cout << fixed << setprecision(2) << "Deposit successful. New balance: R" << balance << "\n";
    return balance;
}


double withdraw(double balance) {
    double amount;
    cout << "Enter amount to withdraw (R): ";
    while (!(cin >> amount) || amount <= 0 || amount > balance) {
        if (!cin) {
            cout << "Invalid input. Enter a numeric amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (amount <= 0) {
            cout << "Amount must be greater than R0.00. Try again: ";
        } else {
            cout << "Insufficient funds. Available balance: R" << fixed << setprecision(2) << balance << ". Enter a smaller amount: ";
        }
    }
    balance -= amount;
    cout << fixed << setprecision(2) << "Withdrawal successful. New balance: R" << balance << "\n";
    return balance;
}


void sendCash(int senderIndex, const int accountNumbers[], double balances[], int numberOfUsers) {
    int recipientAccount;
    cout << "Enter recipient account number: ";
    while (!(cin >> recipientAccount)) {
        cout << "Invalid account number. Enter a whole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int recipientIndex = findAccount(accountNumbers, numberOfUsers, recipientAccount);
    if (recipientIndex == -1) {
        cout << "Transfer failed. The recipient account does not exist.\n";
        return;
    }
    if (recipientIndex == senderIndex) {
        cout << "Transfer failed. You cannot send cash to your own account.\n";
        return;
    }

    double amount;
    cout << "Enter amount to send (R): ";
    while (!(cin >> amount) || amount <= 0 || amount > balances[senderIndex]) {
        if (!cin) {
            cout << "Invalid input. Enter a numeric amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (amount <= 0) {
            cout << "Amount must be greater than R0.00. Try again: ";
        } else {
            cout << "Insufficient funds. Available balance: R" << fixed << setprecision(2) << balances[senderIndex] << ". Enter a smaller amount: ";
        }
    }

    balances[senderIndex] -= amount;
    balances[recipientIndex] += amount;
    cout << fixed << setprecision(2) << "Transfer successful. R" << amount
         << " sent to account " << accountNumbers[recipientIndex] << ".\n";
    cout << "Your new balance is R" << balances[senderIndex] << ".\n";
}

void checkBalance(const string names[], const int accountNumbers[], const double balances[], int userIndex) {
    cout << "\n------- ACCOUNT BALANCE -------\n";
    cout << "Account holder : " << names[userIndex] << "\n";
    cout << "Account number : " << accountNumbers[userIndex] << "\n";
    cout << fixed << setprecision(2) << "Available balance: R" << balances[userIndex] << "\n";
    cout << "-------------------------------\n";
}

int main() {
    const int numberOfUsers = 3;
    string names[numberOfUsers] = {"Thabo Mokoena", "Lerato Dlamini", "Sipho Nkosi"};
    int accountNumbers[numberOfUsers] = {1001, 1002, 1003};
    int pins[numberOfUsers] = {1234, 2345, 3456};
    double balances[numberOfUsers] = {5000.00, 3500.00, 2500.00};

    cout << "================================\n";
    cout << "       WELCOME TO GCC BANK      \n";
    cout << "================================\n";

    int accountNumber = readInteger("Enter your account number: ");
    int userIndex = findAccount(accountNumbers, numberOfUsers, accountNumber);
    if (userIndex == -1) {
        cout << "Login failed. Account number not found.\n";
        return 0;
    }

    int enteredPin = readInteger("Enter your 4-digit PIN: ");
    if (enteredPin != pins[userIndex]) {
        cout << "Login failed. Incorrect PIN.\n";
        return 0;
    }

    cout << "\nLogin successful. Welcome, " << names[userIndex] << "!\n";
    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                balances[userIndex] = deposit(balances[userIndex]);
                break;
            case 2:
                balances[userIndex] = withdraw(balances[userIndex]);
                break;
            case 3:
                sendCash(userIndex, accountNumbers, balances, numberOfUsers);
                break;
            case 4:
                checkBalance(names, accountNumbers, balances, userIndex);
                break;
            case 5:
                cout << "Thank you for banking with GCC Bank. Goodbye!\n";
                break;
            default:
                cout << "Invalid menu choice. Please select a number from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}

