#include "Transaction.h"

Transaction::Transaction(int id, int userId, Type type, double amount, tm date, const string &destination) : id(id),
                                                                                                             userID(userId),
                                                                                                             type(type),
                                                                                                             amount(amount),
                                                                                                             date(date),
                                                                                                             destination(
                                                                                                                     destination) {}

Transaction::Transaction() {}

string Transaction::to_string() {
    return this->id + " " + ::to_string(this->userID) + " " + typeToString() + " " + ::to_string(this->amount) + " " +
           dateToString() + " " + this->destination;
}

string Transaction::typeToString() {
    switch (type) {
        case DEPOSIT:
            return "deposit";
        case TRANSFER:
            return "transfer";
        case WITHDRAW:
            return "withdraw";
    }
}

string Transaction::dateToString() {
    return ::to_string(this->date.tm_year) + ::to_string(this->date.tm_mon) + ::to_string(this->date.tm_mday);
}
