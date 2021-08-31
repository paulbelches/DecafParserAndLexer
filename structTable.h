#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
//#include "./symbolTable.h"

using namespace std;

class StructTable {
    map<string, SymbolTable> structTable;
    vector<string> idTable;

    public:
    void empty(){
        structTable.empty();
        idTable.empty();
    }

    void binding(string identifier, SymbolTable symbolTable){
        structTable[identifier] = symbolTable;
        idTable.push_back(identifier);
    }

    SymbolTable lookup(string identifier){
        return structTable[identifier];
    }
        
    bool hasElement(string identifier){
        vector<string>::iterator it;
        it = find(idTable.begin(), idTable.end(), identifier);
        return it != idTable.end();
    }

};
