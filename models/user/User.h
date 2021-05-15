#ifndef ATM_USER_H
#define ATM_USER_H

#include <string>

using namespace std;


class User {
private:
    int id;
    string cardNumber, password;
    double balance;
public:
    User(int id, const string &cardNumber, const string &password, double balance) : id(id),
                                                                                     cardNumber(cardNumber),
                                                                                     password(password),
                                                                                     balance(balance) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        User::id = id;
    }

    const string &getCardNumber() const {
        return cardNumber;
    }

    void setCardNumber(const string &cardNumber) {
        User::cardNumber = cardNumber;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        User::password = password;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double balance) {
        User::balance = balance;
    }

    User() {
        this->balance = 0;
        this->id = -1;
        this->cardNumber = "null";
        this->password = "null";
    }

    string to_string() const {
        return this->getId() + " " + this->getCardNumber() + " " + this->getPassword() + " " +
               ::to_string(this->getBalance());
    }
};

#endif //ATM_USER_H
