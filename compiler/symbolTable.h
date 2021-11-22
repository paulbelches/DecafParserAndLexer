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
    int base;
    int top;
    map<string, data> symbolTable;
    vector<string> idTable;

    public:
    void empty(){
        symbolTable.clear();
        idTable.clear();
    }

    void setBase(int initialBase){
        base = initialBase;
    }

    int getBase(){
        return base;
    }

    void setTop(int initialTop){
        top = initialTop;
    }

    int getTop(){
        return top;
    }

    void binding(string identifier, string dataType, int size){
        data tempData;
        tempData.id = idTable.size();
        tempData.size = size;
        tempData.dataType = dataType;
        tempData.offset = (tempData.id == 0) ? base : top ;
        top = tempData.offset + tempData.size;
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

    int getSize(){
        return idTable.size();
    }
};
