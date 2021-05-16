#include "ATMController.h"

void ATMController::printMenu() {
    cout << "********************* Welcome to ATM *********************" << endl;
    cout << "1. Login " << endl;
    cout << "2. Exit " << endl;
    cout << "Enter your Request: " << endl;
}

void ATMController::run() {
    bool flag = false;
    int option = 0;
    while (!flag) {
        printMenu();
        cin >> option;
        switch (option) {
            case 1:
                if (!login()) continue;
                else
                    flag = false;
                break;
            case 2:
                flag = true;
                break;
        }
    }
}

bool ATMController::login() {
    string card_number, password;
    cout << "Enter Card Number: ";
    cin >> card_number;
    cout << "Enter password: ";
    cin >> password;
    userController.setUser(fileHandler.search(card_number, password));
    if (userController.user.getId() != -1) {
        loggedIn();
        return true;
    } else {
        cout << "Error! Account does not Exist!\n";
        return false;
    }
}


void ATMController::loggedIn() {
    bool flag = false;
    int command = 0;
    while (!flag) {
        printLoggedInMenu();
        cin >> command;
        switch (command) {
            case 1:
                deposit();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                //TODO Exit
                flag = true;
                break;
        }
    }
    printLoggedInMenu();

}

void ATMController::deposit() {
    double amount = 0.0;
    cout << "***************************** Deposit *****************************\n";
    cout << "Enter Amount: ";
    cin >> amount;
    userController.deposit(amount);
}

void ATMController::printLoggedInMenu() {
    cout << "*********** Hello Dear User ***********" << endl;
    cout << "1. Deposit to Account\n";
    cout << "2. Withdraw from Bank Account\n";
    cout << "3. Money Transfer\n";
    cout << "4. View inventory\n";
    cout << "5. Transaction List\n";
    cout << "6. Transaction List(By search and Sorted)\n";
    cout << "7. Exit\n";
    cout << "Enter your Request: \n";
}
