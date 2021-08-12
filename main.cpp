//g++ -I /usr/local/include/antlr4-runtime -o main main.cpp decafLexer.cpp decafParser.cpp /usr/local/lib/libantlr4-runtime.a


#include <iostream>

#include "antlr4-runtime.h"
#include "decafLexer.h"
#include "decafParser.h"
#include "decafBaseListener.h"

using namespace antlr4;


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  decafLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  decafParser parser(&tokens);

  //tree::ParseTree *tree = parser.key();

  return 0;
}
