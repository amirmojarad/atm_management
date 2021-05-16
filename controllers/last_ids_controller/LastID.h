//
// Created by amirmjrd on 5/16/21.
//

#ifndef ATM_LASTID_H
#define ATM_LASTID_H


class LastID {
private:
    int transaction;
    void fetchID();
public:
    void updateID();
    int getTransaction() const;
};


#endif //ATM_LASTID_H
