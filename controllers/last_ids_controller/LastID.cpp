
#include "LastID.h"
#include <fstream>

using namespace std;

int LastID::getTransaction() const {
    return transaction;
}

void LastID::fetchID() {
    fstream file("last_ids.txt", ios::in);
    string line;
    file >> line;
    this->transaction = stoi(line);
    file.close();
}
