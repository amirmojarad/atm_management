//
// Created by amirmjrd on 5/16/21.
//

#ifndef ATM_TRANSACTIONCONTROLLER_H
#define ATM_TRANSACTIONCONTROLLER_H


#include "../../models/transaction/Transaction.h"

class TransactionController {
private:
    static const int id = 0;
public:
    void makeTransfer(int userID, double amount, string &destination);

    void makeDeposit(int userID, double amount, string &destination);

    void makeWithdraw(int userID, double amount, string &destination);
};


#endif //ATM_TRANSACTIONCONTROLLER_H
