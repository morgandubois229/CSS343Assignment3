//
// Created by morgan on 2/26/20.
//
#include <iostream>
#include "HashTable.h"

HashTable::HashTable(){
    for(int i = 0; i < 4177; i++) {
        this->table[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < 4177; i++) {
        if (!(table[i] == nullptr)) {
            delete table[i];
        }
    }
}

bool HashTable::add(int hashedKey, string key, string data){
    TableNode* newNode = new TableNode(key, data);
    if (table[hashedKey] == nullptr) {
        table[hashedKey] = newNode;
        return true;
    }else {
        TableNode* currentNode = table[hashedKey];
        while(currentNode->next != nullptr){
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        return true;
    }
}
//Simple hash. Uses the names of the people.
int HashTable::hashKey1(string key){
    int preHash = 0;
    for (int i = 0; i < key.size(); i++) {
        preHash += key[i];
    }
    return preHash % 4177;
}
//Hash that uses both the names and the numbers
int HashTable::hashKey2(string key, string data){
    int preHash = 0;
    for (int i = 0; i < key.size(); i++) {
        preHash += key[i];
    }
    for (int i = 0; i < data.size(); i++){
        preHash += data[i];
    }
    return preHash % 4177;
}
//Hash that uses the numbers
int HashTable::hashKey3(string key, string data){
    string numbers = "";
    int preHash = 0;
    int tempNum = key[0];
    preHash = tempNum * 10000;
    for (int i = 10; i < data.size(); i++){
            numbers.push_back(data[i]);
    }
    preHash += stoi(numbers);
    while (preHash > 4177) {
        preHash = preHash / 2;
    }
    return preHash;
}

vector<int> HashTable::returnData(){
    int length = 0;
    vector<int> returnArray;
    returnArray.resize(46334);
    for (int i = 0; i < 4177; i++) {
        if (table[i] == nullptr){
            length = 0;
            returnArray[length] += 1;
        } else {
            length = findLength(*table[i]);
            returnArray[length] += 1;
        }
    }
    for (int j = 46334; j >= 0; j--){
        if (returnArray[j] != 0){
            returnArray.resize(j+1);
            return returnArray;
        }
    }
    return returnArray;
}

int HashTable::findLength(TableNode currentNode){
    if (currentNode.next == nullptr) {
        return 1;
    } else{
        return 1 + findLength(*currentNode.next);
    }
}