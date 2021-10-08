#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Quads {
    struct Quad {
        string result;
        string op;
        string arg1;
        string arg2;     
    };

    map<string, int> currentState; //What is store in which variable
    vector<Quad> instructions; 
    public:
    void binding(string result, string op, string arg1, string arg2, string text){
        Quad tempQuad;
        tempQuad.result = result;
        tempQuad.op = op;
        tempQuad.arg1 = arg1;
        tempQuad.arg2 = arg2;
        instructions.push_back(tempQuad);
        if (text.length() > 0){
            currentState[text] = instructions.size(); //when making a access decreese the index by one
        }
    }

    int find(string text){
        return currentState[text];
    }

    string getId(int pos){
        return instructions[pos - 1].result;
    }

    string toString() {
        string result;
        for (int i = 0; i < instructions.size(); i++){
            result = result + instructions[i].op + " " +
            instructions[i].result + " " +
            instructions[i].arg1 + " " +
            instructions[i].arg2 + " \n" ;
        }
        return result;
    }


};
