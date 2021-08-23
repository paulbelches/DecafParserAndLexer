#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class SymbolTable {
    struct data {
        int id;
        int type; 
        /*
            1 ----- Varible
        */
        int dataType;
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

    void binding(string identifier, int type, int dataType, int size){
        data tempData;
        tempData.id = idTable.size();
        tempData.type = type;
        tempData.size = size;
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
};
