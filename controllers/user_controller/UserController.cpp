#include "UserController.h"
#include <iostream>
#include <string>

using namespace std;


UserController::UserController() : user() {}

bool UserController::deposit(double amount) {
    if (amount >= 5000) {
        this->user.increaseAmount(amount);
        fileHandler.changeUser(this->user);
        return true;
    } else return false;
}

bool UserController::withdraw(double amount) {
    if (amount >= 5000)
        if (this->user.decreaseAmount(amount)) {
            fileHandler.changeUser(this->user);
            return true;
        }
    return false;
}

bool UserController::moneyTransfer(string &cardNumber, double amount) {
    User destUser = fileHandler.search(cardNumber);
    if (this->user.decreaseAmount(amount)) {
        fileHandler.changeUser(this->user);
        destUser.increaseAmount(amount);
        fileHandler.changeUser(destUser);
        return true;
    }
    return false;
}

void UserController::setUser(const User &user) {
    UserController::user = user;
}

