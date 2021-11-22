#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>
#include "./descriptor.h"

using namespace std;

class Quads {
    struct Quad {
        string result;
        string op;
        string arg1;
        string arg2;     
    };

    stack<map<string, int>> currentState; //What is store in which variable
    vector<Quad> instructions; 

    /////////////////////////Code a generation///////////////////////////

    map<string, int> functionSizes;
    Descriptor descriptor; 
    string currentFunction;
    map<string, map<string, int>> first; 
    map<string, map<string, int>> last; 


    public:

    void registerPosition(string id, int c){
        if (id[0] == 't'){
            if (first[currentFunction][id] == 0){
                first[currentFunction][id] = c;
            }
            last[currentFunction][id] = c;
            //cout << id << " " << c << endl; 
        } else if (id[0] == 'l'){
            if (first[currentFunction][id] == 0){
                first[currentFunction][id] = c;
            }
            last[currentFunction][id] = c;
        }
    }

    void setFunctionSizes(map<string, int> newFunctionSizes){
        functionSizes = newFunctionSizes;
    }

    void binding(string result, string op, string arg1, string arg2, string text){
        Quad tempQuad;
        tempQuad.result = result;
        tempQuad.op = op;
        tempQuad.arg1 = arg1;
        tempQuad.arg2 = arg2;
        instructions.push_back(tempQuad);
        if (text.length() > 0){
            currentState.top()[text] = instructions.size(); //when making a access decreese the index by one
        }
        if (op == "function") {
            currentFunction = result;
        }
        //First and last
        registerPosition(arg1 , instructions.size() - 1);
        registerPosition(arg2 , instructions.size() - 1);
        registerPosition(result , instructions.size() - 1);


    }

    void enter(){
        map<string, int> tempMap;
        currentState.push(tempMap);
    }

    void exit(){
        currentState.pop();
    }

    int find(string text){
        return currentState.top()[text];
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

    bool isNumber(const string& str)
    {
        for (char const &c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        return true;
    }

    string generateCode() {

        //param counter 
        int paramCounter = 0; 
        int returnCounter = 0; 

        //Initialice pointers
        cout << ".data" << endl;
        cout << "output: .asciiz \"cout: \""<< endl;
        cout << "input: .asciiz \"cin: \""<< endl;
        cout << "endl: .byte '\\n'" << endl;
        cout << ".text" << endl;
        cout << "add $fp $sp 0 "<< endl;
        cout << "j main" << endl;

        //Inicialice registrys
        descriptor.clear();

        string result;
        map<string, Quad> varAddress;
        stack<string> storeStrings;
        for (int i = 0; i < instructions.size(); i++){
                
            vector<string> registrysTofree ;
            string resultReg = ""; 
            string arg1Reg = ""; 
            string arg2Reg = "";


            ///Insert the storing params
            if (instructions[i].op != "pop" && !storeStrings.empty()){
                //paramCounter = 0; //clean the param pushes counter
                cout << "#Store the param values" << endl;
                while(!storeStrings.empty()){
                    cout << storeStrings.top() << endl; 
                    storeStrings.pop();
                }
                cout << "#-----------------------" << endl;
            }
            /////////////////////////////

            if (instructions[i].op == "mov"){

                if (isNumber(instructions[i].arg1)) {
                    resultReg = descriptor.getResultReg(instructions[i].result, "LD", "");
                    cout << "li "+resultReg+" "+instructions[i].arg1 << endl;
                } else {
                    arg1Reg = descriptor.getReg(instructions[i].arg1);
                    resultReg = descriptor.getResultReg(instructions[i].result, "EQ", arg1Reg);
                    cout << "move "+resultReg+" "+arg1Reg << " #Load"<< endl;
                }

                // Check if it needs to be store
                if (instructions[i].result[0] == 'l'){
                    //cout << instructions[i].result << endl; 
                    std::size_t start = instructions[i].result.find("[") + 1;
                    std::size_t end = instructions[i].result.find("]");
                    string temporal = instructions[i].result.substr(start, end - start);
                    string temporalRegistry = descriptor.getRegistry(temporal);

                    if (temporalRegistry == ""){
                        temporalRegistry = descriptor.getResultReg(varAddress[temporal].result, "LD", "");
                        //cout << temporalReg << "insertar la suma" << varAddress[temporal].result << endl;
                        cout << "li "+temporalRegistry+" "+varAddress[temporal].arg2 << endl;
                    }
                    //get temporal registry
                    cout << "#store the result"<< endl;
                    cout << "add $sp $fp " << temporalRegistry << endl;
                    cout << "sw "<< resultReg << " ($sp)" << endl;
                    cout << "#----------------" << endl;
                    registrysTofree.push_back(temporalRegistry);
                    registrysTofree.push_back(resultReg);
                }

            } else if (
                instructions[i].op == "add" ||
                instructions[i].op == "sub" ||
                instructions[i].op == "mul" || 
                instructions[i].op == "div" || 
                instructions[i].op == "rem" ){
                //resultReg
                resultReg = descriptor.getResultReg(instructions[i].result, "ADD", "");
                //arg1
                if (isNumber(instructions[i].arg1)) {
                    if (instructions[i].arg1 == "0"){
                        arg1Reg = "$zero";
                    } else {
                         //"Make temporal operation"
                        if (!descriptor.availableRegistrys.empty()){
                            arg1Reg = descriptor.getFreeRegistry();
                            registrysTofree.push_back(arg1Reg);
                            cout << "li "+arg1Reg+" "+instructions[i].arg1 << endl;
                        } else {
                            cout << "ERROR" << endl;
                        }
                    }
                } else {
                    arg1Reg = descriptor.getReg(instructions[i].arg1);
                    if (arg1Reg[1] == 't') {
                        registrysTofree.push_back(arg1Reg);
                    } 
                }
                //arg2
                if (isNumber(instructions[i].arg2)) {
                    cout << instructions[i].op+"i "+resultReg+" "+arg1Reg+" "+instructions[i].arg2 << endl;
                } else {
                    arg2Reg = descriptor.getReg(instructions[i].arg2);
                    cout << instructions[i].op+" "+resultReg+" "+arg1Reg+" "+arg2Reg << endl;
                    if (arg2Reg[1] == 't' && arg1Reg[1] != arg2Reg[1]) {
                        registrysTofree.push_back(arg2Reg);
                    }
                }
                // Check if it needs to be store
                if (instructions[i].result[0] == 'l'){
                    //cout << instructions[i].result << endl; 
                    std::size_t start = instructions[i].result.find("[") + 1;
                    std::size_t end = instructions[i].result.find("]");
                    string temporal = instructions[i].result.substr(start, end - start);

                    string temporalRegistry = descriptor.getRegistry(temporal);
                    
                    //get temporal registry
                    cout << "#store the result"<< endl;
                    cout << "add $sp $fp " << temporalRegistry << endl;
                    cout << "sw "<< resultReg << " ($sp)" << endl;
                    cout << "#----------------" << endl;
                    registrysTofree.push_back(temporalRegistry);
                    registrysTofree.push_back(resultReg);
                }
            } else if (instructions[i].op == "loadr"){
                resultReg = descriptor.getResultReg(instructions[i].result, "LD", "");
                cout << "move " << resultReg <<" $v0"<< endl;
            } else if (instructions[i].op == "goto"){
                cout << "jal " << instructions[i].result << endl;
                paramCounter = 0;
                descriptor.clear();
            } else if (instructions[i].op == "push"){
                cout << "#push a param"<< endl;
                //cout << "ANTES -> El valor del param counter es "<< paramCounter << endl;
                paramCounter++;
                //cout << "DESPÚES -> El valor del param counter es "<< paramCounter << endl;
                if (isNumber(instructions[i].result)) {
                    if (instructions[i].arg1 == "0"){
                        resultReg = "$zero";
                    } else {
                         //"Make temporal operation"
                        if (!descriptor.availableRegistrys.empty()){
                            resultReg = descriptor.getFreeRegistry();
                            registrysTofree.push_back(resultReg);
                            cout << "li "+resultReg+" "+instructions[i].result << endl;
                        } else {
                            cout << "ERROR" << endl;
                        }
                    }
                } else {
                    resultReg = descriptor.getReg(instructions[i].result);
                }
                //cout << "El valor del param counter es "<< paramCounter << endl;
                cout << "sub $sp $fp " << to_string(4 + (4*paramCounter)) << endl;
                cout << "sw " << resultReg << " ($sp)"  << endl;
                cout << "#----------------" << endl;
            } else if (instructions[i].op == "return" || instructions[i].op == "End" ){
                //arg1Reg = descriptor.getReg(instructions[i].arg1);
                if (instructions[i].op == "return"){
                    if (isNumber(instructions[i].arg1)) {
                        if (instructions[i].arg1 == "0"){
                            arg1Reg = "$zero";
                        } else {
                            //"Make temporal operation"
                            if (!descriptor.availableRegistrys.empty()){
                                arg1Reg = descriptor.getFreeRegistry();
                                registrysTofree.push_back(arg1Reg);
                                cout << "li "+arg1Reg+" "+instructions[i].arg1 << endl;
                            } else {
                                cout << "ERROR" << endl;
                            }
                        }
                    } else {
                        arg1Reg = descriptor.getReg(instructions[i].arg1);
                    }
                    cout << "move $v0 " << arg1Reg << endl;
                    returnCounter++;
                }
                if (instructions[i].result != "main") {
                    if (instructions[i].op == "End" && returnCounter > 0){
                        returnCounter = 0;
                    } else {
                        if (instructions[i].result == "cout") {
                            cout << "#-------------Print result --------------------" << endl;
                            cout << "la $a0, output" << endl;
                            cout << "li $v0, 4" << endl;
                            cout << "syscall" << endl;
                            cout << "lw $a0, 0($fp)" << endl;
                            cout << "li $v0, 1" << endl;
                            cout << "syscall" << endl;
                            cout << "la $a0, endl" << endl;
                            cout << "li $v0, 4" << endl;
                            cout << "syscall" << endl;
                            cout << "#----------------------------------------------" << endl;
                        }
                        cout << "add $fp $fp " << functionSizes[currentFunction] <<" #dealloc the function size "<< endl;
                        cout << "lw $ra ($fp) #load the returning address" << endl;
                        cout << "add $fp $fp 4 #return to the base of the base of the previus method" << endl;
                        cout << "jr $ra " << endl;
                    }
                } else {
                    cout << "#fin" << endl;
                }
                //Clear tables
                //Set Current function
            } else if (instructions[i].op == "pop"){
                cout << "#pop a param"<< endl;
                std::size_t start = instructions[i].arg1.find("[") + 1;
                std::size_t end = instructions[i].arg1.find("]");
                string offset = instructions[i].arg1.substr(start, end - start);
                resultReg = descriptor.getReg(instructions[i].result);
                //cout << "Result reg " << resultReg << endl;
                cout << "lw "<< resultReg << " " << to_string(-(4 + stoi(offset))) <<"($sp)" << endl;
                storeStrings.push("sw "+ resultReg + " " + to_string((stoi(offset))) + "($fp)");
                //cout << "sw "<< resultReg << " " << to_string((stoi(offset))) << "($fp)" << endl;
                //cout << offset << endl; //restar 4
                cout << "#----------------" << endl;
            } else if (instructions[i].op == "label"){
                cout << instructions[i].result << ":" << endl;
            } else if (instructions[i].op == "function"){
                descriptor.clear();
                cout << endl << instructions[i].result << ":" << endl;
                currentFunction = instructions[i].result;
                cout << "#store the return address"<< endl;
                cout << "sub $sp $fp 4" << endl;
                cout << "sw $ra ($sp)" << endl;
                cout << "#----------------" << endl;
                cout << "sub $fp $sp " << functionSizes[currentFunction] <<" #alloc the function size "<< endl;
                if (currentFunction == "cin"){
                    cout << "# Printing out the text" << endl;
                    cout << "li $v0, 4" << endl;
                    cout << "la $a0, input" << endl;
                    cout << "syscall" << endl;
                    cout << "# Getting user input" << endl;
                    cout << "li $v0, 5" << endl;
                    cout << "syscall" << endl;
                    cout << "add $fp $fp " << functionSizes[currentFunction] <<" #dealloc the function size "<< endl;
                    cout << "lw $ra ($fp) #load the returning address" << endl;
                    cout << "add $fp $fp 4 #return to the base of the base of the previus method" << endl;
                    cout << "jr $ra " << endl;
                    //cout << "# Moving the integer input to another register" << endl;
                    //cout << "move $t0, $v0" << endl;
                    //cout << "move $v0, $t0 " << endl;
                }
            }  else if (
                instructions[i].op == "eq" || 
                instructions[i].op == "ne" ||
                instructions[i].op == "lt" || 
                instructions[i].op == "gt" || 
                instructions[i].op == "le" || 
                instructions[i].op == "ge" ){

                //arg1
                if (isNumber(instructions[i].arg1)) {
                    if (instructions[i].arg1 == "0"){
                        arg1Reg = "$zero";
                    } else {
                         //"Make temporal operation"
                        if (!descriptor.availableRegistrys.empty()){
                            arg1Reg = descriptor.getFreeRegistry();
                            registrysTofree.push_back(arg1Reg);
                            cout << "li "+arg1Reg+" "+instructions[i].arg1 << endl;
                        } else {
                            cout << "ERROR" << endl;
                        }
                    }
                } else {
                    arg1Reg = descriptor.getReg(instructions[i].arg1);
                    if (arg1Reg[1] == 't') {
                        registrysTofree.push_back(arg1Reg);
                    } 
                }
                //arg2
                if (isNumber(instructions[i].arg2)) {
                    cout << "b"+instructions[i].op << " " << arg1Reg << " " << instructions[i].arg2 << " " << instructions[i].result << endl;
                    //cout << instructions[i].op+"i "+resultReg+" "+arg1Reg+" "+instructions[i].arg2 << endl;
                } else {
                    arg2Reg = descriptor.getReg(instructions[i].arg2);
                    cout << "b"+instructions[i].op << " " << arg1Reg << " " << arg2Reg << " " << instructions[i].result << endl;
                
                    if (arg2Reg[1] == 't' && arg1Reg[1] != arg2Reg[1]) {
                        registrysTofree.push_back(arg2Reg);
                    }
                }

                //cout << "b"+instructions[i].op << " " << arg1Reg << " " << arg2Reg << " " << instructions[i].result << endl;

            }

            //store variable address operations
            if (instructions[i].op == "add" && isNumber(instructions[i].arg2) && instructions[i].arg1 == "$zero"){
                //cout << "Guardar " << instructions[i].result << endl;
                varAddress[instructions[i].result] = instructions[i];
            }
            //Check for last appearence
            /*
            if (instructions[i].arg1[0] == 'l'){
                if (last[currentFunction][instructions[i].arg1] == i){
                    //cout << instructions[i].result << endl; 
                    std::size_t start = instructions[i].arg1.find("[") + 1;
                    std::size_t end = instructions[i].arg1.find("]");
                    string temporal = instructions[i].arg1.substr(start, end - start);
                    string temporalRegistry = descriptor.getRegistry(temporal);
                    registrysTofree.push_back(temporalRegistry);
                    registrysTofree.push_back(arg1Reg);
                    //cout << temporalRegistry << " " << arg1Reg << endl;
                }
            }

            if ( instructions[i].arg2[0] == 'l'){
                if (instructions[i].arg1[0]!=instructions[i].arg2[0] && last[currentFunction][instructions[i].arg2] == i){
                    //cout << instructions[i].result << endl; 
                    std::size_t start = instructions[i].arg2.find("[") + 1;
                    std::size_t end = instructions[i].arg2.find("]");
                    string temporal = instructions[i].arg2.substr(start, end - start);
                    string temporalRegistry = descriptor.getRegistry(temporal);
                    registrysTofree.push_back(temporalRegistry);
                    registrysTofree.push_back(arg2Reg);
                    //cout << temporalRegistry << " " << arg1Reg << endl;
                }
            }*/
            

            //Free temporal registrys
            if (registrysTofree.size() != 0){
                for (int i = 0; i < registrysTofree.size(); i++){
                    descriptor.freeRegistry(registrysTofree[i]);
                }
            }

            //Amount of free registrys
            //cout << "Tamaño " <<descriptor.availableRegistrys.size() << endl;
        
        }
        return result;
    }

};
