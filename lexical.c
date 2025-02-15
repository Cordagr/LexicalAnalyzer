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
#define KW_RESTRICT 75 // restrict
#define KW_RETURN 76 // return
#define KW_VOID 77 // void
#define KW_AUTO 78 // auto
#define KW_TYPEDEF 79 // typedef
#define KW_ENUM  80 // enum
#define KW_UNION 81 // union
#define KW_STRUCT 82 // struct
#define KW_GOTO 83 // goto
#define KW_CONTINUE 84 // continue
#define KW_BREAK 85 // break


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
addChar();
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

/****************************************************/
/* getKeyword - a function get the next character of input and determine of
input and determine its keyword */
void getKeyword()
{
if(strcmp(lexeme,"if") == 0):
return KW_IF;
else if(strcmp(lexeme,"else") == 0):
return KW_ELSE;
else if(strcmp(lexeme,"switch") == 0):
return KW_SWITCH;
else if(strcmp(lexeme,"case") == 0):
return KW_CASE;
else if(strcmp(lexeme,"default") == 0):
return KW_DEFAULT;
else if(strcmp(lexeme,"while") == 0):
return KW_WHILE;
else if(strcmp(lexeme,"do") == 0):
return KW_DO;
else if(strcmp(lexeme,"for") == 0):
return KW_FOR;
else if(strcmp(lexeme,"int") == 0):
return KW_INT;
else if(strcmp(lexeme,"char") == 0):
return KW_CHAR;
else if(strcmp(lexeme,"float") == 0):
return KW_FLOAT;
else if(strcmp(lexeme,"double") == 0):
return KW_DOUBLE; 
else if(strcmp(lexeme,"long") == 0):
return KW_LONG;
else if(strcmp(lexeme,"short") == 0):
return KW_SHORT;
else if(strcmp(lexeme,"signed") == 0):
return KW_SIGNED;
else if(strcmp(lexeme,"unsigned") == 0):
return KW_UNSIGNED;
else if(strcmp(lexeme,"auto") == 0):
return KW_AUTO;
else if(strcmp(lexeme,"extern") == 0):
return KW_EXTERN;
else if(strcmp(lexeme,"register") == 0):
return KW_REGISTER;
else if(strcmp(lexeme,"static") == 0):
return KW_CONST;
else if(strcmp(lexeme,"const") == 0):
return KW_CONST;
else if(strcmp(lexeme,"volatile") == 0):
return KW_VOLATILE;
else if(strcmp(lexeme,"restrict") == 0):
return KW_RESTRICT;
else if(strcmp(lexeme,"return") == 0):
return KW_RETURN;
else if(strcmp(lexeme,"void") == 0):
return KW_VOID;
else if(strcmp(lexeme,"sizeof") == 0):
return KW_SIZEOF;
else if(strcmp(lexeme,"typedef") == 0):
return KW_TYPEDEF;
else if(strcmp(lexeme,"enum") == 0):
return KW_ENUM;
else if(strcmp(lexeme,"union") == 0):
return KW_UNION;
else if(strcmp(lexeme,"struct") == 0):
return KW_STRUCT;
else if(strcmp(lexeme,"goto") == 0):
return KW_GOTO;
else if(strcmp(lexeme,"continue") == 0):
return KW_CONTINUE;
else if(strcmp(lexeme,"break") == 0):
return KW_BREAK;
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

