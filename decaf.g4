grammar decaf;

/*------------------------------------------------------------------
 * LEXER RULES 
 *------------------------------------------------------------------*/
 
ID : LETTER (LETTER|DIGIT)* ;

NUM : DIGIT(DIGIT)* ;

CHAR : '\''  LETTER  '\'' ;
 
fragment DIGIT : '0'..'9' ;

fragment LETTER : ('a'..'z'|'A'..'Z'|'_') ;

WS
   : [ \t\n\r] + -> skip
   ;


/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/
 
program : 'class' 'Program' '{' (declaration)* '}' 
	;


declaration
	: varDeclaration 
	| structDeclaration
	| methodDeclaration
	;
/////////	
varDeclaration 
	: varType  ID  ';' 				#variableDeclaration
	| varType  ID  '[' NUM ']' ';'  #arrayDeclaration
	;

structDeclaration
	: 'struct' ID '{' (varDeclaration)* '}'
	;
				
varType
	: 'int'
	| 'char'	
	| 'boolean' 
	| 'struct' ID
	| structDeclaration
	| 'void'
	;
/////////
methodDeclaration
	: methodType ID '(' (parameter (',' parameter)*)? ')' block
	;

///////////
methodType
	: 'int'
	| 'char'	
	| 'boolean' 
	| 'void'
	;
/////////
parameter 
	: parameterType ID			#parameterVariable
	| parameterType ID '[' ']'	#parameterArray
	;

parameterType
	: 'int'
	| 'char'	
	| 'boolean' 
	;

block
	: '{' (varDeclaration | statement)* '}'
	;

statement
	: 'if' '(' expression ')' block ('else' block )?#ifStatement //check if expression is bool
	| 'while' '(' expression ')' block 				#whileStatement //check if expression is bool
	| 'return' (expression)? ';' 					#ReturnStatement // set return type (in method existe compare types)
	//| methodCall ';' 
	| block											#blockStatement
	| location '=' expression 						#asignationStatement//cheack if types are the same
	| (expression)? ';' 							#expresionStatement
	;

/*+++++++++++*/
methodCall
	: ID '(' (arg) (',' arg)*')' //set arg types,  check if exist, set return type
	;

location
	: ID									#varIdLocation //check if exist and set type
	| ID ('.' location)?					#structLocation //check if exist, check if location exist and set type
	| ID '[' expression ']' ('.' location)?	#arrayLocation //check if exist, if its array and set type
	;

//Array verification
///////////
expression
	: location					#expressionLocation ///
	| methodCall				#expressionMethodCall ///
	| literal					#expressionLiteral ////
	| expression op expression	#expressionPair ////
	| '-' expression			#expressionNegativ ////
	| '!' expression			#expressionNegation ////
	| '(' expression ')'		#expressionParentesis ////
	;

/*+++++++++++*/
arg	
	: expression
	;
/*+++++++++++*/  ///add vector check
op
	: arith_op
	| rel_op
	| eq_op
	| cond_op
	;
/*+++++++++++*/
arith_op
	: '+'
	| '-'
	| '*'
	| '/'
	| '%'
	;
/*+++++++++++*/
rel_op
	: '>'
	| '<'
	| '>='
	| '<='
	;
/*+++++++++++*/
eq_op
	: '=='
	| '!='
	;
/*+++++++++++*/
cond_op
	: '&&'
	| '||'
	;
/*+++++++++++*/
literal
	: int_literal
	| char_literal
	| bool_literal
	;
/*+++++++++++*/
int_literal
	: NUM
	;
/*+++++++++++*/
char_literal
	: CHAR
	;
/*+++++++++++*/
bool_literal
	: 'true'
	| 'false'
	;
