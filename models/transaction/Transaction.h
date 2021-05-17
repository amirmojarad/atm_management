//
// Created by amirmjrd on 5/15/21.
//

#ifndef ATM_TRANSACTION_H
#define ATM_TRANSACTION_H

#include <ctime>
#include <string>

using namespace std;

enum Type {
    DEPOSIT,
    TRANSFER,
    WITHDRAW
};

class Transaction {
private:
    int id, userID;
    Type type;
    double amount;
    string date;
    string destination;

    string typeToString();

    Type stringToType(string &);

    string dateToString();

public:
    Transaction(int id, int userId, Type type, double amount, const string &destination);

    Transaction(int id, int userId, string &type, double amount, const string &destination, string &date);

    string to_string();

    string printTransaction();

};


#endif //ATM_TRANSACTION_H
