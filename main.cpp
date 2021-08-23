// antlr4 -Dlanguage=Cpp decaf.g4

//g++ -I /usr/local/include/antlr4-runtime -o main main.cpp decafLexer.cpp decafParser.cpp /usr/local/lib/libantlr4-runtime.a

#include <string>
#include <iostream>
#include <queue>

#include "./symbolTableHandler.h"
#include "./typeTableHandler.h"

#include "antlr4-runtime.h"
#include "decafLexer.h"
#include "decafParser.h"
#include "decafBaseListener.h"

using namespace antlr4;
using namespace std;

class TreeShapeListener : public decafBaseListener {
private:
  queue<string> readTokens;
  SymbolTableHandler symbolTable;
  TypeTableHandler typeTable;
public:
  virtual void enterProgram(decafParser::ProgramContext *ctx) override { 
    symbolTable.enter();
    typeTable.enter();
    typeTable.binding("int", 4);
    typeTable.binding("char", 4);
    typeTable.binding("bool", 4);
  }

  virtual void exitVariableDeclaration(decafParser::VariableDeclarationContext *ctx) override {    
    //string type = 
    string type =  ctx->varType()->getText();
    string identifier = ctx->ID()->getText();
    //check if the type exist
    if (symbolTable.elementExist(identifier) == -1) {
      int size = typeTable.getSize(type);
      int id = typeTable.getId(type);
      symbolTable.binding(identifier, 1, id, size);
    } else {
      cout << "Error, " + identifier + " already declared." << endl;
    }
  }

  virtual void exitProgram(decafParser::ProgramContext *ctx) override {
    if (symbolTable.elementExist("main") == -1) {
      cout << "Error, no main method declared." << endl;
    }

  }
}; 

int main(int argc, const char* argv[]) {
  //Read file
  std::ifstream stream;
  stream.open("input.txt");
  //Convert Stream
  ANTLRInputStream input(stream);
  //Call lexer
  decafLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  //call parser
  decafParser parser(&tokens);
  tree::ParseTree *tree = nullptr;
  try {
    // parse the input
    tree = parser.program();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
  }
  catch (antlr4::ParseCancellationException &e) {
    cout << "error" << endl;
    cout << e.what() << endl;
    exit(0);
  }
  return 0;
}
