//
// Created by amirmjrd on 5/15/21.
//

#include "ATMController.h"

void ATMController::printMenu() {
    cout << "********************* Welcome to ATM *********************" << endl;
    cout << "1. Login " << endl;
    cout << "2. Exit " << endl;
    cout << "Enter your Request: ";
}

void ATMController::run() {
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

void ATMController::login() {
    string card_number, password;
    cout << "Enter Card Number: " ;
    cin >> card_number;
    cout << "Enter password: ";
    cin >> password;

}
