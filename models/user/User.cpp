//
// Created by amirmjrd on 5/15/21.
//

#include "User.h"

User::User() {
    this->balance = 0;
    this->id = -1;
    this->cardNumber = "null";
    this->password = "null";

}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    User::id = id;
}

const string &User::getCardNumber() const {
    return cardNumber;
}

void User::setCardNumber(const string &cardNumber) {
    User::cardNumber = cardNumber;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

double User::getBalance() const {
    return balance;
}

void User::setBalance(double balance) {
    User::balance = balance;
}

string User::to_string() const {
    return ::to_string(this->getId()) + " " + this->getCardNumber() + " " + this->getPassword() + " " +
           ::to_string(this->getBalance());
}

void User::addAmount(double amount) {
    this->balance += amount;
}
