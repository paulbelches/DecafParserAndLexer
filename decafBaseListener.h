
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

  virtual void enterProgram(decafParser::ProgramContext * /*ctx*/) override { }
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

  virtual void enterParameterVariable(decafParser::ParameterVariableContext * /*ctx*/) override { }
  virtual void exitParameterVariable(decafParser::ParameterVariableContext * /*ctx*/) override { }

  virtual void enterParameterArray(decafParser::ParameterArrayContext * /*ctx*/) override { }
  virtual void exitParameterArray(decafParser::ParameterArrayContext * /*ctx*/) override { }

  virtual void enterParameterType(decafParser::ParameterTypeContext * /*ctx*/) override { }
  virtual void exitParameterType(decafParser::ParameterTypeContext * /*ctx*/) override { }

  virtual void enterBlock(decafParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(decafParser::BlockContext * /*ctx*/) override { }

  virtual void enterIfStatement(decafParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(decafParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(decafParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(decafParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(decafParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(decafParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBlockStatement(decafParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(decafParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterAsignationStatement(decafParser::AsignationStatementContext * /*ctx*/) override { }
  virtual void exitAsignationStatement(decafParser::AsignationStatementContext * /*ctx*/) override { }

  virtual void enterExpresionStatement(decafParser::ExpresionStatementContext * /*ctx*/) override { }
  virtual void exitExpresionStatement(decafParser::ExpresionStatementContext * /*ctx*/) override { }

  virtual void enterMethodCall(decafParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(decafParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterVarIdLocation(decafParser::VarIdLocationContext * /*ctx*/) override { }
  virtual void exitVarIdLocation(decafParser::VarIdLocationContext * /*ctx*/) override { }

  virtual void enterArrayLocation(decafParser::ArrayLocationContext * /*ctx*/) override { }
  virtual void exitArrayLocation(decafParser::ArrayLocationContext * /*ctx*/) override { }

  virtual void enterExpressionLiteral(decafParser::ExpressionLiteralContext * /*ctx*/) override { }
  virtual void exitExpressionLiteral(decafParser::ExpressionLiteralContext * /*ctx*/) override { }

  virtual void enterExpressionNegation(decafParser::ExpressionNegationContext * /*ctx*/) override { }
  virtual void exitExpressionNegation(decafParser::ExpressionNegationContext * /*ctx*/) override { }

  virtual void enterExpressionParentesis(decafParser::ExpressionParentesisContext * /*ctx*/) override { }
  virtual void exitExpressionParentesis(decafParser::ExpressionParentesisContext * /*ctx*/) override { }

  virtual void enterExpressionPair(decafParser::ExpressionPairContext * /*ctx*/) override { }
  virtual void exitExpressionPair(decafParser::ExpressionPairContext * /*ctx*/) override { }

  virtual void enterExpressionLocation(decafParser::ExpressionLocationContext * /*ctx*/) override { }
  virtual void exitExpressionLocation(decafParser::ExpressionLocationContext * /*ctx*/) override { }

  virtual void enterExpressionMethodCall(decafParser::ExpressionMethodCallContext * /*ctx*/) override { }
  virtual void exitExpressionMethodCall(decafParser::ExpressionMethodCallContext * /*ctx*/) override { }

  virtual void enterExpressionNegativ(decafParser::ExpressionNegativContext * /*ctx*/) override { }
  virtual void exitExpressionNegativ(decafParser::ExpressionNegativContext * /*ctx*/) override { }

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

