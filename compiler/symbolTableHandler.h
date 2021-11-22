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
    int maxTop;

    int getMaxTop(){
        return maxTop;
    }

    void startTop(){
        maxTop = 0;
    }
    
    int getGlobalSize(){        
        return symbolTable.top().getTop();
    }

    void enter(){
        SymbolTable tempSymbolTable;
        //Set Offset
        (symbolTable.size() <= 1) ? tempSymbolTable.setBase(0) : tempSymbolTable.setBase( symbolTable.top().getTop() );
        tempSymbolTable.setTop(tempSymbolTable.getBase());
        //Push table
        symbolTable.push(tempSymbolTable);
        //Fill with existing parameters
        if (paramTable.getSize() != 0){
            initializeWithParamTable();
        }
    }

    void exit(){
        if (maxTop < symbolTable.top().getTop()){
            maxTop = symbolTable.top().getTop();
            //cout << "si lo hice "<< maxTop << endl;
        }
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
        //cout << "scope " << symbolTable.size() << endl;
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
    int getOffset(string identifier){
        int offset = -1;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        for (int i = 0; i < length; i++){
            //Check if the identifier exist
            if (symbolTable.top().hasElement(identifier)) {
                //check if it is a param
                if (symbolTable.top().lookup(identifier).size > 0){
                    offset = symbolTable.top().lookup(identifier).offset;
                    break;
                }
            }
            tempSymbolTable.push(symbolTable.top());
            symbolTable.pop();
        }
        length = tempSymbolTable.size();
        for (int i = 0; i < length; i++){
            symbolTable.push(tempSymbolTable.top());
            tempSymbolTable.pop();
        }
        return offset;
    }

    //Para llamadas y referencias, no declaraciones
    int getSize(string identifier){
        //Clear the identifier
        //Check if it is a struct
        size_t p = 0;
        p = identifier.find(".");
        if (p > 0){
            identifier = identifier.substr(0, p);
        }
        //Check if it is a array
        p = 0;
        p = identifier.find("[");
        if (p > 0){
            identifier = identifier.substr(0, p);
        }
        //cout << "Result "<< identifier << endl;
        //
        int size = -1;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        for (int i = 0; i < length; i++){
            //Check if the identifier exist
            if (symbolTable.top().hasElement(identifier)) {
                //check if it is a param
                if (symbolTable.top().lookup(identifier).size > 0){
                    size = symbolTable.top().lookup(identifier).size;
                    break;
                }
            }
            tempSymbolTable.push(symbolTable.top());
            symbolTable.pop();
        }
        length = tempSymbolTable.size();
        for (int i = 0; i < length; i++){
            symbolTable.push(tempSymbolTable.top());
            tempSymbolTable.pop();
        }
        return size;
    }

    //Para llamadas y referencias, no declaraciones
    bool isGlobal(string identifier){
        //Clear the identifier
        //Check if it is a struct
        size_t p = 0;
        p = identifier.find(".");
        if (p > 0){
            identifier = identifier.substr(0, p);
        }
        //Check if it is a array
        p = 0;
        p = identifier.find("[");
        if (p > 0){
            identifier = identifier.substr(0, p);
        }
        //cout << "Result "<< identifier << endl;
        //
        bool isglobal = true;
        int length = symbolTable.size();
        stack<SymbolTable> tempSymbolTable;
        //cout << identifier << endl;
        for (int i = 0; i < length; i++){
            //cout << "I : " << i << " "  << endl;
            //Check if the identifier exist
            if (symbolTable.top().hasElement(identifier)) {
                //check if it is a param
                //cout << length << " "<< (i == length - 1) << endl;
                isglobal = i == length - 1;
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
        return isglobal;
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
        paramTable.binding(identifier, dataType, 0);
    }

    // initialize the symbol table With the information of the ParamTable
    void initializeWithParamTable(){
        for (int i = 0; i < paramTable.getSize(); i++){
            string identifier = paramTable.getIdentifier(i);
            string dataType = paramTable.lookup(paramTable.getIdentifier(i)).dataType;
            int size = paramTable.lookup(paramTable.getIdentifier(i)).size;
            symbolTable.top().binding(identifier, dataType, size);
            //cout << i << endl;
        }
    }
};
