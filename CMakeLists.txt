cmake_minimum_required(VERSION 3.19)
project(ATM)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATM main.cpp models/user/User.cpp models/user/User.h controllers/ATMController.cpp controllers/ATMController.h)