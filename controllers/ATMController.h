#ifndef ATM_ATMCONTROLLER_H
#define ATM_ATMCONTROLLER_H

#include <iostream>

using namespace std;

class ATMController {
private:
    void printMenu() {
        cout << "********************* Welcome to ATM *********************" << endl;
        cout << "1. Login " << endl;
        cout << "2. Exit " << endl;
        cout << "Enter your Request: ";
    }

public:
    void run() {
        bool flag = false;
        int option = 0;
        while (!flag) {
            printMenu();
            cin >> option;
            switch (option) {
                case 1:

                    break;
                case 2:
                    flag = true;
                    break;
            }
        }
    }
};


#endif //ATM_ATMCONTROLLER_H
