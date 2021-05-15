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
    tm date;
    string destination;

    string typeToString();

    string dateToString();

public:
    Transaction(int id, int userId, Type type, double amount, tm    date, const string &destination);

    Transaction();


    string to_string();


};


#endif //ATM_TRANSACTION_H
