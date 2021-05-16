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
                                                                                     balance(balance) {};

    int getId() const;

    void setId(int id);

    const string &getCardNumber() const;

    void setCardNumber(const string &cardNumber);

    const string &getPassword() const;

    void setPassword(const string &password);

    double getBalance() const;

    void setBalance(double balance);

    void addAmount(double amount);


    User();

    string to_string() const;
};

#endif //ATM_USER_H
