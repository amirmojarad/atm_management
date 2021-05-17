#include <fstream>
#include <sstream>
#include <iostream>
#include "TransactionController.h"
#include <string>


using namespace std;

void TransactionController::makeTransfer(int userID, double amount, string &destination) {
    Transaction transaction(id, userID, TRANSFER, amount, destination);
    addTransaction(transaction);
}

void TransactionController::makeDeposit(int userID, double amount, string &destination) {
    Transaction transaction(id++, userID, DEPOSIT, amount, destination);
    addTransaction(transaction);
}

void TransactionController::makeWithdraw(int userID, double amount, string &destination) {
    Transaction transaction(id++, userID, WITHDRAW, amount, destination);
    addTransaction(transaction);
}

int TransactionController::fetchLastID() {
    fstream file("transactions.txt", ios::in);
    string line, prevLine;
    while (getline(file, line)) {
        prevLine = line;
    }
    if (prevLine.empty()) {
        return 0;
    } else {
        file.close();
        stringstream ss(prevLine);
        ss >> prevLine;
        return stoi(prevLine) + 1;
    }
}

TransactionController::TransactionController() {
    this->id = fetchLastID();
}

void TransactionController::addTransaction(Transaction &transaction) {
    fstream out("transactions.txt", ios::app);
    out << transaction.to_string() << endl;
    out.close();
}

vector<Transaction> TransactionController::getTransactions(int id) {
    vector<Transaction> transactions;
    fstream file("transactions.txt", ios::in);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string properties[6];
        for (int i = 0; i < 6; i++) {
            ss >> properties[i];
        }
        int fetchedID = stoi(properties[1]);
        if (fetchedID == id) {
            Transaction transaction(stoi(properties[0]), stoi(properties[1]), properties[2],
                                    stod(properties[3]),
                                    properties[5], properties[4]);
            transactions.push_back(transaction);
        }
    }
    file.close();
    return transactions;
}
