#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

class FunctionTable {
    struct data {
        int id;
        int returnType;
        vector<string> params;
    };
    map<string, data> functionTable;
    vector<string> idTable;
    public:
    void empty(){
        functionTable.empty();
        idTable.empty();
    }

    void binding(string identifier, int returnType, vector<string> params){
        data tempData;
        tempData.id = idTable.size();
        tempData.returnType = returnType;
        tempData.params = params;
        functionTable[identifier] = tempData;
        idTable.push_back(identifier);

    }

    string getIdentifier(int id){
        return idTable[id];
    }

    data lookup(string identifier){
        return functionTable[identifier];
    }

    bool hasElement(string identifier){
        vector<string>::iterator it;
        it = find(idTable.begin(), idTable.end(), identifier);
        return it != idTable.end();
    }

    int paramsAmount(string identifier){
        return functionTable[identifier].params.size();
    }

};
