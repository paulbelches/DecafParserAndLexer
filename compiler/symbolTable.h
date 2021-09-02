#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class SymbolTable {
    struct data {
        int id;
        string dataType;
        int size;
        int offset;
    };

    map<string, data> symbolTable;
    vector<string> idTable;
    public:
    void empty(){
        symbolTable.empty();
        idTable.empty();
    }

    void binding(string identifier, string dataType, int size){
        data tempData;
        tempData.id = idTable.size();
        tempData.size = size;
        tempData.dataType = dataType;
        tempData.offset = (tempData.id == 0) ? 0 : symbolTable[idTable[tempData.id - 1]].offset + symbolTable[idTable[tempData.id - 1]].size ;
        symbolTable[identifier] = tempData;
        idTable.push_back(identifier);
    }

    string getIdentifier(int id){
        return idTable[id];
    }

    data lookup(string identifier){
        return symbolTable[identifier];
    }

    bool hasElement(string identifier){
        vector<string>::iterator it;
        it = find(idTable.begin(), idTable.end(), identifier);
        return it != idTable.end();
    }

    string getType(int pos){
        return idTable[pos];
    }
};
