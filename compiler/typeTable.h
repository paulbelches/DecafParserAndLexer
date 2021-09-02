#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class TypeTable {
    struct data {
        int id;
        //string type;
        int size; //amount of bits
    };

    public:
    map<string, data> typeTable;
    vector<string> idTable;

    //public:
    void empty(){
        typeTable.empty();
        idTable.empty();
    }

    void binding(string identifier, int size){
        data tempData;
        tempData.id = typeTable.size();
        tempData.size = size;
        typeTable[identifier] = tempData;
        idTable.push_back(identifier);
    }

    string getIdentifier(int id){
        return idTable[id];
    }

    data lookup(string identifier){
        return typeTable[identifier];
    }

    bool hasElement(string identifier){
        vector<string>::iterator it;
        it = find(idTable.begin(), idTable.end(), identifier);
        return it != idTable.end();
    }

    int getSize(string identifier){
        return typeTable[identifier].size;
    }

    int getId(string identifier){
        return typeTable[identifier].id;
    }
};
