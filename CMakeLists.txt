cmake_minimum_required(VERSION 3.19)
project(ATM)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATM main.cpp models/user/User.cpp models/user/User.h controllers/atm_controller/ATMController.cpp controllers/atm_controller/ATMController.h controllers/user_controller/UserController.cpp controllers/user_controller/UserController.h file_handler/FileHandler.cpp file_handler/FileHandler.h models/transaction/Transaction.cpp models/transaction/Transaction.h models/transaction/time.cpp models/transaction/time.h controllers/transaction_controller/TransactionController.cpp controllers/transaction_controller/TransactionController.h controllers/last_ids_controller/LastID.cpp controllers/last_ids_controller/LastID.h)