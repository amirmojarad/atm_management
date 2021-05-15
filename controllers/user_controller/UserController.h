//
// Created by amirmjrd on 5/15/21.
//

#ifndef ATM_USERCONTROLLER_H
#define ATM_USERCONTROLLER_H


#include "../../models/user/User.h"

class UserController {
private:
    User user;
public:
    UserController(const User &user);

    UserController();
};


#endif //ATM_USERCONTROLLER_H
