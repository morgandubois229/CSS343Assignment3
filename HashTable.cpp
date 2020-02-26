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

}

bool HashTable::add(int hashedKey, string key, string data){

}

int HashTable::hashKey1(string key){

}

int HashTable::hashKey2(string key){

}

int HashTable::hashKey3(string key){

}

int** HashTable::returnData(){

}

bool HashTable::addHelper(int hashedKey, TableNode node){

}