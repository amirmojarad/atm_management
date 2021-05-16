#ifndef ATM_FILEHANDLER_H
#define ATM_FILEHANDLER_H

#include <fstream>
#include "../models/user/User.h"

using namespace std;

#define FILE_NAME "users.txt"

class FileHandler {
private:
    fstream file;

    void switchToRead();

    void clearFile(string , fstream &);

    void switchToWrite(int mood);

public:


    void addUser(User user);

    void removeUser(int id);

    void changeUser(User &changedUser);


    void close();

    User search(const string &card_number, const string &password);

    User search(int id);

};

#endif //ATM_FILEHANDLER_H
