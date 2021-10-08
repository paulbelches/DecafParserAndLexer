// Generated from /home/paul/Documents/compis/compiler/decaf.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class decafParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, ID=38, NUM=39, 
		CHAR=40, WS=41, COMMENTS=42;
	public static final int
		RULE_program = 0, RULE_declaration = 1, RULE_varDeclaration = 2, RULE_structDeclaration = 3, 
		RULE_varType = 4, RULE_methodDeclaration = 5, RULE_methodType = 6, RULE_parameter = 7, 
		RULE_parameterType = 8, RULE_block = 9, RULE_statement = 10, RULE_methodCall = 11, 
		RULE_location = 12, RULE_expression = 13, RULE_arg = 14, RULE_literal = 15, 
		RULE_int_literal = 16, RULE_char_literal = 17, RULE_bool_literal = 18;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "declaration", "varDeclaration", "structDeclaration", "varType", 
			"methodDeclaration", "methodType", "parameter", "parameterType", "block", 
			"statement", "methodCall", "location", "expression", "arg", "literal", 
			"int_literal", "char_literal", "bool_literal"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'class'", "'Program'", "'{'", "'}'", "';'", "'['", "']'", "'struct'", 
			"'int'", "'char'", "'boolean'", "'void'", "'('", "','", "')'", "'if'", 
			"'else'", "'while'", "'return'", "'='", "'.'", "'*'", "'/'", "'%'", "'+'", 
			"'-'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'", 
			"'!'", "'true'", "'false'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "ID", "NUM", "CHAR", "WS", "COMMENTS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "decaf.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public decafParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(38);
			match(T__0);
			setState(39);
			match(T__1);
			setState(40);
			match(T__2);
			setState(44);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11))) != 0)) {
				{
				{
				setState(41);
				declaration();
				}
				}
				setState(46);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(47);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public VarDeclarationContext varDeclaration() {
			return getRuleContext(VarDeclarationContext.class,0);
		}
		public StructDeclarationContext structDeclaration() {
			return getRuleContext(StructDeclarationContext.class,0);
		}
		public MethodDeclarationContext methodDeclaration() {
			return getRuleContext(MethodDeclarationContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_declaration);
		try {
			setState(52);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(49);
				varDeclaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(50);
				structDeclaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(51);
				methodDeclaration();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarDeclarationContext extends ParserRuleContext {
		public VarDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDeclaration; }
	 
		public VarDeclarationContext() { }
		public void copyFrom(VarDeclarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArrayDeclarationContext extends VarDeclarationContext {
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public TerminalNode NUM() { return getToken(decafParser.NUM, 0); }
		public ArrayDeclarationContext(VarDeclarationContext ctx) { copyFrom(ctx); }
	}
	public static class VariableDeclarationContext extends VarDeclarationContext {
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public VariableDeclarationContext(VarDeclarationContext ctx) { copyFrom(ctx); }
	}

	public final VarDeclarationContext varDeclaration() throws RecognitionException {
		VarDeclarationContext _localctx = new VarDeclarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_varDeclaration);
		try {
			setState(65);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				_localctx = new VariableDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(54);
				varType();
				setState(55);
				match(ID);
				setState(56);
				match(T__4);
				}
				break;
			case 2:
				_localctx = new ArrayDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(58);
				varType();
				setState(59);
				match(ID);
				setState(60);
				match(T__5);
				setState(61);
				match(NUM);
				setState(62);
				match(T__6);
				setState(63);
				match(T__4);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructDeclarationContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public List<VarDeclarationContext> varDeclaration() {
			return getRuleContexts(VarDeclarationContext.class);
		}
		public VarDeclarationContext varDeclaration(int i) {
			return getRuleContext(VarDeclarationContext.class,i);
		}
		public StructDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structDeclaration; }
	}

	public final StructDeclarationContext structDeclaration() throws RecognitionException {
		StructDeclarationContext _localctx = new StructDeclarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_structDeclaration);
		int _la;
		try {
			setState(88);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(67);
				match(T__7);
				setState(68);
				match(ID);
				setState(69);
				match(T__2);
				setState(73);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11))) != 0)) {
					{
					{
					setState(70);
					varDeclaration();
					}
					}
					setState(75);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(76);
				match(T__3);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(77);
				match(T__7);
				setState(78);
				match(ID);
				setState(79);
				match(T__2);
				setState(83);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11))) != 0)) {
					{
					{
					setState(80);
					varDeclaration();
					}
					}
					setState(85);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(86);
				match(T__3);
				setState(87);
				match(T__4);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarTypeContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public StructDeclarationContext structDeclaration() {
			return getRuleContext(StructDeclarationContext.class,0);
		}
		public VarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varType; }
	}

	public final VarTypeContext varType() throws RecognitionException {
		VarTypeContext _localctx = new VarTypeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_varType);
		try {
			setState(97);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(90);
				match(T__8);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(91);
				match(T__9);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(92);
				match(T__10);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(93);
				match(T__7);
				setState(94);
				match(ID);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(95);
				structDeclaration();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(96);
				match(T__11);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MethodDeclarationContext extends ParserRuleContext {
		public MethodTypeContext methodType() {
			return getRuleContext(MethodTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public MethodDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodDeclaration; }
	}

	public final MethodDeclarationContext methodDeclaration() throws RecognitionException {
		MethodDeclarationContext _localctx = new MethodDeclarationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_methodDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			methodType();
			setState(100);
			match(ID);
			setState(101);
			match(T__12);
			setState(110);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__9) | (1L << T__10))) != 0)) {
				{
				setState(102);
				parameter();
				setState(107);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__13) {
					{
					{
					setState(103);
					match(T__13);
					setState(104);
					parameter();
					}
					}
					setState(109);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(112);
			match(T__14);
			setState(113);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MethodTypeContext extends ParserRuleContext {
		public MethodTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodType; }
	}

	public final MethodTypeContext methodType() throws RecognitionException {
		MethodTypeContext _localctx = new MethodTypeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_methodType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterContext extends ParserRuleContext {
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	 
		public ParameterContext() { }
		public void copyFrom(ParameterContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ParameterArrayContext extends ParameterContext {
		public ParameterTypeContext parameterType() {
			return getRuleContext(ParameterTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public ParameterArrayContext(ParameterContext ctx) { copyFrom(ctx); }
	}
	public static class ParameterVariableContext extends ParameterContext {
		public ParameterTypeContext parameterType() {
			return getRuleContext(ParameterTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public ParameterVariableContext(ParameterContext ctx) { copyFrom(ctx); }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_parameter);
		try {
			setState(125);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				_localctx = new ParameterVariableContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(117);
				parameterType();
				setState(118);
				match(ID);
				}
				break;
			case 2:
				_localctx = new ParameterArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(120);
				parameterType();
				setState(121);
				match(ID);
				setState(122);
				match(T__5);
				setState(123);
				match(T__6);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterTypeContext extends ParserRuleContext {
		public ParameterTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterType; }
	}

	public final ParameterTypeContext parameterType() throws RecognitionException {
		ParameterTypeContext _localctx = new ParameterTypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_parameterType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__9) | (1L << T__10))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public List<VarDeclarationContext> varDeclaration() {
			return getRuleContexts(VarDeclarationContext.class);
		}
		public VarDeclarationContext varDeclaration(int i) {
			return getRuleContext(VarDeclarationContext.class,i);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(T__2);
			setState(134);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__4) | (1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << T__15) | (1L << T__17) | (1L << T__18) | (1L << T__25) | (1L << T__34) | (1L << T__35) | (1L << T__36) | (1L << ID) | (1L << NUM) | (1L << CHAR))) != 0)) {
				{
				setState(132);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__7:
				case T__8:
				case T__9:
				case T__10:
				case T__11:
					{
					setState(130);
					varDeclaration();
					}
					break;
				case T__2:
				case T__4:
				case T__12:
				case T__15:
				case T__17:
				case T__18:
				case T__25:
				case T__34:
				case T__35:
				case T__36:
				case ID:
				case NUM:
				case CHAR:
					{
					setState(131);
					statement();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(136);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(137);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class WhileStatementContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class BlockStatementContext extends StatementContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public BlockStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ExpresionStatementContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpresionStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ReturnStatementContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ReturnStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class AsignationStatementContext extends StatementContext {
		public LocationContext location() {
			return getRuleContext(LocationContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AsignationStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class IfStatementContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<BlockContext> block() {
			return getRuleContexts(BlockContext.class);
		}
		public BlockContext block(int i) {
			return getRuleContext(BlockContext.class,i);
		}
		public IfStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_statement);
		int _la;
		try {
			setState(168);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				_localctx = new IfStatementContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(139);
				match(T__15);
				setState(140);
				match(T__12);
				setState(141);
				expression(0);
				setState(142);
				match(T__14);
				setState(143);
				block();
				setState(146);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__16) {
					{
					setState(144);
					match(T__16);
					setState(145);
					block();
					}
				}

				}
				break;
			case 2:
				_localctx = new WhileStatementContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(148);
				match(T__17);
				setState(149);
				match(T__12);
				setState(150);
				expression(0);
				setState(151);
				match(T__14);
				setState(152);
				block();
				}
				break;
			case 3:
				_localctx = new ReturnStatementContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(154);
				match(T__18);
				setState(156);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__25) | (1L << T__34) | (1L << T__35) | (1L << T__36) | (1L << ID) | (1L << NUM) | (1L << CHAR))) != 0)) {
					{
					setState(155);
					expression(0);
					}
				}

				setState(158);
				match(T__4);
				}
				break;
			case 4:
				_localctx = new BlockStatementContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(159);
				block();
				}
				break;
			case 5:
				_localctx = new AsignationStatementContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(160);
				location();
				setState(161);
				match(T__19);
				setState(162);
				expression(0);
				}
				break;
			case 6:
				_localctx = new ExpresionStatementContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(165);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__25) | (1L << T__34) | (1L << T__35) | (1L << T__36) | (1L << ID) | (1L << NUM) | (1L << CHAR))) != 0)) {
					{
					setState(164);
					expression(0);
					}
				}

				setState(167);
				match(T__4);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MethodCallContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public List<ArgContext> arg() {
			return getRuleContexts(ArgContext.class);
		}
		public ArgContext arg(int i) {
			return getRuleContext(ArgContext.class,i);
		}
		public MethodCallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodCall; }
	}

	public final MethodCallContext methodCall() throws RecognitionException {
		MethodCallContext _localctx = new MethodCallContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_methodCall);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			match(ID);
			setState(171);
			match(T__12);
			setState(180);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__25) | (1L << T__34) | (1L << T__35) | (1L << T__36) | (1L << ID) | (1L << NUM) | (1L << CHAR))) != 0)) {
				{
				setState(172);
				arg();
				setState(177);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__13) {
					{
					{
					setState(173);
					match(T__13);
					setState(174);
					arg();
					}
					}
					setState(179);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(182);
			match(T__14);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LocationContext extends ParserRuleContext {
		public LocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_location; }
	 
		public LocationContext() { }
		public void copyFrom(LocationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArrayLocationContext extends LocationContext {
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public LocationContext location() {
			return getRuleContext(LocationContext.class,0);
		}
		public ArrayLocationContext(LocationContext ctx) { copyFrom(ctx); }
	}
	public static class VarIdLocationContext extends LocationContext {
		public TerminalNode ID() { return getToken(decafParser.ID, 0); }
		public LocationContext location() {
			return getRuleContext(LocationContext.class,0);
		}
		public VarIdLocationContext(LocationContext ctx) { copyFrom(ctx); }
	}

	public final LocationContext location() throws RecognitionException {
		LocationContext _localctx = new LocationContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_location);
		try {
			setState(197);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				_localctx = new VarIdLocationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(184);
				match(ID);
				setState(187);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
				case 1:
					{
					setState(185);
					match(T__20);
					setState(186);
					location();
					}
					break;
				}
				}
				break;
			case 2:
				_localctx = new ArrayLocationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(189);
				match(ID);
				setState(190);
				match(T__5);
				setState(191);
				expression(0);
				setState(192);
				match(T__6);
				setState(195);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(193);
					match(T__20);
					setState(194);
					location();
					}
					break;
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ExpressionLiteralContext extends ExpressionContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public ExpressionLiteralContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionParentesisContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionParentesisContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionNegationContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionNegationContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionPairArithContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionPairArithContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionPairRelContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionPairRelContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionLocationContext extends ExpressionContext {
		public LocationContext location() {
			return getRuleContext(LocationContext.class,0);
		}
		public ExpressionLocationContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionPairEqContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionPairEqContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionPairCondContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionPairCondContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionMethodCallContext extends ExpressionContext {
		public MethodCallContext methodCall() {
			return getRuleContext(MethodCallContext.class,0);
		}
		public ExpressionMethodCallContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionPairArithSimpleContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionPairArithSimpleContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ExpressionNegativContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionNegativContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(211);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				{
				_localctx = new ExpressionMethodCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(200);
				methodCall();
				}
				break;
			case 2:
				{
				_localctx = new ExpressionParentesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(201);
				match(T__12);
				setState(202);
				expression(0);
				setState(203);
				match(T__14);
				}
				break;
			case 3:
				{
				_localctx = new ExpressionLocationContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(205);
				location();
				}
				break;
			case 4:
				{
				_localctx = new ExpressionLiteralContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(206);
				literal();
				}
				break;
			case 5:
				{
				_localctx = new ExpressionNegativContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(207);
				match(T__25);
				setState(208);
				expression(2);
				}
				break;
			case 6:
				{
				_localctx = new ExpressionNegationContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(209);
				match(T__34);
				setState(210);
				expression(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(230);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(228);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionPairArithContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(213);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(214);
						((ExpressionPairArithContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__21) | (1L << T__22) | (1L << T__23))) != 0)) ) {
							((ExpressionPairArithContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(215);
						expression(10);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionPairArithSimpleContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(216);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(217);
						((ExpressionPairArithSimpleContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__24 || _la==T__25) ) {
							((ExpressionPairArithSimpleContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(218);
						expression(9);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionPairRelContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(219);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(220);
						((ExpressionPairRelContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__26) | (1L << T__27) | (1L << T__28) | (1L << T__29))) != 0)) ) {
							((ExpressionPairRelContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(221);
						expression(8);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionPairEqContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(222);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(223);
						((ExpressionPairEqContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__30 || _la==T__31) ) {
							((ExpressionPairEqContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(224);
						expression(7);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionPairCondContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(225);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(226);
						((ExpressionPairCondContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__32 || _la==T__33) ) {
							((ExpressionPairCondContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(227);
						expression(6);
						}
						break;
					}
					} 
				}
				setState(232);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ArgContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ArgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arg; }
	}

	public final ArgContext arg() throws RecognitionException {
		ArgContext _localctx = new ArgContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_arg);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public Int_literalContext int_literal() {
			return getRuleContext(Int_literalContext.class,0);
		}
		public Char_literalContext char_literal() {
			return getRuleContext(Char_literalContext.class,0);
		}
		public Bool_literalContext bool_literal() {
			return getRuleContext(Bool_literalContext.class,0);
		}
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_literal);
		try {
			setState(238);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM:
				enterOuterAlt(_localctx, 1);
				{
				setState(235);
				int_literal();
				}
				break;
			case CHAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(236);
				char_literal();
				}
				break;
			case T__35:
			case T__36:
				enterOuterAlt(_localctx, 3);
				{
				setState(237);
				bool_literal();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Int_literalContext extends ParserRuleContext {
		public TerminalNode NUM() { return getToken(decafParser.NUM, 0); }
		public Int_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_int_literal; }
	}

	public final Int_literalContext int_literal() throws RecognitionException {
		Int_literalContext _localctx = new Int_literalContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_int_literal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(240);
			match(NUM);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Char_literalContext extends ParserRuleContext {
		public TerminalNode CHAR() { return getToken(decafParser.CHAR, 0); }
		public Char_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_char_literal; }
	}

	public final Char_literalContext char_literal() throws RecognitionException {
		Char_literalContext _localctx = new Char_literalContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_char_literal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(242);
			match(CHAR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Bool_literalContext extends ParserRuleContext {
		public Bool_literalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bool_literal; }
	}

	public final Bool_literalContext bool_literal() throws RecognitionException {
		Bool_literalContext _localctx = new Bool_literalContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_bool_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(244);
			_la = _input.LA(1);
			if ( !(_la==T__35 || _la==T__36) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 13:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 9);
		case 1:
			return precpred(_ctx, 8);
		case 2:
			return precpred(_ctx, 7);
		case 3:
			return precpred(_ctx, 6);
		case 4:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3,\u00f9\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\3\2\3\2\3\2\3\2\7\2-\n\2\f\2\16\2\60\13\2\3\2\3\2"+
		"\3\3\3\3\3\3\5\3\67\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5"+
		"\4D\n\4\3\5\3\5\3\5\3\5\7\5J\n\5\f\5\16\5M\13\5\3\5\3\5\3\5\3\5\3\5\7"+
		"\5T\n\5\f\5\16\5W\13\5\3\5\3\5\5\5[\n\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5"+
		"\6d\n\6\3\7\3\7\3\7\3\7\3\7\3\7\7\7l\n\7\f\7\16\7o\13\7\5\7q\n\7\3\7\3"+
		"\7\3\7\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u0080\n\t\3\n\3\n\3"+
		"\13\3\13\3\13\7\13\u0087\n\13\f\13\16\13\u008a\13\13\3\13\3\13\3\f\3\f"+
		"\3\f\3\f\3\f\3\f\3\f\5\f\u0095\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\f"+
		"\u009f\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\f\u00a8\n\f\3\f\5\f\u00ab\n\f"+
		"\3\r\3\r\3\r\3\r\3\r\7\r\u00b2\n\r\f\r\16\r\u00b5\13\r\5\r\u00b7\n\r\3"+
		"\r\3\r\3\16\3\16\3\16\5\16\u00be\n\16\3\16\3\16\3\16\3\16\3\16\3\16\5"+
		"\16\u00c6\n\16\5\16\u00c8\n\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17"+
		"\3\17\3\17\3\17\3\17\5\17\u00d6\n\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17"+
		"\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\7\17\u00e7\n\17\f\17\16\17\u00ea"+
		"\13\17\3\20\3\20\3\21\3\21\3\21\5\21\u00f1\n\21\3\22\3\22\3\23\3\23\3"+
		"\24\3\24\3\24\2\3\34\25\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&\2"+
		"\n\3\2\13\16\3\2\13\r\3\2\30\32\3\2\33\34\3\2\35 \3\2!\"\3\2#$\3\2&\'"+
		"\2\u010f\2(\3\2\2\2\4\66\3\2\2\2\6C\3\2\2\2\bZ\3\2\2\2\nc\3\2\2\2\fe\3"+
		"\2\2\2\16u\3\2\2\2\20\177\3\2\2\2\22\u0081\3\2\2\2\24\u0083\3\2\2\2\26"+
		"\u00aa\3\2\2\2\30\u00ac\3\2\2\2\32\u00c7\3\2\2\2\34\u00d5\3\2\2\2\36\u00eb"+
		"\3\2\2\2 \u00f0\3\2\2\2\"\u00f2\3\2\2\2$\u00f4\3\2\2\2&\u00f6\3\2\2\2"+
		"()\7\3\2\2)*\7\4\2\2*.\7\5\2\2+-\5\4\3\2,+\3\2\2\2-\60\3\2\2\2.,\3\2\2"+
		"\2./\3\2\2\2/\61\3\2\2\2\60.\3\2\2\2\61\62\7\6\2\2\62\3\3\2\2\2\63\67"+
		"\5\6\4\2\64\67\5\b\5\2\65\67\5\f\7\2\66\63\3\2\2\2\66\64\3\2\2\2\66\65"+
		"\3\2\2\2\67\5\3\2\2\289\5\n\6\29:\7(\2\2:;\7\7\2\2;D\3\2\2\2<=\5\n\6\2"+
		"=>\7(\2\2>?\7\b\2\2?@\7)\2\2@A\7\t\2\2AB\7\7\2\2BD\3\2\2\2C8\3\2\2\2C"+
		"<\3\2\2\2D\7\3\2\2\2EF\7\n\2\2FG\7(\2\2GK\7\5\2\2HJ\5\6\4\2IH\3\2\2\2"+
		"JM\3\2\2\2KI\3\2\2\2KL\3\2\2\2LN\3\2\2\2MK\3\2\2\2N[\7\6\2\2OP\7\n\2\2"+
		"PQ\7(\2\2QU\7\5\2\2RT\5\6\4\2SR\3\2\2\2TW\3\2\2\2US\3\2\2\2UV\3\2\2\2"+
		"VX\3\2\2\2WU\3\2\2\2XY\7\6\2\2Y[\7\7\2\2ZE\3\2\2\2ZO\3\2\2\2[\t\3\2\2"+
		"\2\\d\7\13\2\2]d\7\f\2\2^d\7\r\2\2_`\7\n\2\2`d\7(\2\2ad\5\b\5\2bd\7\16"+
		"\2\2c\\\3\2\2\2c]\3\2\2\2c^\3\2\2\2c_\3\2\2\2ca\3\2\2\2cb\3\2\2\2d\13"+
		"\3\2\2\2ef\5\16\b\2fg\7(\2\2gp\7\17\2\2hm\5\20\t\2ij\7\20\2\2jl\5\20\t"+
		"\2ki\3\2\2\2lo\3\2\2\2mk\3\2\2\2mn\3\2\2\2nq\3\2\2\2om\3\2\2\2ph\3\2\2"+
		"\2pq\3\2\2\2qr\3\2\2\2rs\7\21\2\2st\5\24\13\2t\r\3\2\2\2uv\t\2\2\2v\17"+
		"\3\2\2\2wx\5\22\n\2xy\7(\2\2y\u0080\3\2\2\2z{\5\22\n\2{|\7(\2\2|}\7\b"+
		"\2\2}~\7\t\2\2~\u0080\3\2\2\2\177w\3\2\2\2\177z\3\2\2\2\u0080\21\3\2\2"+
		"\2\u0081\u0082\t\3\2\2\u0082\23\3\2\2\2\u0083\u0088\7\5\2\2\u0084\u0087"+
		"\5\6\4\2\u0085\u0087\5\26\f\2\u0086\u0084\3\2\2\2\u0086\u0085\3\2\2\2"+
		"\u0087\u008a\3\2\2\2\u0088\u0086\3\2\2\2\u0088\u0089\3\2\2\2\u0089\u008b"+
		"\3\2\2\2\u008a\u0088\3\2\2\2\u008b\u008c\7\6\2\2\u008c\25\3\2\2\2\u008d"+
		"\u008e\7\22\2\2\u008e\u008f\7\17\2\2\u008f\u0090\5\34\17\2\u0090\u0091"+
		"\7\21\2\2\u0091\u0094\5\24\13\2\u0092\u0093\7\23\2\2\u0093\u0095\5\24"+
		"\13\2\u0094\u0092\3\2\2\2\u0094\u0095\3\2\2\2\u0095\u00ab\3\2\2\2\u0096"+
		"\u0097\7\24\2\2\u0097\u0098\7\17\2\2\u0098\u0099\5\34\17\2\u0099\u009a"+
		"\7\21\2\2\u009a\u009b\5\24\13\2\u009b\u00ab\3\2\2\2\u009c\u009e\7\25\2"+
		"\2\u009d\u009f\5\34\17\2\u009e\u009d\3\2\2\2\u009e\u009f\3\2\2\2\u009f"+
		"\u00a0\3\2\2\2\u00a0\u00ab\7\7\2\2\u00a1\u00ab\5\24\13\2\u00a2\u00a3\5"+
		"\32\16\2\u00a3\u00a4\7\26\2\2\u00a4\u00a5\5\34\17\2\u00a5\u00ab\3\2\2"+
		"\2\u00a6\u00a8\5\34\17\2\u00a7\u00a6\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8"+
		"\u00a9\3\2\2\2\u00a9\u00ab\7\7\2\2\u00aa\u008d\3\2\2\2\u00aa\u0096\3\2"+
		"\2\2\u00aa\u009c\3\2\2\2\u00aa\u00a1\3\2\2\2\u00aa\u00a2\3\2\2\2\u00aa"+
		"\u00a7\3\2\2\2\u00ab\27\3\2\2\2\u00ac\u00ad\7(\2\2\u00ad\u00b6\7\17\2"+
		"\2\u00ae\u00b3\5\36\20\2\u00af\u00b0\7\20\2\2\u00b0\u00b2\5\36\20\2\u00b1"+
		"\u00af\3\2\2\2\u00b2\u00b5\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b3\u00b4\3\2"+
		"\2\2\u00b4\u00b7\3\2\2\2\u00b5\u00b3\3\2\2\2\u00b6\u00ae\3\2\2\2\u00b6"+
		"\u00b7\3\2\2\2\u00b7\u00b8\3\2\2\2\u00b8\u00b9\7\21\2\2\u00b9\31\3\2\2"+
		"\2\u00ba\u00bd\7(\2\2\u00bb\u00bc\7\27\2\2\u00bc\u00be\5\32\16\2\u00bd"+
		"\u00bb\3\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00c8\3\2\2\2\u00bf\u00c0\7("+
		"\2\2\u00c0\u00c1\7\b\2\2\u00c1\u00c2\5\34\17\2\u00c2\u00c5\7\t\2\2\u00c3"+
		"\u00c4\7\27\2\2\u00c4\u00c6\5\32\16\2\u00c5\u00c3\3\2\2\2\u00c5\u00c6"+
		"\3\2\2\2\u00c6\u00c8\3\2\2\2\u00c7\u00ba\3\2\2\2\u00c7\u00bf\3\2\2\2\u00c8"+
		"\33\3\2\2\2\u00c9\u00ca\b\17\1\2\u00ca\u00d6\5\30\r\2\u00cb\u00cc\7\17"+
		"\2\2\u00cc\u00cd\5\34\17\2\u00cd\u00ce\7\21\2\2\u00ce\u00d6\3\2\2\2\u00cf"+
		"\u00d6\5\32\16\2\u00d0\u00d6\5 \21\2\u00d1\u00d2\7\34\2\2\u00d2\u00d6"+
		"\5\34\17\4\u00d3\u00d4\7%\2\2\u00d4\u00d6\5\34\17\3\u00d5\u00c9\3\2\2"+
		"\2\u00d5\u00cb\3\2\2\2\u00d5\u00cf\3\2\2\2\u00d5\u00d0\3\2\2\2\u00d5\u00d1"+
		"\3\2\2\2\u00d5\u00d3\3\2\2\2\u00d6\u00e8\3\2\2\2\u00d7\u00d8\f\13\2\2"+
		"\u00d8\u00d9\t\4\2\2\u00d9\u00e7\5\34\17\f\u00da\u00db\f\n\2\2\u00db\u00dc"+
		"\t\5\2\2\u00dc\u00e7\5\34\17\13\u00dd\u00de\f\t\2\2\u00de\u00df\t\6\2"+
		"\2\u00df\u00e7\5\34\17\n\u00e0\u00e1\f\b\2\2\u00e1\u00e2\t\7\2\2\u00e2"+
		"\u00e7\5\34\17\t\u00e3\u00e4\f\7\2\2\u00e4\u00e5\t\b\2\2\u00e5\u00e7\5"+
		"\34\17\b\u00e6\u00d7\3\2\2\2\u00e6\u00da\3\2\2\2\u00e6\u00dd\3\2\2\2\u00e6"+
		"\u00e0\3\2\2\2\u00e6\u00e3\3\2\2\2\u00e7\u00ea\3\2\2\2\u00e8\u00e6\3\2"+
		"\2\2\u00e8\u00e9\3\2\2\2\u00e9\35\3\2\2\2\u00ea\u00e8\3\2\2\2\u00eb\u00ec"+
		"\5\34\17\2\u00ec\37\3\2\2\2\u00ed\u00f1\5\"\22\2\u00ee\u00f1\5$\23\2\u00ef"+
		"\u00f1\5&\24\2\u00f0\u00ed\3\2\2\2\u00f0\u00ee\3\2\2\2\u00f0\u00ef\3\2"+
		"\2\2\u00f1!\3\2\2\2\u00f2\u00f3\7)\2\2\u00f3#\3\2\2\2\u00f4\u00f5\7*\2"+
		"\2\u00f5%\3\2\2\2\u00f6\u00f7\t\t\2\2\u00f7\'\3\2\2\2\33.\66CKUZcmp\177"+
		"\u0086\u0088\u0094\u009e\u00a7\u00aa\u00b3\u00b6\u00bd\u00c5\u00c7\u00d5"+
		"\u00e6\u00e8\u00f0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}