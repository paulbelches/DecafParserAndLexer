#include "./symbolTable.h"
#include <string>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class SymbolTableHandler {
    public:
    stack<SymbolTable> symbolTable;
    SymbolTable paramTable;

    void enter(){
        SymbolTable tempSymbolTable;
        symbolTable.push(tempSymbolTable);
        if (paramTable.getSize() != 0){
            initializeWithParamTable();
        }
    }

    void exit(){
        symbolTable.pop();
    }

    SymbolTable top(){
        return symbolTable.top();
    }

    void empty(){
        if (!symbolTable.empty()){
            symbolTable.top().empty();
        } else {
            cout << "Error, no symbol table to clean." << endl;
        }
    }

    void binding(string identifier, string dataType, int size){
        if (!symbolTable.empty()){
            symbolTable.top().binding(identifier, dataType, size);
        } else {
            cout << "Error, no symbol table to insert in." << endl;
        }
    }


    //Para llamadas y referencias, no declaraciones
    int elementExist(string identifier){
        int pos = -1;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        for (int i = 0; i < length; i++){
            //Check if the identifier exist
            if (symbolTable.top().hasElement(identifier)) {
                pos = i;
                break;
            }
            tempSymbolTable.push(symbolTable.top());
            symbolTable.pop();
        }
        length = tempSymbolTable.size();
        for (int i = 0; i < length; i++){
            symbolTable.push(tempSymbolTable.top());
            tempSymbolTable.pop();
        }
        return pos;
    }

    //Para llamadas y referencias, no declaraciones
    string getType(string identifier){
        string type = "null" ;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        for (int i = 0; i < length; i++){
            //Check if the identifier exist
            if (symbolTable.top().hasElement(identifier)) {
                type = symbolTable.top().lookup(identifier).dataType;
                break;
            }
            tempSymbolTable.push(symbolTable.top());
            symbolTable.pop();
        }
        length = tempSymbolTable.size();
        for (int i = 0; i < length; i++){
            symbolTable.push(tempSymbolTable.top());
            tempSymbolTable.pop();
        }
        return type;
    }

    //Empty
    void emptyParamTable() {
        paramTable.empty();
    }
    
    //Binding
    void bindingParamTable(string identifier, string dataType, int size){ 
        paramTable.binding(identifier, dataType, size);
    }

    // initialize the symbol table With the information of the ParamTable
    void initializeWithParamTable(){
        for (int i = 0; i < paramTable.getSize(); i++){
            string identifier = paramTable.getIdentifier(i);
            string dataType = paramTable.lookup(paramTable.getIdentifier(i)).dataType;
            int size = paramTable.lookup(paramTable.getIdentifier(i)).size;
            symbolTable.top().binding(identifier, dataType, size);
            //cout << identifier << endl;
        }
    }
};
