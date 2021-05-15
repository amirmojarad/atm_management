//
// Created by amirmjrd on 5/15/21.
//

#ifndef ATM_USERCONTROLLER_H
#define ATM_USERCONTROLLER_H


#include "../../models/user/User.h"
#include "../../file_handler/FileHandler.h"

class UserController {
public:
    User user;

    UserController(const User &user);

    FileHandler fileHandler;

    UserController();

    bool deposit(double amount);
};


#endif //ATM_USERCONTROLLER_H
