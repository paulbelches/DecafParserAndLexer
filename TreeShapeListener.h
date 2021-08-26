
#include "./symbolTableHandler.h"
#include "./typeTableHandler.h"
#include "./functionTable.h"

#include "decafBaseListener.h"

using namespace antlr4;
using namespace std;

class TreeShapeListener : public decafBaseListener {
private:
  queue<string> readTokens;
  SymbolTableHandler symbolTable;
  TypeTableHandler typeTable;
  FunctionTable functionTable;
  tree::ParseTreeProperty<string> nodeTypes; //put y get
  tree::ParseTreeProperty<string> nodeValues; //put y get
public:
  virtual void enterProgram(decafParser::ProgramContext *ctx) override { 
    symbolTable.enter();
    typeTable.enter();
    typeTable.binding("void", 0);
    typeTable.binding("int", 4);
    typeTable.binding("char", 2);
    typeTable.binding("bool", 1);
  }

  virtual void exitProgram(decafParser::ProgramContext *ctx) override {
    //The program contains a main definition without params
    if (!functionTable.hasElement("main")) {
      cout << "Error, no main method declared." << endl;
      return;
    }
    if (functionTable.paramsAmount("main") > 0) {
      cout << "Error, main has unnecesary arguments." << endl;
      return;
    } 
  }

  virtual void exitVariableDeclaration(decafParser::VariableDeclarationContext *ctx) override {    
    string type =  ctx->varType()->getText();
    string identifier = ctx->ID()->getText();
    //add: check if the type exist
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      int id = typeTable.getId(type);
      symbolTable.binding(identifier, id, size);
    } else {
      cout << "Error, " + identifier + " already declared." << endl;
    }
  }

  virtual void exitArrayDeclaration(decafParser::ArrayDeclarationContext *ctx) override { 
    string type =  ctx->varType()->getText();
    string identifier = ctx->ID()->getText();
    string num = ctx->NUM()->getText();
    //add: check if the type exist
    if (atoi(num.c_str()) < 0){
      cout << "Error, index in " + identifier + " should be greater than 0." << endl;
      return;
    }
    if (!symbolTable.top().hasElement(identifier)) {
      int size = typeTable.getSize(type);
      int id = typeTable.getId(type);
      symbolTable.binding(identifier, id, atoi(num.c_str()) * size );
    } else {
      cout << "Error, " + identifier + " already declared." << endl;
    }
  }

  virtual void enterMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    symbolTable.enter();
    string type =  ctx->methodType()->getText();
    string identifier = ctx->ID()->getText();
    if (!functionTable.hasElement(identifier)){
      int id = typeTable.getId(type);
      int parameterCount = 0;
      vector<string> params;
      while (ctx->parameter(parameterCount) != 0){
        //cout << ctx->parameter(parameterCount)->parameterType()->getText() << endl;
        params.push_back(ctx->parameter(parameterCount)->parameterType()->getText());
        //cout << ctx->parameter(parameterCount)->ID()->getText() << endl;
        //Add parameter as variable to the context
        parameterCount++;
      }
      functionTable.binding(identifier, id, params);
    } else {
      cout << "Error, method " + identifier + " already declared." << endl;
    }
  }

  virtual void exitMethodDeclaration(decafParser::MethodDeclarationContext *ctx) override {
    symbolTable.exit();
  }

  virtual void exitOp(decafParser::OpContext *ctx) override {
    if (ctx->arith_op() != 0){
      nodeTypes.put(ctx, "arith");
      nodeValues.put(ctx, ctx->arith_op()->getText());
      return;
    }
    if (ctx->rel_op() != 0){
      nodeTypes.put(ctx, "rel");
      nodeValues.put(ctx, ctx->rel_op()->getText());
      return;
    }
    if (ctx->eq_op() != 0){
      nodeTypes.put(ctx, "eq");
      nodeValues.put(ctx, ctx->eq_op()->getText());
      return;
    }
    if (ctx->cond_op() != 0){
      nodeTypes.put(ctx, "cond");
      nodeValues.put(ctx, ctx->cond_op()->getText());
    }
  }

  virtual void exitLiteral(decafParser::LiteralContext * ctx) override {
    if (ctx->int_literal() != 0){
      nodeTypes.put(ctx, "int");
      nodeValues.put(ctx, ctx->int_literal()->getText());
      return;
    }
    if (ctx->char_literal() != 0){
      nodeTypes.put(ctx, "char");
      nodeValues.put(ctx, ctx->char_literal()->getText());
      return;
    }
    if (ctx->bool_literal() != 0){
      nodeTypes.put(ctx, "bool");
      nodeValues.put(ctx, ctx->bool_literal()->getText());
    }
  }
}; 