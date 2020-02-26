//
// Created by morgan on 2/26/20.
//

#ifndef ASSIGNMENT_3_HASHTABLEINTERFACE_H
#define ASSIGNMENT_3_HASHTABLEINTERFACE_H

#include <string>

using namespace std;

class HashTableInterface {
public:
    HashTableInterface(){}

    ~HashTableInterface(){}

    virtual bool add(int hashedKey, string key, string data) = 0;

    virtual int hashKey1(string key) = 0;

    virtual int hashKey2(string key) = 0;

    virtual int hashKey3(string key) = 0;

    virtual int** returnData() = 0;

};

#endif //ASSIGNMENT_3_HASHTABLEINTERFACE_H
