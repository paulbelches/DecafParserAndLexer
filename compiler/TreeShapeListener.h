// antlr4 -Dlanguage=Cpp decaf.g4

//g++ -I /usr/local/include/antlr4-runtime -o main main.cpp decafLexer.cpp decafParser.cpp /usr/local/lib/libantlr4-runtime.a

#include "./symbolTableHandler.h"
#include "./typeTableHandler.h"
#include "./functionTable.h"
#include "./structTableHandler.h"
#include "./temporalsHandler.h"
#include "./quads.h"
#include <iostream>
#include <string>

#include "decafBaseListener.h"

using namespace antlr4;
using namespace std;

class TreeShapeListener : public decafBaseListener {

private:

  queue<string> readTokens;
  SymbolTableHandler symbolTable;
  TypeTableHandler typeTable;
  FunctionTable functionTable;
  StructTableHandler structTable;
  tree::ParseTreeProperty<string> nodeTypes; //put y get
  tree::ParseTreeProperty<string> nodeValues; //put y get

  TemporalsHandler labelsHandler;
  TemporalsHandler temporalsHandler;
  Quads quadsHandler; 
  /* Handle control instructions */
  stack<string> correctLabel;
  stack<string> wrongLabel;
  stack<string> beforeblock;
  stack<string> afterblock;
  tree::ParseTreeProperty<string> afterExpr; //put y get
  tree::ParseTreeProperty<int> offsets; //put y get
  tree::ParseTreeProperty<string> offsetOp; //put y get


public:

  virtual void enterProgram(decafParser::ProgramContext *ctx) override { 
    symbolTable.enter();
    typeTable.enter();
    structTable.enter();
    labelsHandler.reset();
    quadsHandler.enter();
    typeTable.binding("void", 0);
    typeTable.binding("int", 4);
    typeTable.binding("char", 2);
    typeTable.binding("boolean", 1);
    typeTable.binding("int[]", 4);
    typeTable.binding("char[]", 2);
    typeTable.binding("boolean[]", 1);
  }

  virtual void exitProgram(decafParser::ProgramContext *ctx) override {
    //The program contains a main definition without params
    if (!functionTable.hasElement("main")) {
      cout << "line "<< ctx->start->getLine() <<", no main method declared. \n";
      nodeTypes.put(ctx, "error");
    } else if (functionTable.paramsAmount("main") > 0) {
      cout << "line "<< ctx->start->getLine() <<", main has unnecesary arguments. \n";
      nodeTypes.put(ctx, "error");
    } 

    cout << quadsHandler.toString();
  }
  //Check for errors
  virtual void exitVariableDeclaration(decafParser::VariableDeclarationContext *ctx) override {    
    string identifier = ctx->ID()->getText();
    string type;
    if (ctx->varType()->structDeclaration() != 0){
      //cout << ctx->varType()->structDeclaration()->ID()->getText() << endl;
      type = "struct"+ctx->varType()->structDeclaration()->ID()->getText();
    } else {
      type =  ctx->varType()->getText();
      //////////
      //cout << "inicializar "<< identifier << endl;
      //////////
    }
    
    if (typeTable.elementExist(type) < 0){
      cout << "line "<< ctx->start->getLine() <<", type " + type + " of variable " + identifier +" does not exist. \n";
      nodeTypes.put(ctx, "error");
    } else if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared. \n";
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void enterStructDeclaration(decafParser::StructDeclarationContext *ctx) override {
    symbolTable.enter();
  }

  virtual void exitStructDeclaration(decafParser::StructDeclarationContext *ctx) override {
    string identifier = ctx->ID()->getText();
    //Check that struct is not already declared
    //Check that var declarations where not error
    if (!symbolTable.top().hasElement(identifier)) {
      SymbolTable tempSymbolTable = symbolTable.top();
      structTable.binding("struct"+identifier, tempSymbolTable); 
      symbolTable.exit();
      //cout << "Struct size "<< identifier<< " " << tempSymbolTable.getBase() << " " << tempSymbolTable.getTop() << endl;
      int structSize = tempSymbolTable.getTop() - tempSymbolTable.getBase();
      typeTable.binding("struct"+identifier, structSize); 
      typeTable.binding("struct"+identifier+"[]", structSize); 
      return;
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared. \n";
      nodeTypes.put(ctx, "error");
    }
    symbolTable.exit();
    
  }

  virtual void exitArrayDeclaration(decafParser::ArrayDeclarationContext *ctx) override { 
    string type;
    string identifier = ctx->ID()->getText();
    string num = ctx->NUM()->getText();

    if (ctx->varType()->structDeclaration() != 0){
      //cout << ctx->varType()->structDeclaration()->ID()->getText() + "[]" << endl;
      type = "struct"+ctx->varType()->structDeclaration()->ID()->getText() + "[]";
    } else {
      type =  ctx->varType()->getText() + "[]";
    }

    //cout << "CONTROL" << typeTable.elementExist(type) << endl;
    if (typeTable.elementExist(type) < 0){
      cout << "line "<< ctx->start->getLine() <<", type " + type + " of variable " + identifier +" does not exist. \n" ;
      nodeTypes.put(ctx, "error");
    } else if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, atoi(num.c_str()) * size );
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared. \n" ;
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void enterMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    typeTable.enter();
    structTable.enter();
    symbolTable.enter();
    quadsHandler.enter();
    temporalsHandler.reset();
    string type =  ctx->methodType()->getText();
    string identifier = ctx->ID()->getText();
    if (!functionTable.hasElement(identifier)){
      //////////
      //cout << "Function "+identifier+" :"<< endl;
      quadsHandler.binding(
        identifier, 
        "function", 
        "",
        "",
        ""
      );
      //////////
      int parameterCounter = ctx->parameter().size() -1;
      vector<string> params;
      while (parameterCounter >= 0){
        //////////
        /* Get temporal */
        int resultTemp = temporalsHandler.getVariable();
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "pop", 
          ctx->parameter(parameterCounter)->children[1]->getText(),
          "",
          ctx->parameter(parameterCounter)->children[1]->getText()
        );
        //cout << "t"+to_string(resultTemp)+" load "+ctx->parameter(parameterCounter)->children[1]->getText()<< endl;
        //////////
        nodeValues.put(ctx->parameter(parameterCounter), identifier);
        parameterCounter--;
      }
      functionTable.binding(identifier, type, params);
      nodeTypes.put(ctx, type);
      
    } else {
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " already declared. \n";
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void exitMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    symbolTable.exit();
    symbolTable.emptyParamTable();
    typeTable.exit();
    structTable.exit();
    quadsHandler.exit();
    string identifier = ctx->ID()->getText();
    string blockType = nodeTypes.get(ctx->block());
    //string blockReturnType = nodeValues.get(ctx->block());
    string methodType = nodeTypes.get(ctx);

    if (blockType == "error"){
      nodeTypes.put(ctx, "error");
      //cout << "Error in method declaration" << endl;
    } else if (methodType != blockType){
      //cout << methodType << endl;
      //cout << blockReturnType << endl;
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " expected return " + methodType + " but " + blockType + " returned \n";
      nodeTypes.put(ctx, "error");
    } else {
      //////////
      quadsHandler.binding(
        identifier, 
        "End", 
        "",
        "",
        ""
      );
      //cout << "End"+identifier<< endl;
      //////////
    }
  }

  virtual void exitParameterVariable(decafParser::ParameterVariableContext *ctx) override {
    //cout << ctx << " parameter variable" << endl;
    string type =  ctx->parameterType()->getText();
    string identifier = ctx->ID()->getText();
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
      symbolTable.bindingParamTable(identifier, type, size);
      nodeTypes.put(ctx, type);
      /////////////MOdify
      functionTable.pushParam(nodeValues.get(ctx), type);
      /////////////
    } else {
      cout << "line "<< ctx->start->getLine() <<" " + identifier + " already declared. \n";
      nodeTypes.put(ctx, "error");
    }
  }
  
  virtual void exitParameterArray(decafParser::ParameterArrayContext *ctx) override {
    string type =  ctx->parameterType()->getText() + "[]";
    string identifier = ctx->ID()->getText();
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
      symbolTable.bindingParamTable(identifier, type, size);
      nodeTypes.put(ctx, type);
      /////////////MOdify
      functionTable.pushParam(nodeValues.get(ctx), type);
      /////////////
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared. \n";
      nodeTypes.put(ctx, "error");
    }
  }
  virtual void enterBlock(decafParser::BlockContext *ctx) override {
    if (!beforeblock.empty()){
      //cout << beforeblock.top() << ":" << endl;
      quadsHandler.binding(
        beforeblock.top(),  
        "label", 
        "",
        "",
        ""
      );
      beforeblock.pop();
    }
  }

  virtual void exitBlock(decafParser::BlockContext *ctx) override {
    if (!afterblock.empty()){
      size_t start = afterblock.top().find(" ");
      size_t finish = afterblock.top().find(" ", start+1, 1);
      //cout << afterblock.top() << endl;
      if (afterblock.top().substr(0, start) == "else"){
        //cout << "goto" << afterblock.top().substr(start, finish-start) << endl;
        quadsHandler.binding(
          afterblock.top().substr(start+1, finish-start),  
          "goto", 
          "",
          "",
          ""
        );
        start = finish;
        finish = afterblock.top().find(" ", start+1, 1);
      } 
      //cout << afterblock.top().substr(start, finish-start)<< ":" << endl;
      quadsHandler.binding(
        afterblock.top().substr(start+1, finish-start),  
        "label", 
        "",
        "",
        ""
      );
      afterblock.pop();
    }
    string type = "void";
    for (int i = 0; i < ctx->varDeclaration().size(); i++){
      if (nodeTypes.get(ctx->varDeclaration(i)) == "error"){
        nodeTypes.put(ctx, "error");
        return;
      }
    }
    for (int i = 0; i < ctx->statement().size(); i++){
      string type = nodeTypes.get(ctx->statement(i));
      if (type == "error"){
        nodeTypes.put(ctx, "error");
        return;
      } else if (type != "void"){
        if (nodeValues.get(ctx).size() == 0){
          //nodeValues.put(ctx, "error");
          nodeTypes.put(ctx, type);
          //cout << "Block " << ctx << " " << nodeValues.get(ctx) << " " << ctx->getText() << endl;
          return; 
        } else {
          if (nodeValues.get(ctx) != type){
            cout << "line "<< ctx->start->getLine() <<", multiple types return in method \n";
            nodeTypes.put(ctx, "error");
            return;
          }
        }
      }
    }
    nodeTypes.put( ctx, "void" );
  }

  virtual void enterIfStatement(decafParser::IfStatementContext *ctx) override { 
    symbolTable.enter();
    typeTable.enter();
    structTable.enter();
    //// Control /////
    string label = "L"+to_string(labelsHandler.getVariable());
    correctLabel.push(label);
    beforeblock.push(label);
    label = "L"+to_string(labelsHandler.getVariable());
    wrongLabel.push(label);
    afterblock.push("norm "+label);
    label = "L"+to_string(labelsHandler.getVariable());
    if (ctx->block()[1] != 0){
      string tempString = "else "+label+" "+afterblock.top().substr(5, afterblock.top().size())+" ";
      afterblock.top() = "norm "+label;
      afterblock.push(tempString);
    }
    /*
    if (ctx->block()[1] != 0){
      string temp = "goto "+ label+ "\n" + afterblock.top();
      afterblock.top() = label+":";
      afterblock.push(temp);
    }
    */
    //////////////
  }

  virtual void exitIfStatement(decafParser::IfStatementContext *ctx) override { 
    string expressionType = nodeTypes.get(ctx->expression());
    string blockType = nodeTypes.get(ctx->block()[0]);
    string block2Type = nodeTypes.get(ctx->block()[1]);
    if ((blockType == "error") || (block2Type == "error") || (expressionType == "error")){
      nodeTypes.put(ctx, "error");
    } else if (expressionType == "boolean"){
      //There is no else statement , so it is not known if the result is going to be return
      if (ctx->block()[1] == 0){
        nodeTypes.put(ctx, blockType);
      } else {
        if (blockType == block2Type) {
          nodeTypes.put(ctx, block2Type);
        } else {
          nodeTypes.put(ctx, "error");
          cout << "line "<< ctx->start->getLine() <<", if statement returns two diferent types \n";
        }
      }
    } else {
      nodeTypes.put(ctx, "error");
      cout << "line "<< ctx->start->getLine() <<", if statement with no boolean conditional \n";
    }
    correctLabel.pop();
    wrongLabel.pop();
    symbolTable.exit();
    typeTable.exit();
    structTable.exit();
  }

  virtual void enterWhileStatement(decafParser::WhileStatementContext *ctx) override {
    symbolTable.enter();
    typeTable.enter();
    structTable.enter();

    string initialLabel = "L"+to_string(labelsHandler.getVariable());
    quadsHandler.binding(
      initialLabel,  
      "label", 
      "",
      "",
      ""
    );
    string label = "L"+to_string(labelsHandler.getVariable());
    correctLabel.push(label);
    beforeblock.push(label);
    label = "L"+to_string(labelsHandler.getVariable());
    wrongLabel.push(label);
    afterblock.push("norm "+label);
    afterblock.top() = "else "+initialLabel+" "+afterblock.top().substr(5, afterblock.top().size() - 5)+" ";
  }

  virtual void exitWhileStatement(decafParser::WhileStatementContext *ctx) override {
    string expressionType = nodeTypes.get(ctx->expression());
    string blockType = nodeTypes.get(ctx->block());

    if ((blockType == "error") || (expressionType == "error")){
      nodeTypes.put(ctx, "error");
    } else if (expressionType == "boolean"){
      nodeTypes.put(ctx, nodeTypes.get(ctx->block()));
    } else {
      nodeTypes.put(ctx , "error");
      cout << "line "<< ctx->start->getLine() <<", while statement with no boolean conditional \n";
    }
    correctLabel.pop();
    wrongLabel.pop();
    symbolTable.exit();
    typeTable.exit();
    structTable.exit();
  }

  virtual void exitReturnStatement(decafParser::ReturnStatementContext *ctx) override {
    if (ctx->expression() == 0){
      nodeTypes.put(ctx, "void");
      //nodeValues.put( ctx, "return" );
    } else if (nodeTypes.get(ctx->expression()) == "error"){
      nodeTypes.put( ctx , "error");
    } else {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      //////////
      /* search for expression */
      string arg1;
      int temp1Value =  quadsHandler.find(ctx->expression()->getText());
      /**/
      if (temp1Value == 0){
        if (offsetOp.get(ctx->expression()).size() != 0){
          string loc = (symbolTable.isGlobal(ctx->expression()->getText())) ? "g[" : "l[";
          int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()));
          arg1 = loc+quadsHandler.getId(tempValue)+"]";
        } else {
          arg1 = ctx->expression()->getText();
        }
      } else {
        arg1 = quadsHandler.getId(temp1Value);
      }
      quadsHandler.binding(
        "rr", 
        "mov", 
        arg1,
        "",
        ""
      );
      //cout << "rr load "+arg1<< endl;
        //////////
      //nodeValues.put( ctx, "return" );
    }
  }

  virtual void exitAsignationStatement(decafParser::AsignationStatementContext *ctx) override { 
    string expressionType = nodeTypes.get(ctx->expression());
    string locationType = nodeTypes.get(ctx->location());
    if ((locationType == "error") || (expressionType == "error")){
      nodeTypes.put(ctx, "error");
    } else if (expressionType == locationType){
      nodeTypes.put( ctx, "void" );
      //////////
      /*Check if the expression is in the symbol table*/
      string arg1;
      string arg2;
      int temp1Value =  quadsHandler.find(ctx->expression()->getText());  
      int temp2Value =  quadsHandler.find(ctx->location()->getText()); 
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /**/
        if (temp2Value == 0){
          if (offsetOp.get(ctx->location()).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->location()->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->location()));
            arg2 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg2 = ctx->location()->getText();
          }
        } else {
          arg2 = quadsHandler.getId(temp2Value);
        } 
      ////
      quadsHandler.binding(
        arg2,
        "mov", 
        arg1,
        "",
        ""
      );
      //cout << "Asign "+ctx->location()->getText()+" "+ctx->expression()->getText()<< endl;
      //////////
    } else {
      cout << "line "<< ctx->start->getLine() <<", cannot asign " << expressionType << " to " << locationType << "\n";
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void exitExpresionStatement(decafParser::ExpresionStatementContext *ctx) override {
    nodeTypes.put( ctx, "void" );
  }

  //////////////////////////////////////Expressions
  virtual void exitMethodCall(decafParser::MethodCallContext *ctx) override {
    string identifier = ctx->ID()->getText();
    //Check if identifier exist
    if (functionTable.hasElement(identifier)){
      //Extract arguments
      int argCount = 0;
      vector<string> args;
      while (ctx->arg(argCount) != 0){
        //////////
        /*Check if the expression is in the symbol table*/
        int temp1Value =  quadsHandler.find(ctx->arg(argCount)->getText());
        string arg1;
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->arg(argCount)->expression()).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->arg(argCount)->expression()->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->arg(argCount)->expression()));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->arg(argCount)->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /*Get the temporal where the result is going to be store*/
        //int resultTemp = temporalsHandler.getVariable(); //Check if it is necesary
        /*Insert The Quad*/
        quadsHandler.binding(
          arg1, 
          "push", 
          "",
          "",
          ""
        );
        ////////// 
        args.push_back(nodeTypes.get(ctx->arg(argCount)));
        argCount++;
      }
      //cout << argCount << endl;
      vector<string> methodParams = functionTable.getParams(identifier);
      //Compare firms
      if (equal(args.begin(), args.end(), methodParams.begin(), methodParams.end())){
        //cout << identifier << " is of type " << functionTable.getType(identifier) << endl;
        nodeTypes.put(ctx, functionTable.getType(identifier));
        //////////
        /*Get the temporal where the result is going to be store*/
        int resultTemp = temporalsHandler.getVariable();
        //Call Function
        quadsHandler.binding(
          identifier,  
          "goto", 
          "",
          "",
          ""
        );
        //Read return value
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "mov", 
          "rr", 
          "",
          ctx->getText()
        );
        //////////
      } else {
        //Print error message
        cout << "line "<< ctx->start->getLine() <<", expected paramters ( ";
        for (int i = 0; i < methodParams.size(); i++){
          cout << methodParams[i]  << " ";
        }
        cout << ") but received ( ";
        for (int i = 0; i < args.size(); i++){
          cout << args[i] << " ";
        }
        cout << ")  \n";
        //set error type
        nodeTypes.put(ctx, "error");
      }
    } else {
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " not declared. \n";
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void enterVarIdLocation(decafParser::VarIdLocationContext *ctx) override {
    if (ctx->location() != 0){
      nodeValues.put(ctx->location(), "son");
    }
    //Check if it is a son node
    if (nodeValues.get(ctx) == "son" ){
      string parentType = nodeTypes.get( ctx->parent);
      string identifier = ctx->ID()->getText();
      //Check if parent is error 
      if (parentType == "error"){
        nodeTypes.put( ctx , "error");
        return;
      }
      //Check that parent is a struct
      if (structTable.elementExist(parentType)> -1){
        //Check atribute exist
        if (structTable.hasChild(parentType,identifier)){
          //Get the atributes type
          string type = structTable.getChildType(parentType,identifier);
          nodeTypes.put(ctx, type);
        } else {
          cout << "line "<< ctx->start->getLine() <<", type " + parentType + " has no atribute "+ identifier + ". \n";
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", type " + parentType + " is not a struct. \n";
        nodeTypes.put(ctx, "error");
        return;
      }
    //Check if it is a parent node
    } else {
      string identifier = ctx->ID()->getText();
      //Check it exist on the symbol table
      if (symbolTable.elementExist(identifier) != -1){
        string type = symbolTable.getType(identifier);
        nodeTypes.put( ctx, type );
      } else {
        cout << "line "<< ctx->start->getLine() <<", variable " + identifier + " does not exist. \n";
        nodeTypes.put(ctx, "error");
      }
    }
  }
  
  virtual void exitVarIdLocation(decafParser::VarIdLocationContext *ctx) override {
    string identifier = ctx->ID()->getText();
    if (nodeValues.get(ctx) == "son" ){
      //cout << identifier << " relative offset " << endl;
      /* get my offset */
      string fatherType = nodeTypes.get(ctx->parent);
      int offset = structTable.getOffset(fatherType, identifier);
      //cout << identifier << " My offset es " << offset << endl;
      //Get the address from identifier
      string op = "$zero + "+to_string(offset);
      if (quadsHandler.find(op) == 0) {
        int resultTemp = temporalsHandler.getVariable();
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "add", 
          "$zero",
          to_string(offset),
          op
        );
      } 
      offsetOp.put(ctx, op); //Use to check if the offset is a result
      //////////////////
      string type = nodeTypes.get(ctx);
      nodeTypes.put(ctx->parent, type);
    } else {
      //cout << identifier << " absolute offset " << endl;
      if (symbolTable.elementExist(identifier) != -1){
        //Get type from symbol table
        /* refactoring */
        int offset = symbolTable.getOffset(identifier);
        //cout << identifier << " My offset padre es " << offset << endl;
        string op = "$zero + "+to_string(offset);
        if (quadsHandler.find(op) == 0) {
          int resultTemp = temporalsHandler.getVariable();
          quadsHandler.binding(
            "t"+to_string(resultTemp), 
            "add", 
            "$zero",
            to_string(offset),
            op
          );
        }
        offsetOp.put(ctx, op); //Use to check if the offset is a result
        offsetOp.put(ctx->parent, op); // tranfer the value to the father expression
      }
    }

    /* check if it has a child */
    if (ctx->location() != 0){
      int temp1Value = quadsHandler.find( offsetOp.get(ctx) );
      int temp2Value = quadsHandler.find( offsetOp.get(ctx->location()) );
      //add validations?
      string arg1 = quadsHandler.getId(temp1Value);
      string arg2 = quadsHandler.getId(temp2Value);
      string op = arg1+" + "+arg2;
      if (quadsHandler.find(op) == 0) {
        int resultTemp = temporalsHandler.getVariable();
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "add", 
          arg1,
          arg2,
          op
        );
      }
      offsetOp.put(ctx, op);
      if (nodeValues.get(ctx) != "son" ){
        offsetOp.put(ctx->parent, op);
      }
    }
  }

  virtual void enterArrayLocation(decafParser::ArrayLocationContext *ctx) override {
    if (ctx->location() != 0){
      nodeValues.put(ctx->location(), "son");
    }
    //Check if it is a son node
    if (nodeValues.get(ctx) == "son" ){
      string parentType = nodeTypes.get( ctx->parent);
      string identifier = ctx->ID()->getText();
      //Check if parent is error 
      if (parentType == "error"){
        nodeTypes.put( ctx , "error");
        return;
      }
      //Check that parent is a struct
      if (structTable.elementExist(parentType) > -1){
        //Check atribute exist
        if (structTable.hasChild(parentType,identifier)){
          //Get the atributes type
          string type = structTable.getChildType(parentType,identifier);
          // Check if it is a array
          if (type[type.size()-1] == ']' && type[type.size()-2] == '[') {
            type = type.substr(0, type.size()-2);
            nodeTypes.put( ctx, type );
          } else {
            cout << "line "<< ctx->start->getLine() <<", " + identifier + " is not and array. \n" ;
            nodeTypes.put(ctx, "error");
            return;
          }
        } else {
          cout << "line "<< ctx->start->getLine() <<", type " + parentType + " has no atribute "+ identifier + ". \n" ;
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", type " + parentType + "  is not a struct. \n" ;
        nodeTypes.put(ctx, "error");
        return;
      }
    //Check if it is a parent node
    } else {
      string identifier = ctx->ID()->getText();
      //Check it exist on the symbol table
      if (symbolTable.elementExist(identifier) != -1){
        //Get type from symbol table
        string type = symbolTable.getType(identifier);
        // Check if it is a array
        if (type[type.size()-1] == ']' && type[type.size()-2] == '[') {
          type = type.substr(0, type.size()-2);
          nodeTypes.put( ctx, type );
        } else {
          cout << "line "<< ctx->start->getLine() <<", " + identifier + " is not and array. \n" ;
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", variable " + identifier + " does not exist. \n" ;
        nodeTypes.put(ctx, "error");
      }
    }
  }

  virtual void exitArrayLocation(decafParser::ArrayLocationContext *ctx) override {
    //Check if the index is a int and if it is negativ 
    if (nodeTypes.get(ctx->expression()) == "int"){
      try { 
        int value = stoi(ctx->expression()->getText());
        if (value < 0){
          cout << "line "<< ctx->start->getLine() <<", negativ index. \n" ;
          nodeTypes.put(ctx, "error");
        }
        //validate size of array
      } catch(exception) {
        ;
      }
    } else {
      cout << "line "<< ctx->start->getLine() <<", index of type "+ nodeTypes.get(ctx->expression()) + ".\n";
      nodeTypes.put(ctx, "error");
    }
    /// rel offset
    string identifier = ctx->ID()->getText();
    string type = nodeTypes.get(ctx);
    if (nodeValues.get(ctx) == "son" ){
      //cout << identifier << " relative offset " << endl;
      /* get my offset */
      string fatherType = nodeTypes.get(ctx->parent);
      int offset = structTable.getOffset(fatherType, identifier);
      //cout << identifier << " My offset es " << offset << endl;
      //Get the address from identifier
      string op = "$zero + "+to_string(offset);
      if (quadsHandler.find(op) == 0) {
        int resultTemp = temporalsHandler.getVariable();
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "add", 
          "$zero",
          to_string(offset),
          op
        );
      } 
      offsetOp.put(ctx, op); //Use to check if the offset is a result
      //////////////////
      nodeTypes.put(ctx->parent, type);
    } else {
      //cout << identifier << " absolute offset " << endl;
      if (symbolTable.elementExist(identifier) != -1){
        //Get type from symbol table
        /* refactoring */
        int offset = symbolTable.getOffset(identifier);
        //cout << identifier << " My offset padre es " << offset << endl;
        string op = "$zero + "+to_string(offset);
        if (quadsHandler.find(op) == 0) {
          int resultTemp = temporalsHandler.getVariable();
          quadsHandler.binding(
            "t"+to_string(resultTemp), 
            "add", 
            "$zero",
            to_string(offset),
            op
          );
        }
        offsetOp.put(ctx, op); //Use to check if the offset is a result
        offsetOp.put(ctx->parent, op); // tranfer the value to the father expression
      }
    }
   
    //cout << identifier << " array offset " << endl;
    //local offset    
    //Get the expression
    string arg1;
    int temp1Value =  quadsHandler.find(ctx->expression()->getText()); 
    if (temp1Value == 0){
      if (offsetOp.get(ctx->expression()).size() != 0){
        string loc = (symbolTable.isGlobal(ctx->expression()->getText())) ? "g[" : "l[";
        int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()));
        arg1 = loc+quadsHandler.getId(tempValue)+"]";
      } else {
        arg1 = ctx->expression()->getText();
      }
    } else {
      arg1 = quadsHandler.getId(temp1Value);
    }
    int size = typeTable.getSize(type);
    int identifierSize = symbolTable.getSize(identifier);
    /*Dinamic verficiaction*/
    int resultTemp = temporalsHandler.getVariable();
    int resultTemp2 = temporalsHandler.getVariable();
    quadsHandler.binding(
      "L"+to_string(resultTemp), 
      "gt", 
      arg1,
      to_string(identifierSize / size) ,
      ""
    );
    quadsHandler.binding(
      "L"+to_string(resultTemp2),
      "goto", 
      "",
      "",
      ""
    );
    quadsHandler.binding(
      "t"+to_string(resultTemp),   
      "label", 
      "",
      "",
      ""
    );
    quadsHandler.binding(
      "",   
      "Panic", 
      "",
      "",
      ""
    );
    quadsHandler.binding(
      "t"+to_string(resultTemp2),   
      "label", 
      "",
      "",
      ""
    );
    /**/

    string arg2;
    //Multiply by the size
    string op2 = arg1 + " * "+ to_string(size);
    if (true) { //Remove
      int resultTemp = temporalsHandler.getVariable();
      quadsHandler.binding(
        "t"+to_string(resultTemp), 
        "mul", 
        arg1,
        to_string(size),
        op2
      );
      arg2 = "t"+to_string(resultTemp);
    } else {
      arg2 = quadsHandler.getId( quadsHandler.find(op2) );
    }
    //add the offsets
    temp1Value = quadsHandler.find( offsetOp.get(ctx) );
    arg1 = quadsHandler.getId(temp1Value);
    string op3 = arg1 + " + "+ arg2;
    if (true) { //Remove
      int resultTemp = temporalsHandler.getVariable();
      quadsHandler.binding(
        "t"+to_string(resultTemp), 
        "add", 
        arg1,
        arg2,
        op3
      );
    }
    offsetOp.put(ctx, op3);
    if (nodeValues.get(ctx) != "son" ){
      offsetOp.put(ctx->parent, op3);
    }
    
    /* check if it has a child */
    if (ctx->location() != 0){
      int temp1Value = quadsHandler.find( offsetOp.get(ctx) );
      int temp2Value = quadsHandler.find( offsetOp.get(ctx->location()) );
      //add validations?
      string arg1 = quadsHandler.getId(temp1Value);
      string arg2 = quadsHandler.getId(temp2Value);
      string op = arg1+" + "+arg2;
      if (quadsHandler.find(op) == 0) {
        int resultTemp = temporalsHandler.getVariable();
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "add", 
          arg1,
          arg2,
          op
        );
      }
      offsetOp.put(ctx, op);
      if (nodeValues.get(ctx) != "son" ){
        offsetOp.put(ctx->parent, op);
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////  
  virtual void exitExpressionPairArith(decafParser::ExpressionPairArithContext *ctx) override { 
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    } else {
      if (((exp1Type == exp2Type)  && (exp1Type == "int"))){
        nodeTypes.put(ctx, "int");
        //////////
        /*Check if the expression is in the symbol table*/
        string arg1;
        string arg2;
        int temp1Value =  quadsHandler.find(ctx->expression()[0]->getText());
        int temp2Value =  quadsHandler.find(ctx->expression()[1]->getText());
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()[1]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[0]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[0]));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()[0]->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /**/
        if (temp2Value == 0){
          if (offsetOp.get(ctx->expression()[1]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[1]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[1]));
            arg2 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg2 = ctx->expression()[1]->getText();
          }
        } else {
          arg2 = quadsHandler.getId(temp2Value);
        }
        /*Get the temporal where the result is going to be store*/
        int resultTemp = temporalsHandler.getVariable();
        string func; 
        if (ctx->children[1]->getText() == "*"){
           func = "mul";
        } else if (ctx->children[1]->getText() == "/"){
          func = "div";
        } else {
          func = "rem";
        }
        /*Insert The Quad*/
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          func, 
          arg1,
          arg2,
          ctx->getText()
        );
        //////////
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type  + ".\n";
        return;
      }
    }
  }

  virtual void exitExpressionPairArithSimple(decafParser::ExpressionPairArithSimpleContext *ctx) override { 
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    } else {
      if (((exp1Type == exp2Type)  && (exp1Type == "int"))){
        nodeTypes.put(ctx, "int");
        //////////
        /*Check if the expression is in the symbol table*/
        string arg1;
        string arg2;
        int temp1Value =  quadsHandler.find(ctx->expression()[0]->getText());
        int temp2Value =  quadsHandler.find(ctx->expression()[1]->getText());
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()[0]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[0]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[0]));
            //add validation for checking if the temporal exist?
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()[0]->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /**/
        if (temp2Value == 0){
          if (offsetOp.get(ctx->expression()[1]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[1]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[1]));
            arg2 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg2 = ctx->expression()[1]->getText();
          }
        } else {
          arg2 = quadsHandler.getId(temp2Value);
        }
        /*Get the temporal where the result is going to be store*/
        int resultTemp = temporalsHandler.getVariable();
        string func; 
        if (ctx->children[1]->getText() == "+"){
           func = "add";
        } else {
          func = "sub";
        }
        /*Insert The Quad*/
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          func, 
          arg1,
          arg2,
          ctx->getText()
        );
        //////////
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type  + ".\n";
        return;
      }
    }
  }
  
  virtual void exitExpressionPairRel(decafParser::ExpressionPairRelContext *ctx) override {
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    } else {
      if (exp1Type == exp2Type){
        nodeTypes.put(ctx, "boolean");
        /*Check if the expression is in the symbol table*/
        string arg1;
        string arg2;
        int temp1Value =  quadsHandler.find(ctx->expression()[0]->getText());
        int temp2Value =  quadsHandler.find(ctx->expression()[1]->getText());
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()[0]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[0]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[0]));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()[0]->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /**/
        if (temp2Value == 0){
          if (offsetOp.get(ctx->expression()[1]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[1]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[1]));
            arg2 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg2 = ctx->expression()[1]->getText();
          }
        } else {
          arg2 = quadsHandler.getId(temp2Value);
        }
        /*Get the temporal where the result is going to be store*/
        // int resultTemp = temporalsHandler.getVariable();
        string func; 
        if (ctx->children[1]->getText() == "<"){
           func = "lt";
        } else if (ctx->children[1]->getText() == ">"){
          func = "gt";
        } else if (ctx->children[1]->getText() == "<="){
          func = "le";
        } else {
          func = "ge";
        }
        /*Insert The Quad*/
        quadsHandler.binding(
          correctLabel.top(), // add later
          func, 
          arg1,
          arg2,
          ""//ctx->getText()
        );
        quadsHandler.binding(
          wrongLabel.top(), // add later
          "goto", 
          "",
          "",
          ""//ctx->getText()
        );
        //////////
        /* Check for after writng */                        
        string parentValue = afterExpr.get(ctx->parent);
        if (parentValue == "switch") {
          //cout << "Switch back " << endl;
          string label = wrongLabel.top();
          wrongLabel.top() = correctLabel.top();
          correctLabel.top() = label;
        } else if (parentValue.size() > 0 ){
          afterExpr.put(ctx->parent, "");
          quadsHandler.binding(
            parentValue,  
            "label", 
            "",
            "",
            ""
          );
          //cout << parentValue << ":" << endl;
          if (ctx->parent->children[1]->getText() == "&&"){
            correctLabel.pop();
          } else {
            wrongLabel.pop();
          }
        }
        /*                        */
        //////////
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type + ".\n";
        return;
      }
    }
  }
  
  virtual void exitExpressionPairEq(decafParser::ExpressionPairEqContext *ctx) override {
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    } else {
      if (exp1Type == exp2Type){
        nodeTypes.put(ctx, "boolean");
        //////////
        /*Check if the expression is in the symbol table*/
        string arg1;
        string arg2;
        int temp1Value =  quadsHandler.find(ctx->expression()[0]->getText());
        int temp2Value =  quadsHandler.find(ctx->expression()[1]->getText());
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()[0]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[0]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[0]));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()[0]->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
        /**/
        if (temp2Value == 0){
          if (offsetOp.get(ctx->expression()[1]).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()[1]->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()[1]));
            arg2 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg2 = ctx->expression()[1]->getText();
          }
        } else {
          arg2 = quadsHandler.getId(temp2Value);
        }
        /*Get the temporal where the result is going to be store*/
        int resultTemp = temporalsHandler.getVariable();
        string func; 
        if (ctx->children[1]->getText() == "=="){
          func = "eq";
        } else {
          func = "ne";
        }
        /*Insert The Quad*/
        quadsHandler.binding(
          correctLabel.top(), // add later
          func, 
          arg1,
          arg2,
          ""//ctx->getText()
        );
        quadsHandler.binding(
          wrongLabel.top(), // add later
          "goto", 
          "",
          "",
          ""//ctx->getText()
        );
        /* Check for after writng */                        
        string parentValue = afterExpr.get(ctx->parent);
        if (parentValue == "switch") {
          //cout << "Switch back " << endl;
          string label = wrongLabel.top();
          wrongLabel.top() = correctLabel.top();
          correctLabel.top() = label;
        } else if (parentValue.size() > 0 ){
          afterExpr.put(ctx->parent, "");
          quadsHandler.binding(
            parentValue,  
            "label", 
            "",
            "",
            ""
          );
          //cout << parentValue << ":" << endl;
          if (ctx->parent->children[1]->getText() == "&&"){
            correctLabel.pop();
          } else {
            wrongLabel.pop();
          }
        }
        /*                        */
        //////////
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type + ".\n";
        return;
      }
    }
  }

  virtual void enterExpressionPairCond(decafParser::ExpressionPairCondContext *ctx) override {
    //////////
    string func; 
    string label = "L"+to_string(labelsHandler.getVariable());
    if (ctx->children[1]->getText() == "&&"){
      correctLabel.push(label);
    } else {
      wrongLabel.push(label);
    }
    afterExpr.put(ctx, label);
    //cout << "guarde " << afterExpr.get(ctx) << endl;
  }
  
  virtual void exitExpressionPairCond(decafParser::ExpressionPairCondContext *ctx) override {
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    } else {
      if ((exp1Type == "boolean") && (exp2Type == "boolean")){
        nodeTypes.put(ctx, "boolean");
        //////////
        /* Check for after writng */                        
        string parentValue = afterExpr.get(ctx->parent);
        if (parentValue == "switch") {
          //cout << "Switch back " << endl;
          string label = wrongLabel.top();
          wrongLabel.top() = correctLabel.top();
          correctLabel.top() = label;
        } else if (parentValue.size() > 0 ){
          afterExpr.put(ctx->parent, "");
          quadsHandler.binding(
            parentValue,  
            "label", 
            "",
            "",
            ""
          );
          //cout << parentValue << ":" << endl;
          if (ctx->parent->children[1]->getText() == "&&"){
            correctLabel.pop();
          } else {
            wrongLabel.pop();
          }
        }
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type + ".\n";
        return;
      }
    }
  }

  virtual void exitExpressionLocation(decafParser::ExpressionLocationContext *ctx) override {
    nodeTypes.put( ctx, nodeTypes.get(ctx->location()) );
    nodeValues.put( ctx, nodeValues.get(ctx->location()) ); 
  }

  virtual void exitExpressionMethodCall(decafParser::ExpressionMethodCallContext *ctx) override { 
    nodeTypes.put( ctx, nodeTypes.get(ctx->methodCall()) );
    nodeValues.put( ctx, nodeValues.get(ctx->methodCall()) );
  }

  virtual void exitExpressionLiteral(decafParser::ExpressionLiteralContext *ctx) override { 
    nodeTypes.put( ctx, nodeTypes.get(ctx->literal()) );
    nodeValues.put( ctx, nodeValues.get(ctx->literal()) );
  }

  virtual void exitExpressionNegativ(decafParser::ExpressionNegativContext *ctx) override {
    if (nodeTypes.get(ctx->expression()) == "error") {
      nodeTypes.put( ctx, "error" );
    }else if (nodeTypes.get(ctx->expression()) == "int") {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      nodeValues.put( ctx, nodeValues.get(ctx->expression()) ); // update to real, negativ value?
      //////////
      /*Check if the expression is in the symbol table*/
        string arg1;
        int temp1Value =  quadsHandler.find(ctx->expression()->getText());
        /**/
        if (temp1Value == 0){
          if (offsetOp.get(ctx->expression()).size() != 0){
            string loc = (symbolTable.isGlobal(ctx->expression()->getText())) ? "g[" : "l[";
            int tempValue =  quadsHandler.find(offsetOp.get(ctx->expression()));
            arg1 = loc+quadsHandler.getId(tempValue)+"]";
          } else {
            arg1 = ctx->expression()->getText();
          }
        } else {
          arg1 = quadsHandler.getId(temp1Value);
        }
      /*Get the temporal where the result is going to be store*/
      int resultTemp = temporalsHandler.getVariable();
      /*Insert The Quad*/
      quadsHandler.binding(
        "t"+to_string(resultTemp), 
        "neg", 
        arg1,
        "",
        ctx->getText()
      );
      //////////
    } else {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<", incompatible type " + nodeTypes.get(ctx->expression()) + " and operator \"-\"." + ".\n";
    }
  }

  virtual void enterExpressionNegation(decafParser::ExpressionNegationContext *ctx) override {
    //////////
    string label = wrongLabel.top();
    wrongLabel.top() = correctLabel.top();
    correctLabel.top() = label;
    afterExpr.put(ctx, "switch");
    //////////
  }

  virtual void exitExpressionNegation(decafParser::ExpressionNegationContext *ctx) override {
    if (nodeTypes.get(ctx->expression()) == "error") {
      nodeTypes.put( ctx, "error" );
    } else if (nodeTypes.get(ctx->expression()) == "boolean") {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
      /* Check for after writng */                        
      string parentValue = afterExpr.get(ctx->parent);
      if (parentValue == "switch") {
        //cout << "Switch back " << endl;
        string label = wrongLabel.top();
        wrongLabel.top() = correctLabel.top();
        correctLabel.top() = label;
      } else if (parentValue.size() > 0 ){
        afterExpr.put(ctx->parent, "");
        quadsHandler.binding(
          parentValue,  
          "label", 
          "",
          "",
          ""
        );
        //cout << parentValue << ":" << endl;
        if (ctx->parent->children[1]->getText() == "&&"){
          correctLabel.pop();
        } else {
          wrongLabel.pop();
        }
      }
      /*                        */
    } else {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<" incompatible type " + nodeTypes.get(ctx->expression()) + " and operator \"!\"." + ".\n";
    }
  }

  virtual void exitExpressionParentesis(decafParser::ExpressionParentesisContext *ctx) override {
    if (nodeTypes.get(ctx->expression()) == "void") {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<", expressions cannot be void." << endl;
    } else {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
      //////////
      /*Check if the expression is in the symbol table*/
      int temp1Value =  quadsHandler.find(ctx->expression()->getText());
      if (temp1Value != 0) {
        /*Get the temporal where the result is going to be store*/
        int resultTemp = temporalsHandler.getVariable();
        /*Insert The Quad*/
        quadsHandler.binding(
          "t"+to_string(resultTemp), 
          "mov", 
          quadsHandler.getId(temp1Value),
          "",
          ctx->getText()
        );
        //////////
      }
      /* Check for after writng */                        
      string parentValue = afterExpr.get(ctx->parent);
      if (parentValue == "switch") {
        //cout << "Switch back " << endl;
        string label = wrongLabel.top();
        wrongLabel.top() = correctLabel.top();
        correctLabel.top() = label;
      } else if (parentValue.size() > 0 ){
        afterExpr.put(ctx->parent, "");
        quadsHandler.binding(
          parentValue,  
          "label", 
          "",
          "",
          ""
        );
        //cout << parentValue << ":" << endl;
        if (ctx->parent->children[1]->getText() == "&&"){
          correctLabel.pop();
        } else {
          wrongLabel.pop();
        }
      }
      /*                        */
    }
  }

  virtual void exitArg(decafParser::ArgContext *ctx) override {
    nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
    nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
  }

  virtual void exitLiteral(decafParser::LiteralContext * ctx) override {
    if (ctx->int_literal() != 0){
      nodeTypes.put(ctx, "int");
      nodeValues.put(ctx, ctx->int_literal()->getText());
    } else if (ctx->char_literal() != 0){
      nodeTypes.put(ctx, "char");
      nodeValues.put(ctx, ctx->char_literal()->getText());
    }else if (ctx->bool_literal() != 0){
      nodeTypes.put(ctx, "boolean");
      nodeValues.put(ctx, ctx->bool_literal()->getText());
      if (ctx->bool_literal()->getText() == "true") {
        quadsHandler.binding(
          correctLabel.top(),  
          "goto", 
          "",
          "",
          ""
        );
      } else {
        quadsHandler.binding(
          wrongLabel.top(),  
          "goto", 
          "",
          "",
          ""
        );
      }
      /* Check for after writng */                        
      string parentValue = afterExpr.get(ctx->parent);
      if (parentValue == "switch") {
        //cout << "Switch back " << endl;
        string label = wrongLabel.top();
        wrongLabel.top() = correctLabel.top();
        correctLabel.top() = label;
      } else if (parentValue.size() > 0 ){
        afterExpr.put(ctx->parent, "");
        quadsHandler.binding(
          parentValue,  
          "label", 
          "",
          "",
          ""
        );
        //cout << parentValue << ":" << endl;
        if (ctx->parent->children[1]->getText() == "&&"){
          correctLabel.pop();
        } else {
          wrongLabel.pop();
        }
      }
      /*                        */
    }
  }
}; 