/* front.c - a lexical analyzer system for simple
arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define MOD_OP 25
#define EQUAL_OP 26
#define LEFT_PAREN 27
#define RIGHT_PAREN 28

/* 32 keywords */
/* Keywords */
#define KW_IF 50       // if
#define KW_ELSE 51     // else
#define KW_WHILE 52    // while
#define KW_SWITCH 53     // switch 
#define KW_RETURN 54  // return
#define KW_CASE 55 // case
#define KW_DEFAULT 56 // default
#define KW-WHILE 57 // while
#define KW_DO 58 // do
#define KW_FOR 59 // for
#define KW_INT 60 // int
#define KW_CHAR 61 // char
#define KW_FLOAT 62 // float
#define KW_LONG  63 // long
#define KW_DOUBLE 64 // double
#define KW_LONG 65 // long
#define KW_SHORT 66 // short
#define KW_SIGNED 67 // signed
#define KW_UNSIGNED 68 // unsigned
#define KW_AUTO 69 // auto
#define KW_EXTERN 70 // extern
#define KW_REGISTER 71 // register
#define KW_STATIC 72 // static
#define KW_CONST 73 // const 
#define KW_VOLATILE 74 // volatile
#define KW_MUTABLE 75 // mutable
#define KW_RESTRICT 76 // restrict
#define KW_RETURN 77 // return
#define KW_VOID 78 // void
#define KW_AUTO 79 // auto
#define KW_TYPEDEF // typedef
#define KW_ENUM // enum
#define KW_UNION // union
#define KW_STRUCT // struct
#define KW_goto // goto
#define KW_continue // continue
#define KW_BREAK // break


/******************************************************/
/* main driver */
int main()
{
/* Open the input data file and process its contents */
if ((in_fp = fopen("front.in", "r")) == NULL)
printf("ERROR - cannot open front.in \n");
else
{
getChar();
do
{
lex();
} while (nextToken != EOF);
}
return 0;
}
/*****************************************************/
/* lookup - a function to lookup operators and parentheses
and return the token */
int lookup(char ch)
{
switch (ch)
{
case '(':
addChar();
nextToken = LEFT_PAREN;
break;
case ')':
addChar();
nextToken = RIGHT_PAREN;
break;
case '+':
addChar();
nextToken = ADD_OP;
break;
case '-':
addChar();
nextToken = SUB_OP;
break;
case '*':
addChar();
nextToken = MULT_OP;
break;
case '/':
addChar();
nextToken = DIV_OP;
break;
case '%':
nextToken = MOD_OP;
addChar();
nextTOKEN = MOD_OP;
break;
case '=':
nextToken = EQ_OP;
addChar();
break;
default:
addChar()
nextToken = EOF;
break;
}
return nextToken;
}
/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar()
{
if (lexLen <= 98)
{
lexeme[lexLen++] = nextChar;
lexeme[lexLen] = 0;
}
else
printf("Error - lexeme is too long \n");
}
/*****************************************************/
/* getChar - a function to get the next character of
input and determine its character class */
void getChar()
{
if ((nextChar = getc(in_fp)) != EOF)
{
if (isalpha(nextChar))
charClass = LETTER;
else if (isdigit(nextChar))
charClass = DIGIT;
else
charClass = UNKNOWN;
}
else
charClass = EOF;
}
/*****************************************************/
/* getNonBlank - a function to call getChar until it
returns a non-whitespace character */
void getNonBlank()
{
while (isspace(nextChar))
getChar();
}
/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic expressions */
int lex()
{
lexLen = 0;
getNonBlank();
switch (charClass)
{
/* Parse identifiers */
case LETTER:
addChar();
getChar();
while (charClass == LETTER || charClass == DIGIT)
{
addChar();
getChar();
}
nextToken = IDENT;
break;
/* Parse integer literals */
case DIGIT:
addChar();
getChar();
while (charClass == DIGIT)
{
addChar();
getChar();
}
nextToken = INT_LIT;
break;
/* Parentheses and operators */
case UNKNOWN:
lookup(nextChar);
getChar();
break;
/* EOF */
case EOF:
nextToken = EOF;
lexeme[0] = 'E';
lexeme[1] = 'O';
lexeme[2] = 'F';
lexeme[3] = 0;
break;
} /* End of switch */
printf("Next token is: %d, Next lexeme is %s\n")
}

nextToken, lexeme);
return nextToken;
} /* End of function lex */
