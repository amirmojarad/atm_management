#ifndef ATM_ATMCONTROLLER_H
#define ATM_ATMCONTROLLER_H

#include <iostream>
#include "../../models/user/User.h"
#include "../../file_handler/FileHandler.h"
#include "../../controllers/user_controller/UserController.h"
#include "../../controllers/transaction_controller/TransactionController.h"

using namespace std;

class ATMController {
private:
    FileHandler fileHandler;
    UserController userController;
    TransactionController transactionController;

    bool login();

    void loggedIn();

    void deposit();

    void printLoggedInMenu();

    void printMenu();


public:
    void run();

    void withdraw();

    void seeInventory();

    void moneyTransfer();

    void showTransactionList();
};


#endif //ATM_ATMCONTROLLER_H
