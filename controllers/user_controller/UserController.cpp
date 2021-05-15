//
// Created by amirmjrd on 5/15/21.
//

#include "UserController.h"

UserController::UserController(const User &user) : user(user) {}

UserController::UserController() : user() {}

bool UserController::deposit(double amount) {
    if (amount >= 5000) {
        this->user.addAmount(amount);
        fileHandler.changeUser(this->user);
        return true;
    } else return false;
}
