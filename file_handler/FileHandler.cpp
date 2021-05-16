#include "FileHandler.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

User FileHandler::search(const string &card_number, const string &password) {
    switchToRead();
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string words[4];
            int i = 0;
            while (ss >> words[i++]);
            if (card_number == words[1] && password == words[2])
                return User(stoi(words[0]), words[1], words[2], stod(words[3]));
        }
    }
    close();
    return User();
}


User FileHandler::search(int id) {
    switchToRead();
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string words[4];
            int i = 0;
            while (ss >> words[i++]);
            if (id == stoi(words[0]))
                return User(stoi(words[0]), words[1], words[2], stod(words[3]));
        }
    }
    close();
    return User();
}

User FileHandler::search(string &cardNumber) {
    switchToRead();
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string words[4];
            int i = 0;
            while (ss >> words[i++]);
            if (cardNumber == words[1])
                return User(stoi(words[0]), words[1], words[2], stod(words[3]));
        }
    }
    close();
    return User();
}


void FileHandler::close() {
    file.close();
}

void FileHandler::switchToWrite(int mood) {
    switch (mood) {
        case 1:
            file.open(FILE_NAME, ios::out);
            break;
        case 2:
            file.open(FILE_NAME, ios::app);
            break;
    }
}

void FileHandler::switchToRead() {
    file.open(FILE_NAME, ios::in);
}

void FileHandler::addUser(User user) {
    switchToWrite(2);
    file << user.to_string() << endl;
    close();
}

void FileHandler::removeUser(int id) {
    switchToRead();
    fstream tempFile;
    tempFile.open("temp.txt", ios::app);
    if (file.is_open() && tempFile.is_open()) {
        string line;
        while (getline(file, line))
            if (line.find(to_string(id)) == 0)
                continue;
            else
                tempFile << line << endl;
    }
    close();
    switchToWrite(1);
    tempFile.close();
    tempFile.open("temp.txt", ios::in);
    if (tempFile.is_open()) {
        string line;
        while (getline(tempFile, line)) {
            cout << line << endl;
            file << line << endl;
        }
    }
    tempFile.close();
    clearFile("temp.txt", tempFile);
    tempFile.close();
    close();
}

void FileHandler::changeUser(User &changedUser) {
    removeUser(changedUser.getId());
    User user = search(changedUser.getId());
    addUser(changedUser);
}

void FileHandler::clearFile(string title, fstream &file) {
    file.open(title, ios::out);
    file << "";
}

