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
                withdraw();
                break;
            case 3:
                moneyTransfer();
                break;
            case 4:
                seeInventory();
                break;
            case 5:
                showTransactionList();
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
    string destination = "0";
    transactionController.makeDeposit(this->userController.user.getId(), amount, destination);
}

void ATMController::withdraw() {
    double amount = 0.0;
    cout << "***************************** Withdraw *****************************\n";
    cout << "Enter Amount: ";
    cin >> amount;
    if (amount < 5000) cout << "Please Enter More than 5000\n";
    bool result = userController.withdraw(amount);
    string destination = "0";
    if (!result) cout << "Inventory is not enough";
    else transactionController.makeWithdraw(this->userController.user.getId(), amount, destination);
}

void ATMController::seeInventory() {
    cout << "***************************** See Inventory *****************************\n";
    cout << "Main Inventory " << userController.user.getBalance() << endl;
    cout << "Amount to be withdrawn " << userController.user.getBalance() - 10000 << endl;
}

void ATMController::moneyTransfer() {
    string destCardNumber;
    double amount;
    cout << "***************************** Money Transfer *****************************\n";
    cout << "Enter Destination Card Number: \n";
    cin >> destCardNumber;
    cout << "Enter Amount: \n";
    cin >> amount;
    if (destCardNumber.length() < 10) cout << "Enter a valid Card Number!" << endl;
    else if (amount < 5000) cout << "Please Enter More than 5000\n";
    else {
        userController.moneyTransfer(destCardNumber, amount);
        transactionController.makeTransfer(this->userController.user.getId(), amount, destCardNumber);
    }
}

void ATMController::showTransactionList() {
    cout << "***************************** Show User Transactions *****************************\n";
    vector<Transaction> transactions = transactionController.getTransactions(userController.user.getId());
    for (int i = 0; i < transactions.size(); i++)
        cout << transactions[i].printTransaction() << endl;
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





