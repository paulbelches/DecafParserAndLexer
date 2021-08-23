
// Generated from decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "decafListener.h"


/**
 * This class provides an empty implementation of decafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  decafBaseListener : public decafListener {
public:

  virtual void enterProgram(decafParser::ProgramContext *ctx) override { }
  virtual void exitProgram(decafParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDeclaration(decafParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(decafParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(decafParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(decafParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterArrayDeclaration(decafParser::ArrayDeclarationContext * /*ctx*/) override { }
  virtual void exitArrayDeclaration(decafParser::ArrayDeclarationContext * /*ctx*/) override { }

  virtual void enterStructDeclaration(decafParser::StructDeclarationContext * /*ctx*/) override { }
  virtual void exitStructDeclaration(decafParser::StructDeclarationContext * /*ctx*/) override { }

  virtual void enterVarType(decafParser::VarTypeContext * /*ctx*/) override { }
  virtual void exitVarType(decafParser::VarTypeContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(decafParser::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(decafParser::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterMethodType(decafParser::MethodTypeContext * /*ctx*/) override { }
  virtual void exitMethodType(decafParser::MethodTypeContext * /*ctx*/) override { }

  virtual void enterParameter(decafParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(decafParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameterType(decafParser::ParameterTypeContext * /*ctx*/) override { }
  virtual void exitParameterType(decafParser::ParameterTypeContext * /*ctx*/) override { }

  virtual void enterBlock(decafParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(decafParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(decafParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(decafParser::StatementContext * /*ctx*/) override { }

  virtual void enterLocation(decafParser::LocationContext * /*ctx*/) override { }
  virtual void exitLocation(decafParser::LocationContext * /*ctx*/) override { }

  virtual void enterExpression(decafParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(decafParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterMethodCall(decafParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(decafParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterArg(decafParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(decafParser::ArgContext * /*ctx*/) override { }

  virtual void enterOp(decafParser::OpContext * /*ctx*/) override { }
  virtual void exitOp(decafParser::OpContext * /*ctx*/) override { }

  virtual void enterArith_op(decafParser::Arith_opContext * /*ctx*/) override { }
  virtual void exitArith_op(decafParser::Arith_opContext * /*ctx*/) override { }

  virtual void enterRel_op(decafParser::Rel_opContext * /*ctx*/) override { }
  virtual void exitRel_op(decafParser::Rel_opContext * /*ctx*/) override { }

  virtual void enterEq_op(decafParser::Eq_opContext * /*ctx*/) override { }
  virtual void exitEq_op(decafParser::Eq_opContext * /*ctx*/) override { }

  virtual void enterCond_op(decafParser::Cond_opContext * /*ctx*/) override { }
  virtual void exitCond_op(decafParser::Cond_opContext * /*ctx*/) override { }

  virtual void enterLiteral(decafParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(decafParser::LiteralContext * /*ctx*/) override { }

  virtual void enterInt_literal(decafParser::Int_literalContext * /*ctx*/) override { }
  virtual void exitInt_literal(decafParser::Int_literalContext * /*ctx*/) override { }

  virtual void enterChar_literal(decafParser::Char_literalContext * /*ctx*/) override { }
  virtual void exitChar_literal(decafParser::Char_literalContext * /*ctx*/) override { }

  virtual void enterBool_literal(decafParser::Bool_literalContext * /*ctx*/) override { }
  virtual void exitBool_literal(decafParser::Bool_literalContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

