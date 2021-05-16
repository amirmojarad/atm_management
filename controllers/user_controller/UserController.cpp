#include "UserController.h"
#include <iostream>
#include <string>

using namespace std;

UserController::UserController(const User &user) : user(user) {}

UserController::UserController() : user() {}

bool UserController::deposit(double amount) {
    if (amount >= 5000) {
        cout << this->user.to_string() << endl;
        this->user.addAmount(amount);
        cout << to_string(this->user.getBalance()) << endl;
        fileHandler.changeUser(this->user);
        return true;
    } else return false;
}

void UserController::setUser(const User &user) {
    UserController::user = user;
}
