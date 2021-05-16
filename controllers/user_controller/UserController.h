#ifndef ATM_USERCONTROLLER_H
#define ATM_USERCONTROLLER_H


#include "../../models/user/User.h"
#include "../../file_handler/FileHandler.h"

class UserController {
public:
    User user;

    void setUser(const User &user);

    FileHandler fileHandler;

    UserController();

    bool deposit(double amount);

    bool withdraw(double amount);

    bool moneyTransfer(string &cardNumber, double amount);
};


#endif //ATM_USERCONTROLLER_H
