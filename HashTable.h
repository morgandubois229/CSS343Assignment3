//
// Created by morgan on 2/26/20.
//

#ifndef ASSIGNMENT_3_HASHTABLE_H
#define ASSIGNMENT_3_HASHTABLE_H

#include "HashTableInterface.h"

class HashTable : public HashTableInterface {
    struct TableNode {
        string key = "";

        string data = "";

        TableNode* next = nullptr;

        TableNode(string k, string d): key(k), data(d) {
            //No other work is needed
        }

        ~TableNode() {
            tableNodeHelper(this);
        }

        void tableNodeHelper(TableNode* currentNode) {
            if (currentNode->next == nullptr) {
                key = "";
                data = "";
                return;
            }else {
                tableNodeHelper(currentNode->next);
                key = "";
                data = "";
            }
        }

        bool setNext(TableNode* nextNode) {
            this->next = nextNode;
        }

    };

    TableNode* table[4177];

public:
    HashTable();

    ~HashTable();

    bool add(int hashedKey, string key, string data);

    int hashKey1(string key);

    int hashKey2(string key, string data);

    int hashKey3(string key, string data);

    vector<int> returnData();

protected:
    int findLength(TableNode currentNode);
};

#endif //ASSIGNMENT_3_HASHTABLE_H
