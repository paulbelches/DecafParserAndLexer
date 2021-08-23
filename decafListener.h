
// Generated from decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "decafParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by decafParser.
 */
class  decafListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(decafParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(decafParser::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(decafParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(decafParser::DeclarationContext *ctx) = 0;

  virtual void enterVariableDeclaration(decafParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(decafParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterArrayDeclaration(decafParser::ArrayDeclarationContext *ctx) = 0;
  virtual void exitArrayDeclaration(decafParser::ArrayDeclarationContext *ctx) = 0;

  virtual void enterStructDeclaration(decafParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(decafParser::StructDeclarationContext *ctx) = 0;

  virtual void enterVarType(decafParser::VarTypeContext *ctx) = 0;
  virtual void exitVarType(decafParser::VarTypeContext *ctx) = 0;

  virtual void enterMethodDeclaration(decafParser::MethodDeclarationContext *ctx) = 0;
  virtual void exitMethodDeclaration(decafParser::MethodDeclarationContext *ctx) = 0;

  virtual void enterMethodType(decafParser::MethodTypeContext *ctx) = 0;
  virtual void exitMethodType(decafParser::MethodTypeContext *ctx) = 0;

  virtual void enterParameter(decafParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(decafParser::ParameterContext *ctx) = 0;

  virtual void enterParameterType(decafParser::ParameterTypeContext *ctx) = 0;
  virtual void exitParameterType(decafParser::ParameterTypeContext *ctx) = 0;

  virtual void enterBlock(decafParser::BlockContext *ctx) = 0;
  virtual void exitBlock(decafParser::BlockContext *ctx) = 0;

  virtual void enterStatement(decafParser::StatementContext *ctx) = 0;
  virtual void exitStatement(decafParser::StatementContext *ctx) = 0;

  virtual void enterLocation(decafParser::LocationContext *ctx) = 0;
  virtual void exitLocation(decafParser::LocationContext *ctx) = 0;

  virtual void enterExpression(decafParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(decafParser::ExpressionContext *ctx) = 0;

  virtual void enterMethodCall(decafParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(decafParser::MethodCallContext *ctx) = 0;

  virtual void enterArg(decafParser::ArgContext *ctx) = 0;
  virtual void exitArg(decafParser::ArgContext *ctx) = 0;

  virtual void enterOp(decafParser::OpContext *ctx) = 0;
  virtual void exitOp(decafParser::OpContext *ctx) = 0;

  virtual void enterArith_op(decafParser::Arith_opContext *ctx) = 0;
  virtual void exitArith_op(decafParser::Arith_opContext *ctx) = 0;

  virtual void enterRel_op(decafParser::Rel_opContext *ctx) = 0;
  virtual void exitRel_op(decafParser::Rel_opContext *ctx) = 0;

  virtual void enterEq_op(decafParser::Eq_opContext *ctx) = 0;
  virtual void exitEq_op(decafParser::Eq_opContext *ctx) = 0;

  virtual void enterCond_op(decafParser::Cond_opContext *ctx) = 0;
  virtual void exitCond_op(decafParser::Cond_opContext *ctx) = 0;

  virtual void enterLiteral(decafParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(decafParser::LiteralContext *ctx) = 0;

  virtual void enterInt_literal(decafParser::Int_literalContext *ctx) = 0;
  virtual void exitInt_literal(decafParser::Int_literalContext *ctx) = 0;

  virtual void enterChar_literal(decafParser::Char_literalContext *ctx) = 0;
  virtual void exitChar_literal(decafParser::Char_literalContext *ctx) = 0;

  virtual void enterBool_literal(decafParser::Bool_literalContext *ctx) = 0;
  virtual void exitBool_literal(decafParser::Bool_literalContext *ctx) = 0;


};

