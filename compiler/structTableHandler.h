#include <string>
#include <iostream>
#include <map>
#include <stack>
#include "./structTable.h"
using namespace std;

class StructTableHandler {
    public:
    stack<StructTable> structTable;
    //public:
    void enter(){
        StructTable tempStructTable;
        structTable.push(tempStructTable);
    }

    void exit(){
        structTable.pop();
    }

    void empty(){
        if (!structTable.empty()){
            structTable.top().empty();
        } else {
            cout << "Error, no struct table to clean." << endl;
        }
    }

    void binding(string identifier, SymbolTable symbolTable){
        if (!structTable.empty()){
            structTable.top().binding(identifier, symbolTable);
        } else {
            cout << "Error, no struct table to insert in." << endl;
        }
    }

    int elementExist(string identifier){
        int pos = -1;
        int length = structTable.size();
        //cout << length << endl;
        stack<StructTable> tempStructTable;
        for (int i = 0; i < length; i++){
            if (structTable.top().hasElement(identifier)) {
                pos = i;
                break;
            }
            tempStructTable.push(structTable.top());
            structTable.pop();
        }
        length = tempStructTable.size();
        for (int i = 0; i < length; i++){
            structTable.push(tempStructTable.top());
            tempStructTable.pop();
        }
            
        return pos;
    }

    bool hasChild(string parentType, string identifier){
        bool anw = false;
        int length = structTable.size();
        //cout << length << endl;
        stack<StructTable> tempStructTable;
        for (int i = 0; i < length; i++){
            if (structTable.top().hasElement(parentType)) {
                if (structTable.top().lookup(parentType).hasElement(identifier)){
                    anw = true;
                }
                break;
            }
            tempStructTable.push(structTable.top());
            structTable.pop();
        }
        length = tempStructTable.size();
        for (int i = 0; i < length; i++){
            structTable.push(tempStructTable.top());
            tempStructTable.pop();
        }   
        return anw;
    }

    string getChildType(string parentType, string identifier){
        string s = "";
        int length = structTable.size();
        //cout << length << endl;
        stack<StructTable> tempStructTable;
        for (int i = 0; i < length; i++){
            if (structTable.top().hasElement(parentType)) {
                s = structTable.top().lookup(parentType).lookup(identifier).dataType;
                break;
            }
            tempStructTable.push(structTable.top());
            structTable.pop();
        }
        length = tempStructTable.size();
        for (int i = 0; i < length; i++){
            structTable.push(tempStructTable.top());
            tempStructTable.pop();
        }   
        return s;
    }

    int getOffset(string parentType, string identifier){
        int offset = -1;
        int length = structTable.size();
        //cout << length << endl;
        stack<StructTable> tempStructTable;
        for (int i = 0; i < length; i++){
            if (structTable.top().hasElement(parentType)) {
                offset = structTable.top().lookup(parentType).lookup(identifier).offset;
                break;
            }
            tempStructTable.push(structTable.top());
            structTable.pop();
        }
        length = tempStructTable.size();
        for (int i = 0; i < length; i++){
            structTable.push(tempStructTable.top());
            tempStructTable.pop();
        }   
        return offset;
    }



};
