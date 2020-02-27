#include <iostream>
#include <fstream>
#include <vector>
#include "HashTable.h"

vector<string> parseWords(string line);
void addToHashTable(string key, string data, HashTable& theTable);

vector<int> readWords(char **argv) {
    HashTable theTable;
    string line = "";
    vector<string> keyAndData;
    //ifstream myFile(argv[1]);
    ifstream myFile("phonebook.txt");
    if(myFile.is_open()) {
        while(getline(myFile, line)) {
            keyAndData = parseWords(line);
            addToHashTable(keyAndData[0], keyAndData[1], theTable);
            keyAndData.clear();
        }
    }
    return theTable.returnData();
}

vector<string> parseWords(string line) {
    string key = "";
    string data = "";
    int i = 0;
    for (i; i < line.size(); i++){
        if (line[i] == '\t'){
            i++;
            for (i; i < line.size(); i++){
                data.push_back(line[i]);
            }
        }else {
            key.push_back(line[i]);
        }
    }
    vector<string> returnVector;
    returnVector.push_back(key);
    returnVector.push_back(data);
    return returnVector;
}

void addToHashTable(string key, string data, HashTable& theTable) {
    int hashedKey = 0;
    //hashedKey = theTable.hashKey1(key); //change for each hash function.
    //hashedKey = theTable.hashKey2(key, data);
    hashedKey = theTable.hashKey3(key, data);
    theTable.add(hashedKey, key, data);
}

void printData(vector<int> data) {
    for(int i = 0; i < data.size(); i++) {
        if (!(data[i] == 0)) {
            cout << "Length " << i << " occurs " << data[i] << " times" << endl;
        }
    }
}

int main(int argc, char **argv) {
    vector<int> data = readWords(argv);
    printData(data);

    //char aChar = 'a';
    //int anInt = aChar;
    //cout << anInt << endl;

    return 0;
}
