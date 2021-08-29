
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

  virtual void enterParameterVariable(decafParser::ParameterVariableContext *ctx) = 0;
  virtual void exitParameterVariable(decafParser::ParameterVariableContext *ctx) = 0;

  virtual void enterParameterArray(decafParser::ParameterArrayContext *ctx) = 0;
  virtual void exitParameterArray(decafParser::ParameterArrayContext *ctx) = 0;

  virtual void enterParameterType(decafParser::ParameterTypeContext *ctx) = 0;
  virtual void exitParameterType(decafParser::ParameterTypeContext *ctx) = 0;

  virtual void enterBlock(decafParser::BlockContext *ctx) = 0;
  virtual void exitBlock(decafParser::BlockContext *ctx) = 0;

  virtual void enterIfStatement(decafParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(decafParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(decafParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(decafParser::WhileStatementContext *ctx) = 0;

  virtual void enterReturnStatement(decafParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(decafParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBlockStatement(decafParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(decafParser::BlockStatementContext *ctx) = 0;

  virtual void enterAsignationStatement(decafParser::AsignationStatementContext *ctx) = 0;
  virtual void exitAsignationStatement(decafParser::AsignationStatementContext *ctx) = 0;

  virtual void enterExpresionStatement(decafParser::ExpresionStatementContext *ctx) = 0;
  virtual void exitExpresionStatement(decafParser::ExpresionStatementContext *ctx) = 0;

  virtual void enterMethodCall(decafParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(decafParser::MethodCallContext *ctx) = 0;

  virtual void enterVarIdLocation(decafParser::VarIdLocationContext *ctx) = 0;
  virtual void exitVarIdLocation(decafParser::VarIdLocationContext *ctx) = 0;

  virtual void enterStructLocation(decafParser::StructLocationContext *ctx) = 0;
  virtual void exitStructLocation(decafParser::StructLocationContext *ctx) = 0;

  virtual void enterArrayLocation(decafParser::ArrayLocationContext *ctx) = 0;
  virtual void exitArrayLocation(decafParser::ArrayLocationContext *ctx) = 0;

  virtual void enterExpressionLiteral(decafParser::ExpressionLiteralContext *ctx) = 0;
  virtual void exitExpressionLiteral(decafParser::ExpressionLiteralContext *ctx) = 0;

  virtual void enterExpressionNegation(decafParser::ExpressionNegationContext *ctx) = 0;
  virtual void exitExpressionNegation(decafParser::ExpressionNegationContext *ctx) = 0;

  virtual void enterExpressionParentesis(decafParser::ExpressionParentesisContext *ctx) = 0;
  virtual void exitExpressionParentesis(decafParser::ExpressionParentesisContext *ctx) = 0;

  virtual void enterExpressionPair(decafParser::ExpressionPairContext *ctx) = 0;
  virtual void exitExpressionPair(decafParser::ExpressionPairContext *ctx) = 0;

  virtual void enterExpressionLocation(decafParser::ExpressionLocationContext *ctx) = 0;
  virtual void exitExpressionLocation(decafParser::ExpressionLocationContext *ctx) = 0;

  virtual void enterExpressionMethodCall(decafParser::ExpressionMethodCallContext *ctx) = 0;
  virtual void exitExpressionMethodCall(decafParser::ExpressionMethodCallContext *ctx) = 0;

  virtual void enterExpressionNegativ(decafParser::ExpressionNegativContext *ctx) = 0;
  virtual void exitExpressionNegativ(decafParser::ExpressionNegativContext *ctx) = 0;

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

