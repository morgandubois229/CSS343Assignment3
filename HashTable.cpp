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

int HashTable::hashKey1(string key){
    return 0;
}

int HashTable::hashKey2(string key){
    return 0;
}

int HashTable::hashKey3(string key){
    return 0;
}

int** HashTable::returnData(){

}

bool HashTable::addHelper(int hashedKey, TableNode node){

}