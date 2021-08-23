#include "./typeTable.h"
#include <string>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class TypeTableHandler {
    public:
    stack<TypeTable> typeTable;
    //public:
    void enter(){
        TypeTable tempTypeTable;
        typeTable.push(tempTypeTable);
    }

    void exit(){
        typeTable.pop();
    }

    void empty(){
        if (!typeTable.empty()){
            typeTable.top().empty();
        } else {
            cout << "Error, no type table to clean." << endl;
        }
    }

    void binding(string identifier, int size){
        if (!typeTable.empty()){
            typeTable.top().binding(identifier, size);
        } else {
            cout << "Error, no type table to insert in." << endl;
        }
    }

    int elementExist(string identifier){
        int pos = -1;
        int length = typeTable.size();
        //cout << length << endl;
        stack<TypeTable> tempTypeTable;
        for (int i = 0; i < length; i++){
            if (typeTable.top().hasElement(identifier)) {
                pos = i;
                break;
            }
            tempTypeTable.push(typeTable.top());
            typeTable.pop();
        }
        length = tempTypeTable.size();
        for (int i = 0; i < length; i++){
            typeTable.push(tempTypeTable.top());
            tempTypeTable.pop();
        }
            
        return pos;
    }

    int getSize(string identifier){
        int size = -1;
        int length = typeTable.size();
        //cout << length << endl;
        stack<TypeTable> tempTypeTable;
        for (int i = 0; i < length; i++){
            if (typeTable.top().hasElement(identifier)) {
                size = typeTable.top().typeTable[identifier].size;
                break;
            }
            tempTypeTable.push(typeTable.top());
            typeTable.pop();
        }
        length = tempTypeTable.size();
        for (int i = 0; i < length; i++){
            typeTable.push(tempTypeTable.top());
            tempTypeTable.pop();
        }
            
        return size;
    }

    int getId(string identifier){
        int id = -1;
        int length = typeTable.size();
        //cout << length << endl;
        stack<TypeTable> tempTypeTable;
        for (int i = 0; i < length; i++){
            if (typeTable.top().hasElement(identifier)) {
                id = typeTable.top().typeTable[identifier].id;
                break;
            }
            tempTypeTable.push(typeTable.top());
            typeTable.pop();
        }
        length = tempTypeTable.size();
        for (int i = 0; i < length; i++){
            typeTable.push(tempTypeTable.top());
            tempTypeTable.pop();
        }
        return id;
    }

};
