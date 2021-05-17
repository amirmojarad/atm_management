//
// Created by amirmjrd on 5/16/21.
//

#ifndef ATM_TRANSACTIONCONTROLLER_H
#define ATM_TRANSACTIONCONTROLLER_H


#include <vector>
#include "../../models/transaction/Transaction.h"

class TransactionController {
private:
    int id;
    void addTransaction(Transaction &transaction);
    int fetchLastID();

public:

    TransactionController();

    void makeTransfer(int userID, double amount, string &destination);

    void makeDeposit(int userID, double amount, string &destination);

    void makeWithdraw(int userID, double amount, string &destination);

    vector<Transaction> getTransactions(int id);

};


#endif //ATM_TRANSACTIONCONTROLLER_H
