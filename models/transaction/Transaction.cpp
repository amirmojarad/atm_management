#include "Transaction.h"

string Transaction::to_string() {
    return ::to_string(this->id) + " " + ::to_string(this->userID) + " " + typeToString() + " " +
           ::to_string(this->amount) + " " +
           this->date + " " + this->destination;
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
    time_t now = time(0);
    tm *tmNow = gmtime(&now);
    string year = ::to_string(tmNow->tm_year + 1900);
    return year + ::to_string(tmNow->tm_mon + 1) + ::to_string(tmNow->tm_mday);
}

Transaction::Transaction(int id, int userId, Type type, double amount, const string &destination) : id(id),
                                                                                                    userID(userId),
                                                                                                    type(type),
                                                                                                    amount(amount),
                                                                                                    destination(
                                                                                                            destination) {
    this->date = dateToString();
}

Type Transaction::stringToType(string &type) {
    if (type == "DEPOSIT") return DEPOSIT;
    else if (type == "TRANSFER") return TRANSFER;
    else if (type == "WITHDRAW") return WITHDRAW;
    return WITHDRAW;
}

Transaction::Transaction(int id, int userId, string &type, double amount, const string &destination, string &date) : id(
        id), userID(userId), amount(amount), destination(destination), date(date) {
    this->type = stringToType(type);
}

string Transaction::printTransaction() {
    if (destination == "0")
        return "Type: " + this->typeToString() + " Amount: " + ::to_string(this->amount) + " Date: " + this->date;
    else
        return "Type: " + this->typeToString() + " Amount: " + ::to_string(this->amount) + " Date: " + this->date +
               " Destination: " + this->destination;

}
