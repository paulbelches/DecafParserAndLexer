
// Generated from decaf.g4 by ANTLR 4.7.2


#include "decafListener.h"

#include "decafParser.h"


using namespace antlrcpp;
using namespace antlr4;

decafParser::decafParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

decafParser::~decafParser() {
  delete _interpreter;
}

std::string decafParser::getGrammarFileName() const {
  return "decaf.g4";
}

const std::vector<std::string>& decafParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& decafParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

decafParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<decafParser::DeclarationContext *> decafParser::ProgramContext::declaration() {
  return getRuleContexts<decafParser::DeclarationContext>();
}

decafParser::DeclarationContext* decafParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<decafParser::DeclarationContext>(i);
}


size_t decafParser::ProgramContext::getRuleIndex() const {
  return decafParser::RuleProgram;
}

void decafParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void decafParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

decafParser::ProgramContext* decafParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, decafParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(decafParser::T__0);
    setState(49);
    match(decafParser::T__1);
    setState(50);
    match(decafParser::T__2);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__7)
      | (1ULL << decafParser::T__8)
      | (1ULL << decafParser::T__9)
      | (1ULL << decafParser::T__10)
      | (1ULL << decafParser::T__11))) != 0)) {
      setState(51);
      declaration();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
    match(decafParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

decafParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

decafParser::VarDeclarationContext* decafParser::DeclarationContext::varDeclaration() {
  return getRuleContext<decafParser::VarDeclarationContext>(0);
}

decafParser::StructDeclarationContext* decafParser::DeclarationContext::structDeclaration() {
  return getRuleContext<decafParser::StructDeclarationContext>(0);
}

decafParser::MethodDeclarationContext* decafParser::DeclarationContext::methodDeclaration() {
  return getRuleContext<decafParser::MethodDeclarationContext>(0);
}


size_t decafParser::DeclarationContext::getRuleIndex() const {
  return decafParser::RuleDeclaration;
}

void decafParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void decafParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

decafParser::DeclarationContext* decafParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, decafParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      varDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      structDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      methodDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

decafParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::VarDeclarationContext::getRuleIndex() const {
  return decafParser::RuleVarDeclaration;
}

void decafParser::VarDeclarationContext::copyFrom(VarDeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

decafParser::VarTypeContext* decafParser::ArrayDeclarationContext::varType() {
  return getRuleContext<decafParser::VarTypeContext>(0);
}

tree::TerminalNode* decafParser::ArrayDeclarationContext::ID() {
  return getToken(decafParser::ID, 0);
}

tree::TerminalNode* decafParser::ArrayDeclarationContext::NUM() {
  return getToken(decafParser::NUM, 0);
}

decafParser::ArrayDeclarationContext::ArrayDeclarationContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void decafParser::ArrayDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDeclaration(this);
}
void decafParser::ArrayDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDeclaration(this);
}
//----------------- VariableDeclarationContext ------------------------------------------------------------------

decafParser::VarTypeContext* decafParser::VariableDeclarationContext::varType() {
  return getRuleContext<decafParser::VarTypeContext>(0);
}

tree::TerminalNode* decafParser::VariableDeclarationContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::VariableDeclarationContext::VariableDeclarationContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void decafParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}
void decafParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}
decafParser::VarDeclarationContext* decafParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, decafParser::RuleVarDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<decafParser::VariableDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(64);
      varType();
      setState(65);
      match(decafParser::ID);
      setState(66);
      match(decafParser::T__4);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<decafParser::ArrayDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(68);
      varType();
      setState(69);
      match(decafParser::ID);
      setState(70);
      match(decafParser::T__5);
      setState(71);
      match(decafParser::NUM);
      setState(72);
      match(decafParser::T__6);
      setState(73);
      match(decafParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

decafParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* decafParser::StructDeclarationContext::ID() {
  return getToken(decafParser::ID, 0);
}

std::vector<decafParser::VarDeclarationContext *> decafParser::StructDeclarationContext::varDeclaration() {
  return getRuleContexts<decafParser::VarDeclarationContext>();
}

decafParser::VarDeclarationContext* decafParser::StructDeclarationContext::varDeclaration(size_t i) {
  return getRuleContext<decafParser::VarDeclarationContext>(i);
}


size_t decafParser::StructDeclarationContext::getRuleIndex() const {
  return decafParser::RuleStructDeclaration;
}

void decafParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void decafParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}

decafParser::StructDeclarationContext* decafParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, decafParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      match(decafParser::T__7);
      setState(78);
      match(decafParser::ID);
      setState(79);
      match(decafParser::T__2);
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << decafParser::T__7)
        | (1ULL << decafParser::T__8)
        | (1ULL << decafParser::T__9)
        | (1ULL << decafParser::T__10)
        | (1ULL << decafParser::T__11))) != 0)) {
        setState(80);
        varDeclaration();
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(86);
      match(decafParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(87);
      match(decafParser::T__7);
      setState(88);
      match(decafParser::ID);
      setState(89);
      match(decafParser::T__2);
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << decafParser::T__7)
        | (1ULL << decafParser::T__8)
        | (1ULL << decafParser::T__9)
        | (1ULL << decafParser::T__10)
        | (1ULL << decafParser::T__11))) != 0)) {
        setState(90);
        varDeclaration();
        setState(95);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(96);
      match(decafParser::T__3);
      setState(97);
      match(decafParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

decafParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* decafParser::VarTypeContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::StructDeclarationContext* decafParser::VarTypeContext::structDeclaration() {
  return getRuleContext<decafParser::StructDeclarationContext>(0);
}


size_t decafParser::VarTypeContext::getRuleIndex() const {
  return decafParser::RuleVarType;
}

void decafParser::VarTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarType(this);
}

void decafParser::VarTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarType(this);
}

decafParser::VarTypeContext* decafParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, decafParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(100);
      match(decafParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101);
      match(decafParser::T__9);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(102);
      match(decafParser::T__10);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(103);
      match(decafParser::T__7);
      setState(104);
      match(decafParser::ID);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(105);
      structDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(106);
      match(decafParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

decafParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

decafParser::MethodTypeContext* decafParser::MethodDeclarationContext::methodType() {
  return getRuleContext<decafParser::MethodTypeContext>(0);
}

tree::TerminalNode* decafParser::MethodDeclarationContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::BlockContext* decafParser::MethodDeclarationContext::block() {
  return getRuleContext<decafParser::BlockContext>(0);
}

std::vector<decafParser::ParameterContext *> decafParser::MethodDeclarationContext::parameter() {
  return getRuleContexts<decafParser::ParameterContext>();
}

decafParser::ParameterContext* decafParser::MethodDeclarationContext::parameter(size_t i) {
  return getRuleContext<decafParser::ParameterContext>(i);
}


size_t decafParser::MethodDeclarationContext::getRuleIndex() const {
  return decafParser::RuleMethodDeclaration;
}

void decafParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void decafParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}

decafParser::MethodDeclarationContext* decafParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, decafParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    methodType();
    setState(110);
    match(decafParser::ID);
    setState(111);
    match(decafParser::T__12);
    setState(120);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__8)
      | (1ULL << decafParser::T__9)
      | (1ULL << decafParser::T__10))) != 0)) {
      setState(112);
      parameter();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == decafParser::T__13) {
        setState(113);
        match(decafParser::T__13);
        setState(114);
        parameter();
        setState(119);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(122);
    match(decafParser::T__14);
    setState(123);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodTypeContext ------------------------------------------------------------------

decafParser::MethodTypeContext::MethodTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::MethodTypeContext::getRuleIndex() const {
  return decafParser::RuleMethodType;
}

void decafParser::MethodTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodType(this);
}

void decafParser::MethodTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodType(this);
}

decafParser::MethodTypeContext* decafParser::methodType() {
  MethodTypeContext *_localctx = _tracker.createInstance<MethodTypeContext>(_ctx, getState());
  enterRule(_localctx, 12, decafParser::RuleMethodType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__8)
      | (1ULL << decafParser::T__9)
      | (1ULL << decafParser::T__10)
      | (1ULL << decafParser::T__11))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

decafParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::ParameterContext::getRuleIndex() const {
  return decafParser::RuleParameter;
}

void decafParser::ParameterContext::copyFrom(ParameterContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParameterArrayContext ------------------------------------------------------------------

decafParser::ParameterTypeContext* decafParser::ParameterArrayContext::parameterType() {
  return getRuleContext<decafParser::ParameterTypeContext>(0);
}

tree::TerminalNode* decafParser::ParameterArrayContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::ParameterArrayContext::ParameterArrayContext(ParameterContext *ctx) { copyFrom(ctx); }

void decafParser::ParameterArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterArray(this);
}
void decafParser::ParameterArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterArray(this);
}
//----------------- ParameterVariableContext ------------------------------------------------------------------

decafParser::ParameterTypeContext* decafParser::ParameterVariableContext::parameterType() {
  return getRuleContext<decafParser::ParameterTypeContext>(0);
}

tree::TerminalNode* decafParser::ParameterVariableContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::ParameterVariableContext::ParameterVariableContext(ParameterContext *ctx) { copyFrom(ctx); }

void decafParser::ParameterVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterVariable(this);
}
void decafParser::ParameterVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterVariable(this);
}
decafParser::ParameterContext* decafParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 14, decafParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ParameterContext *>(_tracker.createInstance<decafParser::ParameterVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(127);
      parameterType();
      setState(128);
      match(decafParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ParameterContext *>(_tracker.createInstance<decafParser::ParameterArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(130);
      parameterType();
      setState(131);
      match(decafParser::ID);
      setState(132);
      match(decafParser::T__5);
      setState(133);
      match(decafParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeContext ------------------------------------------------------------------

decafParser::ParameterTypeContext::ParameterTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::ParameterTypeContext::getRuleIndex() const {
  return decafParser::RuleParameterType;
}

void decafParser::ParameterTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterType(this);
}

void decafParser::ParameterTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterType(this);
}

decafParser::ParameterTypeContext* decafParser::parameterType() {
  ParameterTypeContext *_localctx = _tracker.createInstance<ParameterTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, decafParser::RuleParameterType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__8)
      | (1ULL << decafParser::T__9)
      | (1ULL << decafParser::T__10))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

decafParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<decafParser::VarDeclarationContext *> decafParser::BlockContext::varDeclaration() {
  return getRuleContexts<decafParser::VarDeclarationContext>();
}

decafParser::VarDeclarationContext* decafParser::BlockContext::varDeclaration(size_t i) {
  return getRuleContext<decafParser::VarDeclarationContext>(i);
}

std::vector<decafParser::StatementContext *> decafParser::BlockContext::statement() {
  return getRuleContexts<decafParser::StatementContext>();
}

decafParser::StatementContext* decafParser::BlockContext::statement(size_t i) {
  return getRuleContext<decafParser::StatementContext>(i);
}


size_t decafParser::BlockContext::getRuleIndex() const {
  return decafParser::RuleBlock;
}

void decafParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void decafParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

decafParser::BlockContext* decafParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 18, decafParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(decafParser::T__2);
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__2)
      | (1ULL << decafParser::T__4)
      | (1ULL << decafParser::T__7)
      | (1ULL << decafParser::T__8)
      | (1ULL << decafParser::T__9)
      | (1ULL << decafParser::T__10)
      | (1ULL << decafParser::T__11)
      | (1ULL << decafParser::T__12)
      | (1ULL << decafParser::T__15)
      | (1ULL << decafParser::T__17)
      | (1ULL << decafParser::T__18)
      | (1ULL << decafParser::T__21)
      | (1ULL << decafParser::T__22)
      | (1ULL << decafParser::T__35)
      | (1ULL << decafParser::T__36)
      | (1ULL << decafParser::ID)
      | (1ULL << decafParser::NUM)
      | (1ULL << decafParser::CHAR))) != 0)) {
      setState(142);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case decafParser::T__7:
        case decafParser::T__8:
        case decafParser::T__9:
        case decafParser::T__10:
        case decafParser::T__11: {
          setState(140);
          varDeclaration();
          break;
        }

        case decafParser::T__2:
        case decafParser::T__4:
        case decafParser::T__12:
        case decafParser::T__15:
        case decafParser::T__17:
        case decafParser::T__18:
        case decafParser::T__21:
        case decafParser::T__22:
        case decafParser::T__35:
        case decafParser::T__36:
        case decafParser::ID:
        case decafParser::NUM:
        case decafParser::CHAR: {
          setState(141);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(146);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147);
    match(decafParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

decafParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::StatementContext::getRuleIndex() const {
  return decafParser::RuleStatement;
}

void decafParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileStatementContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::WhileStatementContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::BlockContext* decafParser::WhileStatementContext::block() {
  return getRuleContext<decafParser::BlockContext>(0);
}

decafParser::WhileStatementContext::WhileStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}
void decafParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}
//----------------- BlockStatementContext ------------------------------------------------------------------

decafParser::BlockContext* decafParser::BlockStatementContext::block() {
  return getRuleContext<decafParser::BlockContext>(0);
}

decafParser::BlockStatementContext::BlockStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}
void decafParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}
//----------------- ExpresionStatementContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::ExpresionStatementContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::ExpresionStatementContext::ExpresionStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::ExpresionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpresionStatement(this);
}
void decafParser::ExpresionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpresionStatement(this);
}
//----------------- ReturnStatementContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::ReturnStatementContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::ReturnStatementContext::ReturnStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}
void decafParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}
//----------------- AsignationStatementContext ------------------------------------------------------------------

decafParser::LocationContext* decafParser::AsignationStatementContext::location() {
  return getRuleContext<decafParser::LocationContext>(0);
}

decafParser::ExpressionContext* decafParser::AsignationStatementContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::AsignationStatementContext::AsignationStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::AsignationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsignationStatement(this);
}
void decafParser::AsignationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsignationStatement(this);
}
//----------------- IfStatementContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::IfStatementContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

std::vector<decafParser::BlockContext *> decafParser::IfStatementContext::block() {
  return getRuleContexts<decafParser::BlockContext>();
}

decafParser::BlockContext* decafParser::IfStatementContext::block(size_t i) {
  return getRuleContext<decafParser::BlockContext>(i);
}

decafParser::IfStatementContext::IfStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void decafParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}
void decafParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}
decafParser::StatementContext* decafParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, decafParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::IfStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(149);
      match(decafParser::T__15);
      setState(150);
      match(decafParser::T__12);
      setState(151);
      expression(0);
      setState(152);
      match(decafParser::T__14);
      setState(153);
      block();
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == decafParser::T__16) {
        setState(154);
        match(decafParser::T__16);
        setState(155);
        block();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::WhileStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(158);
      match(decafParser::T__17);
      setState(159);
      match(decafParser::T__12);
      setState(160);
      expression(0);
      setState(161);
      match(decafParser::T__14);
      setState(162);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::ReturnStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(164);
      match(decafParser::T__18);
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << decafParser::T__12)
        | (1ULL << decafParser::T__21)
        | (1ULL << decafParser::T__22)
        | (1ULL << decafParser::T__35)
        | (1ULL << decafParser::T__36)
        | (1ULL << decafParser::ID)
        | (1ULL << decafParser::NUM)
        | (1ULL << decafParser::CHAR))) != 0)) {
        setState(165);
        expression(0);
      }
      setState(168);
      match(decafParser::T__4);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::BlockStatementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(169);
      block();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::AsignationStatementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(170);
      location();
      setState(171);
      match(decafParser::T__19);
      setState(172);
      expression(0);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<decafParser::ExpresionStatementContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(175);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << decafParser::T__12)
        | (1ULL << decafParser::T__21)
        | (1ULL << decafParser::T__22)
        | (1ULL << decafParser::T__35)
        | (1ULL << decafParser::T__36)
        | (1ULL << decafParser::ID)
        | (1ULL << decafParser::NUM)
        | (1ULL << decafParser::CHAR))) != 0)) {
        setState(174);
        expression(0);
      }
      setState(177);
      match(decafParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

decafParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* decafParser::MethodCallContext::ID() {
  return getToken(decafParser::ID, 0);
}

std::vector<decafParser::ArgContext *> decafParser::MethodCallContext::arg() {
  return getRuleContexts<decafParser::ArgContext>();
}

decafParser::ArgContext* decafParser::MethodCallContext::arg(size_t i) {
  return getRuleContext<decafParser::ArgContext>(i);
}


size_t decafParser::MethodCallContext::getRuleIndex() const {
  return decafParser::RuleMethodCall;
}

void decafParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void decafParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}

decafParser::MethodCallContext* decafParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 22, decafParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(decafParser::ID);
    setState(181);
    match(decafParser::T__12);

    setState(182);
    arg();
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == decafParser::T__13) {
      setState(183);
      match(decafParser::T__13);
      setState(184);
      arg();
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(190);
    match(decafParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocationContext ------------------------------------------------------------------

decafParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::LocationContext::getRuleIndex() const {
  return decafParser::RuleLocation;
}

void decafParser::LocationContext::copyFrom(LocationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayLocationContext ------------------------------------------------------------------

tree::TerminalNode* decafParser::ArrayLocationContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::ExpressionContext* decafParser::ArrayLocationContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::LocationContext* decafParser::ArrayLocationContext::location() {
  return getRuleContext<decafParser::LocationContext>(0);
}

decafParser::ArrayLocationContext::ArrayLocationContext(LocationContext *ctx) { copyFrom(ctx); }

void decafParser::ArrayLocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLocation(this);
}
void decafParser::ArrayLocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLocation(this);
}
//----------------- VarIdLocationContext ------------------------------------------------------------------

tree::TerminalNode* decafParser::VarIdLocationContext::ID() {
  return getToken(decafParser::ID, 0);
}

decafParser::LocationContext* decafParser::VarIdLocationContext::location() {
  return getRuleContext<decafParser::LocationContext>(0);
}

decafParser::VarIdLocationContext::VarIdLocationContext(LocationContext *ctx) { copyFrom(ctx); }

void decafParser::VarIdLocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarIdLocation(this);
}
void decafParser::VarIdLocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarIdLocation(this);
}
decafParser::LocationContext* decafParser::location() {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState());
  enterRule(_localctx, 24, decafParser::RuleLocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<decafParser::VarIdLocationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(192);
      match(decafParser::ID);
      setState(195);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(193);
        match(decafParser::T__20);
        setState(194);
        location();
        break;
      }

      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<decafParser::ArrayLocationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(197);
      match(decafParser::ID);
      setState(198);
      match(decafParser::T__5);
      setState(199);
      expression(0);
      setState(200);
      match(decafParser::T__6);
      setState(203);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(201);
        match(decafParser::T__20);
        setState(202);
        location();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

decafParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::ExpressionContext::getRuleIndex() const {
  return decafParser::RuleExpression;
}

void decafParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionLiteralContext ------------------------------------------------------------------

decafParser::LiteralContext* decafParser::ExpressionLiteralContext::literal() {
  return getRuleContext<decafParser::LiteralContext>(0);
}

decafParser::ExpressionLiteralContext::ExpressionLiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionLiteral(this);
}
void decafParser::ExpressionLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionLiteral(this);
}
//----------------- ExpressionNegationContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::ExpressionNegationContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::ExpressionNegationContext::ExpressionNegationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionNegationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionNegation(this);
}
void decafParser::ExpressionNegationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionNegation(this);
}
//----------------- ExpressionParentesisContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::ExpressionParentesisContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::ExpressionParentesisContext::ExpressionParentesisContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionParentesisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionParentesis(this);
}
void decafParser::ExpressionParentesisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionParentesis(this);
}
//----------------- ExpressionPairContext ------------------------------------------------------------------

std::vector<decafParser::ExpressionContext *> decafParser::ExpressionPairContext::expression() {
  return getRuleContexts<decafParser::ExpressionContext>();
}

decafParser::ExpressionContext* decafParser::ExpressionPairContext::expression(size_t i) {
  return getRuleContext<decafParser::ExpressionContext>(i);
}

decafParser::OpContext* decafParser::ExpressionPairContext::op() {
  return getRuleContext<decafParser::OpContext>(0);
}

decafParser::ExpressionPairContext::ExpressionPairContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionPairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionPair(this);
}
void decafParser::ExpressionPairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionPair(this);
}
//----------------- ExpressionLocationContext ------------------------------------------------------------------

decafParser::LocationContext* decafParser::ExpressionLocationContext::location() {
  return getRuleContext<decafParser::LocationContext>(0);
}

decafParser::ExpressionLocationContext::ExpressionLocationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionLocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionLocation(this);
}
void decafParser::ExpressionLocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionLocation(this);
}
//----------------- ExpressionMethodCallContext ------------------------------------------------------------------

decafParser::MethodCallContext* decafParser::ExpressionMethodCallContext::methodCall() {
  return getRuleContext<decafParser::MethodCallContext>(0);
}

decafParser::ExpressionMethodCallContext::ExpressionMethodCallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionMethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionMethodCall(this);
}
void decafParser::ExpressionMethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionMethodCall(this);
}
//----------------- ExpressionNegativContext ------------------------------------------------------------------

decafParser::ExpressionContext* decafParser::ExpressionNegativContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}

decafParser::ExpressionNegativContext::ExpressionNegativContext(ExpressionContext *ctx) { copyFrom(ctx); }

void decafParser::ExpressionNegativContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionNegativ(this);
}
void decafParser::ExpressionNegativContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionNegativ(this);
}

decafParser::ExpressionContext* decafParser::expression() {
   return expression(0);
}

decafParser::ExpressionContext* decafParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  decafParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  decafParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, decafParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExpressionLocationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(208);
      location();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExpressionMethodCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      methodCall();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExpressionLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(210);
      literal();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExpressionNegativContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(211);
      match(decafParser::T__21);
      setState(212);
      expression(3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExpressionNegationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(213);
      match(decafParser::T__22);
      setState(214);
      expression(2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExpressionParentesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(215);
      match(decafParser::T__12);
      setState(216);
      expression(0);
      setState(217);
      match(decafParser::T__14);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(227);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ExpressionPairContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(221);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(222);
        op();
        setState(223);
        expression(5); 
      }
      setState(229);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

decafParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

decafParser::ExpressionContext* decafParser::ArgContext::expression() {
  return getRuleContext<decafParser::ExpressionContext>(0);
}


size_t decafParser::ArgContext::getRuleIndex() const {
  return decafParser::RuleArg;
}

void decafParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void decafParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}

decafParser::ArgContext* decafParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 28, decafParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpContext ------------------------------------------------------------------

decafParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

decafParser::Arith_opContext* decafParser::OpContext::arith_op() {
  return getRuleContext<decafParser::Arith_opContext>(0);
}

decafParser::Rel_opContext* decafParser::OpContext::rel_op() {
  return getRuleContext<decafParser::Rel_opContext>(0);
}

decafParser::Eq_opContext* decafParser::OpContext::eq_op() {
  return getRuleContext<decafParser::Eq_opContext>(0);
}

decafParser::Cond_opContext* decafParser::OpContext::cond_op() {
  return getRuleContext<decafParser::Cond_opContext>(0);
}


size_t decafParser::OpContext::getRuleIndex() const {
  return decafParser::RuleOp;
}

void decafParser::OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp(this);
}

void decafParser::OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp(this);
}

decafParser::OpContext* decafParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 30, decafParser::RuleOp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case decafParser::T__21:
      case decafParser::T__23:
      case decafParser::T__24:
      case decafParser::T__25:
      case decafParser::T__26: {
        enterOuterAlt(_localctx, 1);
        setState(232);
        arith_op();
        break;
      }

      case decafParser::T__27:
      case decafParser::T__28:
      case decafParser::T__29:
      case decafParser::T__30: {
        enterOuterAlt(_localctx, 2);
        setState(233);
        rel_op();
        break;
      }

      case decafParser::T__31:
      case decafParser::T__32: {
        enterOuterAlt(_localctx, 3);
        setState(234);
        eq_op();
        break;
      }

      case decafParser::T__33:
      case decafParser::T__34: {
        enterOuterAlt(_localctx, 4);
        setState(235);
        cond_op();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_opContext ------------------------------------------------------------------

decafParser::Arith_opContext::Arith_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::Arith_opContext::getRuleIndex() const {
  return decafParser::RuleArith_op;
}

void decafParser::Arith_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_op(this);
}

void decafParser::Arith_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_op(this);
}

decafParser::Arith_opContext* decafParser::arith_op() {
  Arith_opContext *_localctx = _tracker.createInstance<Arith_opContext>(_ctx, getState());
  enterRule(_localctx, 32, decafParser::RuleArith_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__21)
      | (1ULL << decafParser::T__23)
      | (1ULL << decafParser::T__24)
      | (1ULL << decafParser::T__25)
      | (1ULL << decafParser::T__26))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_opContext ------------------------------------------------------------------

decafParser::Rel_opContext::Rel_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::Rel_opContext::getRuleIndex() const {
  return decafParser::RuleRel_op;
}

void decafParser::Rel_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_op(this);
}

void decafParser::Rel_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_op(this);
}

decafParser::Rel_opContext* decafParser::rel_op() {
  Rel_opContext *_localctx = _tracker.createInstance<Rel_opContext>(_ctx, getState());
  enterRule(_localctx, 34, decafParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << decafParser::T__27)
      | (1ULL << decafParser::T__28)
      | (1ULL << decafParser::T__29)
      | (1ULL << decafParser::T__30))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Eq_opContext ------------------------------------------------------------------

decafParser::Eq_opContext::Eq_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::Eq_opContext::getRuleIndex() const {
  return decafParser::RuleEq_op;
}

void decafParser::Eq_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq_op(this);
}

void decafParser::Eq_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq_op(this);
}

decafParser::Eq_opContext* decafParser::eq_op() {
  Eq_opContext *_localctx = _tracker.createInstance<Eq_opContext>(_ctx, getState());
  enterRule(_localctx, 36, decafParser::RuleEq_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    _la = _input->LA(1);
    if (!(_la == decafParser::T__31

    || _la == decafParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_opContext ------------------------------------------------------------------

decafParser::Cond_opContext::Cond_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::Cond_opContext::getRuleIndex() const {
  return decafParser::RuleCond_op;
}

void decafParser::Cond_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_op(this);
}

void decafParser::Cond_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_op(this);
}

decafParser::Cond_opContext* decafParser::cond_op() {
  Cond_opContext *_localctx = _tracker.createInstance<Cond_opContext>(_ctx, getState());
  enterRule(_localctx, 38, decafParser::RuleCond_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    _la = _input->LA(1);
    if (!(_la == decafParser::T__33

    || _la == decafParser::T__34)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

decafParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

decafParser::Int_literalContext* decafParser::LiteralContext::int_literal() {
  return getRuleContext<decafParser::Int_literalContext>(0);
}

decafParser::Char_literalContext* decafParser::LiteralContext::char_literal() {
  return getRuleContext<decafParser::Char_literalContext>(0);
}

decafParser::Bool_literalContext* decafParser::LiteralContext::bool_literal() {
  return getRuleContext<decafParser::Bool_literalContext>(0);
}


size_t decafParser::LiteralContext::getRuleIndex() const {
  return decafParser::RuleLiteral;
}

void decafParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void decafParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

decafParser::LiteralContext* decafParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 40, decafParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(249);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case decafParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(246);
        int_literal();
        break;
      }

      case decafParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(247);
        char_literal();
        break;
      }

      case decafParser::T__35:
      case decafParser::T__36: {
        enterOuterAlt(_localctx, 3);
        setState(248);
        bool_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Int_literalContext ------------------------------------------------------------------

decafParser::Int_literalContext::Int_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* decafParser::Int_literalContext::NUM() {
  return getToken(decafParser::NUM, 0);
}


size_t decafParser::Int_literalContext::getRuleIndex() const {
  return decafParser::RuleInt_literal;
}

void decafParser::Int_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt_literal(this);
}

void decafParser::Int_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt_literal(this);
}

decafParser::Int_literalContext* decafParser::int_literal() {
  Int_literalContext *_localctx = _tracker.createInstance<Int_literalContext>(_ctx, getState());
  enterRule(_localctx, 42, decafParser::RuleInt_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(decafParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Char_literalContext ------------------------------------------------------------------

decafParser::Char_literalContext::Char_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* decafParser::Char_literalContext::CHAR() {
  return getToken(decafParser::CHAR, 0);
}


size_t decafParser::Char_literalContext::getRuleIndex() const {
  return decafParser::RuleChar_literal;
}

void decafParser::Char_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChar_literal(this);
}

void decafParser::Char_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChar_literal(this);
}

decafParser::Char_literalContext* decafParser::char_literal() {
  Char_literalContext *_localctx = _tracker.createInstance<Char_literalContext>(_ctx, getState());
  enterRule(_localctx, 44, decafParser::RuleChar_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(decafParser::CHAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_literalContext ------------------------------------------------------------------

decafParser::Bool_literalContext::Bool_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t decafParser::Bool_literalContext::getRuleIndex() const {
  return decafParser::RuleBool_literal;
}

void decafParser::Bool_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_literal(this);
}

void decafParser::Bool_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<decafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_literal(this);
}

decafParser::Bool_literalContext* decafParser::bool_literal() {
  Bool_literalContext *_localctx = _tracker.createInstance<Bool_literalContext>(_ctx, getState());
  enterRule(_localctx, 46, decafParser::RuleBool_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _la = _input->LA(1);
    if (!(_la == decafParser::T__35

    || _la == decafParser::T__36)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool decafParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool decafParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> decafParser::_decisionToDFA;
atn::PredictionContextCache decafParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN decafParser::_atn;
std::vector<uint16_t> decafParser::_serializedATN;

std::vector<std::string> decafParser::_ruleNames = {
  "program", "declaration", "varDeclaration", "structDeclaration", "varType", 
  "methodDeclaration", "methodType", "parameter", "parameterType", "block", 
  "statement", "methodCall", "location", "expression", "arg", "op", "arith_op", 
  "rel_op", "eq_op", "cond_op", "literal", "int_literal", "char_literal", 
  "bool_literal"
};

std::vector<std::string> decafParser::_literalNames = {
  "", "'class'", "'Program'", "'{'", "'}'", "';'", "'['", "']'", "'struct'", 
  "'int'", "'char'", "'boolean'", "'void'", "'('", "','", "')'", "'if'", 
  "'else'", "'while'", "'return'", "'='", "'.'", "'-'", "'!'", "'+'", "'*'", 
  "'/'", "'%'", "'>'", "'<'", "'>='", "'<='", "'=='", "'!='", "'&&'", "'||'", 
  "'true'", "'false'"
};

std::vector<std::string> decafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "ID", "NUM", "CHAR", "WS"
};

dfa::Vocabulary decafParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> decafParser::_tokenNames;

decafParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0x104, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0x37, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3a, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x41, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4e, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x57, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0x5e, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x61, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x65, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6e, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x76, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0x79, 0xb, 0x7, 0x5, 0x7, 0x7b, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x8a, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0x91, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x94, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x9f, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa9, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0xb2, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb5, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xbc, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xbf, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0xc6, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0xce, 0xa, 0xe, 0x5, 0xe, 0xd0, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xde, 0xa, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xe4, 0xa, 0xf, 0xc, 
    0xf, 0xe, 0xf, 0xe7, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xef, 0xa, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xfc, 0xa, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x2, 
    0x3, 0x1c, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x2, 0x9, 0x3, 0x2, 0xb, 0xe, 0x3, 0x2, 0xb, 0xd, 0x4, 0x2, 
    0x18, 0x18, 0x1a, 0x1d, 0x3, 0x2, 0x1e, 0x21, 0x3, 0x2, 0x22, 0x23, 
    0x3, 0x2, 0x24, 0x25, 0x3, 0x2, 0x26, 0x27, 0x2, 0x113, 0x2, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x40, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x64, 0x3, 0x2, 0x2, 0x2, 0xa, 0x6d, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x20, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x101, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0x3, 
    0x2, 0x2, 0x33, 0x34, 0x7, 0x4, 0x2, 0x2, 0x34, 0x38, 0x7, 0x5, 0x2, 
    0x2, 0x35, 0x37, 0x5, 0x4, 0x3, 0x2, 0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x6, 0x2, 0x2, 0x3c, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x41, 0x5, 0x6, 0x4, 0x2, 0x3e, 0x41, 0x5, 0x8, 
    0x5, 0x2, 0x3f, 0x41, 0x5, 0xc, 0x7, 0x2, 0x40, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x5, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0xa, 0x6, 0x2, 0x43, 
    0x44, 0x7, 0x28, 0x2, 0x2, 0x44, 0x45, 0x7, 0x7, 0x2, 0x2, 0x45, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0xa, 0x6, 0x2, 0x47, 0x48, 0x7, 
    0x28, 0x2, 0x2, 0x48, 0x49, 0x7, 0x8, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x29, 
    0x2, 0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x7, 0x2, 
    0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0xa, 0x2, 0x2, 0x50, 0x51, 0x7, 0x28, 0x2, 0x2, 0x51, 0x55, 
    0x7, 0x5, 0x2, 0x2, 0x52, 0x54, 0x5, 0x6, 0x4, 0x2, 0x53, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x65, 0x7, 0x6, 0x2, 0x2, 
    0x59, 0x5a, 0x7, 0xa, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x28, 0x2, 0x2, 0x5b, 
    0x5f, 0x7, 0x5, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x6, 0x4, 0x2, 0x5d, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x6, 0x2, 
    0x2, 0x63, 0x65, 0x7, 0x7, 0x2, 0x2, 0x64, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x59, 0x3, 0x2, 0x2, 0x2, 0x65, 0x9, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x6e, 0x7, 0xb, 0x2, 0x2, 0x67, 0x6e, 0x7, 0xc, 0x2, 0x2, 0x68, 0x6e, 
    0x7, 0xd, 0x2, 0x2, 0x69, 0x6a, 0x7, 0xa, 0x2, 0x2, 0x6a, 0x6e, 0x7, 
    0x28, 0x2, 0x2, 0x6b, 0x6e, 0x5, 0x8, 0x5, 0x2, 0x6c, 0x6e, 0x7, 0xe, 
    0x2, 0x2, 0x6d, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0xe, 0x8, 0x2, 0x70, 0x71, 
    0x7, 0x28, 0x2, 0x2, 0x71, 0x7a, 0x7, 0xf, 0x2, 0x2, 0x72, 0x77, 0x5, 
    0x10, 0x9, 0x2, 0x73, 0x74, 0x7, 0x10, 0x2, 0x2, 0x74, 0x76, 0x5, 0x10, 
    0x9, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x11, 0x2, 0x2, 0x7d, 0x7e, 0x5, 
    0x14, 0xb, 0x2, 0x7e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x9, 0x2, 
    0x2, 0x2, 0x80, 0xf, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x5, 0x12, 0xa, 
    0x2, 0x82, 0x83, 0x7, 0x28, 0x2, 0x2, 0x83, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x85, 0x5, 0x12, 0xa, 0x2, 0x85, 0x86, 0x7, 0x28, 0x2, 0x2, 0x86, 
    0x87, 0x7, 0x8, 0x2, 0x2, 0x87, 0x88, 0x7, 0x9, 0x2, 0x2, 0x88, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x81, 0x3, 0x2, 0x2, 0x2, 0x89, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x9, 0x3, 
    0x2, 0x2, 0x8c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x92, 0x7, 0x5, 0x2, 
    0x2, 0x8e, 0x91, 0x5, 0x6, 0x4, 0x2, 0x8f, 0x91, 0x5, 0x16, 0xc, 0x2, 
    0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x95, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x6, 0x2, 0x2, 0x96, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x98, 0x7, 0x12, 0x2, 0x2, 0x98, 0x99, 0x7, 0xf, 0x2, 
    0x2, 0x99, 0x9a, 0x5, 0x1c, 0xf, 0x2, 0x9a, 0x9b, 0x7, 0x11, 0x2, 0x2, 
    0x9b, 0x9e, 0x5, 0x14, 0xb, 0x2, 0x9c, 0x9d, 0x7, 0x13, 0x2, 0x2, 0x9d, 
    0x9f, 0x5, 0x14, 0xb, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 
    0x14, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0xf, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x1c, 
    0xf, 0x2, 0xa3, 0xa4, 0x7, 0x11, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x14, 0xb, 
    0x2, 0xa5, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x7, 0x15, 0x2, 0x2, 
    0xa7, 0xa9, 0x5, 0x1c, 0xf, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xb5, 
    0x7, 0x7, 0x2, 0x2, 0xab, 0xb5, 0x5, 0x14, 0xb, 0x2, 0xac, 0xad, 0x5, 
    0x1a, 0xe, 0x2, 0xad, 0xae, 0x7, 0x16, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x1c, 
    0xf, 0x2, 0xaf, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x1c, 0xf, 
    0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x7, 0x7, 0x2, 0x2, 0xb4, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x7, 0x28, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0xf, 0x2, 
    0x2, 0xb8, 0xbd, 0x5, 0x1e, 0x10, 0x2, 0xb9, 0xba, 0x7, 0x10, 0x2, 0x2, 
    0xba, 0xbc, 0x5, 0x1e, 0x10, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x11, 0x2, 0x2, 0xc1, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc5, 0x7, 0x28, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x17, 0x2, 
    0x2, 0xc4, 0xc6, 0x5, 0x1a, 0xe, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc8, 0x7, 0x28, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x8, 0x2, 0x2, 0xc9, 0xca, 
    0x5, 0x1c, 0xf, 0x2, 0xca, 0xcd, 0x7, 0x9, 0x2, 0x2, 0xcb, 0xcc, 0x7, 
    0x17, 0x2, 0x2, 0xcc, 0xce, 0x5, 0x1a, 0xe, 0x2, 0xcd, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x8, 0xf, 0x1, 0x2, 0xd2, 
    0xde, 0x5, 0x1a, 0xe, 0x2, 0xd3, 0xde, 0x5, 0x18, 0xd, 0x2, 0xd4, 0xde, 
    0x5, 0x2a, 0x16, 0x2, 0xd5, 0xd6, 0x7, 0x18, 0x2, 0x2, 0xd6, 0xde, 0x5, 
    0x1c, 0xf, 0x5, 0xd7, 0xd8, 0x7, 0x19, 0x2, 0x2, 0xd8, 0xde, 0x5, 0x1c, 
    0xf, 0x4, 0xd9, 0xda, 0x7, 0xf, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x1c, 0xf, 
    0x2, 0xdb, 0xdc, 0x7, 0x11, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0xc, 0x6, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x20, 
    0x11, 0x2, 0xe1, 0xe2, 0x5, 0x1c, 0xf, 0x7, 0xe2, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 
    0x5, 0x1c, 0xf, 0x2, 0xe9, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xea, 0xef, 0x5, 
    0x22, 0x12, 0x2, 0xeb, 0xef, 0x5, 0x24, 0x13, 0x2, 0xec, 0xef, 0x5, 
    0x26, 0x14, 0x2, 0xed, 0xef, 0x5, 0x28, 0x15, 0x2, 0xee, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xee, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xf1, 0x9, 0x4, 0x2, 0x2, 0xf1, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xf3, 0x9, 0x5, 0x2, 0x2, 0xf3, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf5, 0x9, 0x6, 0x2, 0x2, 0xf5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 
    0x9, 0x7, 0x2, 0x2, 0xf7, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfc, 0x5, 
    0x2c, 0x17, 0x2, 0xf9, 0xfc, 0x5, 0x2e, 0x18, 0x2, 0xfa, 0xfc, 0x5, 
    0x30, 0x19, 0x2, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfe, 0x7, 0x29, 0x2, 0x2, 0xfe, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0x2a, 0x2, 0x2, 0x100, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0x9, 0x8, 0x2, 0x2, 0x102, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x38, 
    0x40, 0x4d, 0x55, 0x5f, 0x64, 0x6d, 0x77, 0x7a, 0x89, 0x90, 0x92, 0x9e, 
    0xa8, 0xb1, 0xb4, 0xbd, 0xc5, 0xcd, 0xcf, 0xdd, 0xe5, 0xee, 0xfb, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

decafParser::Initializer decafParser::_init;
