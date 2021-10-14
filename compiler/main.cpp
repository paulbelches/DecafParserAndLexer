// antlr4 -Dlanguage=Cpp decaf.g4

//g++ -I /usr/local/include/antlr4-runtime -o main main.cpp decafLexer.cpp decafParser.cpp /usr/local/lib/libantlr4-runtime.a

//

#include <string>
#include <iostream>
#include <queue>
#include <cstdlib>

#include "./TreeShapeListener.h"


#include "antlr4-runtime.h"
#include "decafLexer.h"
#include "decafParser.h"
#include "decafBaseListener.h"

using namespace antlr4;
using namespace std;


int main(int argc, const char* argv[]) {
  //cout << "You have entered " << argc << " arguments:" << "\n";
  
  string stream;
  
  if (argc > 1){
    stream = argv[1];
  } else {
    //Read file
    /*
    std::ifstream stream;
    stream.open("input.txt");*/
  }
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
