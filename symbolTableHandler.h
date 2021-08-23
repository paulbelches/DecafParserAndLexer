#include "./symbolTable.h"
#include <string>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class SymbolTableHandler {
    public:
    stack<SymbolTable> symbolTable;

    void enter(){
        SymbolTable tempSymbolTable;
        symbolTable.push(tempSymbolTable);
    }

    void exit(){
        symbolTable.pop();
    }

    void empty(){
        if (!symbolTable.empty()){
            symbolTable.top().empty();
        } else {
            cout << "Error, no symbol table to clean." << endl;
        }
    }

    void binding(string identifier, int type, int dataType, int size){
        //cout << "Tama;o actual: " << symbolTable.size() << endl;
        if (!symbolTable.empty()){
            symbolTable.top().binding(identifier, type, dataType, size);
        } else {
            cout << "Error, no symbol table to insert in." << endl;
        }
    }

    int elementExist(string identifier){
        int pos = -1;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        for (int i = 0; i < length; i++){
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

};
