#include <sstream>
#include "controllers/atm_controller/ATMController.h"
#include "controllers/transaction_controller/TransactionController.h"

int main() {
    ATMController ATM;
    ATM.run();
    return 0;
}
