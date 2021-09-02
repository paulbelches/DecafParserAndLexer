// antlr4 -Dlanguage=Cpp decaf.g4

//g++ -I /usr/local/include/antlr4-runtime -o main main.cpp decafLexer.cpp decafParser.cpp /usr/local/lib/libantlr4-runtime.a

#include "./symbolTableHandler.h"
#include "./typeTableHandler.h"
#include "./functionTable.h"
#include "./structTableHandler.h"

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

public:

  virtual void enterProgram(decafParser::ProgramContext *ctx) override { 
    symbolTable.enter();
    typeTable.enter();
    structTable.enter();
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
      cout << "line "<< ctx->start->getLine() <<", no main method declared." << endl;
      nodeTypes.put(ctx, "error");
    } else if (functionTable.paramsAmount("main") > 0) {
      cout << "line "<< ctx->start->getLine() <<", main has unnecesary arguments." << endl;
      nodeTypes.put(ctx, "error");
    } 
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
    }
    
    if (typeTable.elementExist(type) < 0){
      cout << "line "<< ctx->start->getLine() <<", type " + type + " of variable " + identifier +" does not exist." << endl;
      nodeTypes.put(ctx, "error");
    } else if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared." << endl;
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
      typeTable.binding("struct"+identifier, 0); //Modify size
      typeTable.binding("struct"+identifier+"[]", 0); //Modify size
      return;
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared." << endl;
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
      cout << "line "<< ctx->start->getLine() <<", type " + type + " of variable " + identifier +" does not exist." << endl;
      nodeTypes.put(ctx, "error");
    } else if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, atoi(num.c_str()) * size );
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared." << endl;
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void enterMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    symbolTable.enter();
    typeTable.enter();
    structTable.enter();
    string type =  ctx->methodType()->getText();
    string identifier = ctx->ID()->getText();
    if (!functionTable.hasElement(identifier)){
      int parameterCount = 0;
      vector<string> params;
      while (ctx->parameter(parameterCount) != 0){
        nodeValues.put(ctx->parameter(parameterCount), identifier);
        parameterCount++;
      }
      functionTable.binding(identifier, type, params);
      nodeTypes.put(ctx, type);
    } else {
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " already declared." << endl;
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void exitMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    symbolTable.exit();
    typeTable.exit();
    structTable.exit();
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
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " expected return " + methodType + " but " + blockType + " returned" << endl;
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void exitParameterVariable(decafParser::ParameterVariableContext *ctx) override {
    //cout << ctx << " parameter variable" << endl;
    string type =  ctx->parameterType()->getText();
    string identifier = ctx->ID()->getText();
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
      nodeTypes.put(ctx, type);
      /////////////MOdify
      functionTable.pushParam(nodeValues.get(ctx), type);
      /////////////
    } else {
      cout << "line "<< ctx->start->getLine() <<" " + identifier + " already declared." << endl;
      nodeTypes.put(ctx, "error");
    }
  }
  
  virtual void exitParameterArray(decafParser::ParameterArrayContext *ctx) override {
    string type =  ctx->parameterType()->getText() + "[]";
    string identifier = ctx->ID()->getText();
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      symbolTable.binding(identifier, type, size);
      nodeTypes.put(ctx, type);
      /////////////MOdify
      functionTable.pushParam(nodeValues.get(ctx), type);
      /////////////
    } else {
      cout << "line "<< ctx->start->getLine() <<", " + identifier + " already declared." << endl;
      nodeTypes.put(ctx, "error");
    }
  }

  virtual void exitBlock(decafParser::BlockContext *ctx) override {
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
            cout << "line "<< ctx->start->getLine() <<", multiple types return in method" << endl;
            nodeTypes.put(ctx, "error");
            return;
          }
        }
      }
    }
    nodeTypes.put( ctx, "void" );
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
          cout << "line "<< ctx->start->getLine() <<", if statement returns two diferent types" << endl;
        }
      }
    } else {
      nodeTypes.put(ctx, "error");
      cout << "line "<< ctx->start->getLine() <<", if statement with no boolean conditional" << endl;
    }
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
      cout << "line "<< ctx->start->getLine() <<", while statement with no boolean conditional" << endl;
    }
  }

  virtual void exitReturnStatement(decafParser::ReturnStatementContext *ctx) override {
    if (ctx->expression() == 0){
      nodeTypes.put(ctx, "void");
      //nodeValues.put( ctx, "return" );
    } else if (nodeTypes.get(ctx->expression()) == "error"){
      nodeTypes.put( ctx , "error");
    } else {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
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
    } else {
      cout << "line "<< ctx->start->getLine() <<", cannot asign " << expressionType << " to " << locationType << endl;
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
        //cout << ctx->arg(argCount)->getText()<< endl; 
        //cout << nodeTypes.get(ctx->arg(argCount))<< endl; 
        args.push_back(nodeTypes.get(ctx->arg(argCount)));
        argCount++;
      }
      //cout << argCount << endl;
      vector<string> methodParams = functionTable.getParams(identifier);
      //Compare firms
      if (equal(args.begin(), args.end(), methodParams.begin(), methodParams.end())){
        //cout << identifier << " is of type " << functionTable.getType(identifier) << endl;
        nodeTypes.put(ctx, functionTable.getType(identifier));
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
        cout << ") " << endl;
        //set error type
        nodeTypes.put(ctx, "error");
      }
    } else {
      cout << "line "<< ctx->start->getLine() <<", method " + identifier + " not declared." << endl;
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
          cout << "line "<< ctx->start->getLine() <<", type " + parentType + " has no atribute "+ identifier + "." << endl;
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", type " + parentType + " is not a struct." << endl;
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
        nodeTypes.put( ctx, type );
      } else {
        cout << "line "<< ctx->start->getLine() <<", variable " + identifier + " does not exist." << endl;
        nodeTypes.put(ctx, "error");
      }
    }
  }
  
  virtual void exitVarIdLocation(decafParser::VarIdLocationContext *ctx) override {
    if (nodeValues.get(ctx) == "son" ){
      string type = nodeTypes.get(ctx);
      nodeTypes.put(ctx->parent, type);
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
            cout << "line "<< ctx->start->getLine() <<", " + identifier + " is not and array." << endl;
            nodeTypes.put(ctx, "error");
            return;
          }
        } else {
          cout << "line "<< ctx->start->getLine() <<"r, type " + parentType + " has no atribute "+ identifier + "." << endl;
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", type " + parentType + "  is not a struct." << endl;
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
          cout << "line "<< ctx->start->getLine() <<", " + identifier + " is not and array." << endl;
          nodeTypes.put(ctx, "error");
          return;
        }
      } else {
        cout << "line "<< ctx->start->getLine() <<", variable " + identifier + " does not exist." << endl;
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
          cout << "line "<< ctx->start->getLine() <<", negativ index." << endl;
          nodeTypes.put(ctx, "error");
        }
      } catch(exception) {
        ;
      }
    } else {
      cout << "line "<< ctx->start->getLine() <<", index of type "+ nodeTypes.get(ctx->expression())<< endl;
      nodeTypes.put(ctx, "error");
    }
    ///
    if (nodeValues.get(ctx) == "son" ){
      string type = nodeTypes.get(ctx);
      nodeTypes.put(ctx->parent, type);
    } 
  }

//////////////////////////////////////////////////////////////////////////////
  virtual void exitExpressionPair(decafParser::ExpressionPairContext *ctx) override {
    // Add diferente type opernads operations
    string opType = nodeTypes.get(ctx->op());
    string opValue = nodeValues.get(ctx->op());
    string exp1Type = nodeTypes.get(ctx->expression()[0]);
    string exp1Value = nodeValues.get(ctx->expression()[0]);
    string exp2Type = nodeTypes.get(ctx->expression()[1]);
    string exp2Value = nodeValues.get(ctx->expression()[1]);

    if ( (exp1Type == "error") || (exp2Type == "error") ) {
      nodeTypes.put(ctx, "error");
      return;
    }
    if (opType == "cond")  {
      if ((exp1Type == "boolean") && (exp2Type == "boolean")){
        nodeTypes.put(ctx, "boolean");
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type << endl;
        return;
      }
    } else if (opType == "eq")  {
      if (exp1Type == exp2Type){
        nodeTypes.put(ctx, "boolean");
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type << endl;
        return;
      }
    } else if (opType == "rel")  {
      if (exp1Type == exp2Type){
        nodeTypes.put(ctx, "boolean");
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type << endl;
        return;
      }
    } else if (opType == "arith")  {
      if (((exp1Type == exp2Type)  && (exp1Type == "int"))){
        nodeTypes.put(ctx, "int");
        return;
      } else {
        nodeTypes.put(ctx, "error");
        cout << "line "<< ctx->start->getLine() <<", incompatible types " << exp1Type << " and " << exp2Type  << endl;
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
    } else {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<", incompatible type " + nodeTypes.get(ctx->expression()) + " and operator \"-\"." << endl;
    }
  }

  virtual void exitExpressionNegation(decafParser::ExpressionNegationContext *ctx) override {
    if (nodeTypes.get(ctx->expression()) == "error") {
      nodeTypes.put( ctx, "error" );
    } else if (nodeTypes.get(ctx->expression()) == "boolean") {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
    } else {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<" incompatible type " + nodeTypes.get(ctx->expression()) + " and operator \"!\"." << endl;
    }
  }

  virtual void exitExpressionParentesis(decafParser::ExpressionParentesisContext *ctx) override {
    if (nodeTypes.get(ctx->expression()) == "void") {
      nodeTypes.put( ctx, "error" );
      cout << "line "<< ctx->start->getLine() <<", expressions cannot be void." << endl;
    } else {
      nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
      nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
    }
  }

  virtual void exitArg(decafParser::ArgContext *ctx) override {
    nodeTypes.put( ctx, nodeTypes.get(ctx->expression()) );
    nodeValues.put( ctx, nodeValues.get(ctx->expression()) );
  }

  virtual void exitOp(decafParser::OpContext *ctx) override {
    if (ctx->arith_op() != 0){
      nodeTypes.put(ctx, "arith");
      nodeValues.put(ctx, ctx->arith_op()->getText());
    } else if (ctx->rel_op() != 0){
      nodeTypes.put(ctx, "rel");
      nodeValues.put(ctx, ctx->rel_op()->getText());
    } else if (ctx->eq_op() != 0){
      nodeTypes.put(ctx, "eq");
      nodeValues.put(ctx, ctx->eq_op()->getText());
    } else if (ctx->cond_op() != 0){
      nodeTypes.put(ctx, "cond");
      nodeValues.put(ctx, ctx->cond_op()->getText());
    }
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
    }
  }
}; 