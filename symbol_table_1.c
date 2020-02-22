%{
int lineno = 1;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWITCH 1
#define BREAK 2
#define CASE 3
#define CHAR 4
#define CONTINUE 5
#define DEFAULT 6
#define DOUBLE 7
#define FLOAT 8
#define FOR 9
#define INT 10
#define RETURN 11
#define VOID 12
#define WHILE 13
#define IDENTIFIER 14
#define LEQ 15
#define GEQ 16
#define EQEQ 17
#define NEQ 18
#define LOR 19
#define LAND 20
#define ASSIGN 21
#define PLUS 22
#define SUB 23
#define MULT 24
#define DIV 25
#define MOD 26
#define LESSER 27
#define GREATER 28
#define INCR 29
#define DECR 30
#define COMMA 31
#define SEMI 32
#define COLON 33
#define MAIN 34
#define PRINTF 35
#define SCANF 36
#define INT_CONST 37
#define FLOAT_CONST 38
#define TYPE_SPEC 39
#define DQ 40 //special symbol
#define OBO 41
#define OBC 42
#define CBO 43
#define CBC 44
//#define HASH 68
#define ARR 45
#define FUNC 46
#define NUM_ERR 47
#define UNKNOWN 48
#define CHAR_CONST 49
#define STRING_CONST 50
#define ERROR 51
#define SLC 52
#define MLCS 53
#define MLCE 54
%}

alpha [A-Za-z]
digit [0-9]
und [_]
space [ ]
tab [ ]
line [\n]
char \'.\'
at [@]
string \"(.^([%d]|[%f]|[%s]|[%c]))\"

%%
{line} {lineno++;}
[\t]+ ;
{space}* {}
{string} return STRING_CONST;
{char} return CHAR_CONST;
break return BREAK;
case return CASE;
char return CHAR;
continue return CONTINUE;
default return DEFAULT;
double return DOUBLE;
float return FLOAT;
for return FOR;
int return INT;
return return RETURN;
switch return SWITCH;
void return VOID;
while return WHILE;
printf return PRINTF;
scanf return SCANF;
({alpha}|{und})({alpha}|{digit}|{und})* return IDENTIFIER;
"<=" return LEQ;
">=" return GEQ;
"==" return EQEQ;
"!=" return NEQ;
"||" return LOR;
"&&" return LAND;
"=" return ASSIGN;
"+" return PLUS;
"-" return SUB;
"*" return MULT;
"/" return DIV;
"%" return MOD;
"<" return LESSER;
">" return GREATER;
"++" return INCR;
"--" return DECR;
"," return COMMA;
";" return SEMI;
":" return COLON;
"main()" return MAIN;
{digit}+ return INT_CONST;
({digit}+)\.({digit}+) return FLOAT_CONST;
"%d"|"%f"|"%u"|"%s" return TYPE_SPEC;
"\"" return DQ;
"(" return OBO;
")" return OBC;
"{" return CBO;
"}" return CBC;


"//" return SLC;
"/*" return MLCS;
"*/" return MLCE;

{alpha}({alpha}|{digit}|{und})*\[{digit}*\] return ARR;
{alpha}({alpha}|{digit}|{und})*\(({alpha}|{digit}|{und}|{space})*\) return FUNC;
({digit}+)\.({digit}+)\.({digit}|\.)* return NUM_ERR;
({digit}|{at})+({alpha}|{digit}|{und}|{at})* return UNKNOWN;
. return ERROR;

%%

struct node
{
char token[100];
    char attr[100];
struct node *next;
};

struct hash
{
struct node *head;
int count;
};

struct hash hashTable[1000];
int eleCount = 1000;

struct node * createNode(char *token, char *attr)
{
struct node *newnode;
newnode = (struct node *) malloc(sizeof(struct node));
strcpy(newnode->token, token);
strcpy(newnode->attr, attr);
newnode->next = NULL;
return newnode;
}

int hashIndex(char *token)
{
//printf("%s",token[0]);
int hi=0;
int l,i;
for(i=0;token[i]!='\0';i++)
{
hi = hi + (int)token[i];
}
hi = hi%eleCount;
return hi;
}

void insertToHash(char *token, char *attr)
{
int flag=0;
int hi;
hi = hashIndex(token);
//printf("%d\n",hi);
struct node *newnode = createNode(token, attr);
/* head of list for the bucket with index "hashIndex" */
if (hashTable[hi].head==NULL)
{
hashTable[hi].head = newnode;
       hashTable[hi].count = 1;
       return;
}
struct node *myNode;
    myNode = hashTable[hi].head;
while (myNode != NULL)
    {
        if (strcmp(myNode->token, token)==0)
        {
            flag = 1;
            break;
        }
        myNode = myNode->next;
//printf("hello gaani");
    }
/*if(!flag)
{
//adding new node to the list
newnode->next = (hashTable[hi].head);
//update the head of the list and no of nodes in the current bucket
hashTable[hi].head = newnode;
hashTable[hi].count++;
//printf("%s",hashTable[hi].head->token);
printf("hello gaani");
}
//printf("%d",hashTable[hi].count);*/
return ;
}

void display()
{
    struct node *myNode;
    int i,j, k=1;
    printf("-------------------------------------------------------------------");
    printf("\nSNo \t|\tToken \t\t|\tToken Type \t\n");
        printf("-------------------------------------------------------------------\n");
    for (i = 0; i < eleCount; i++)
    {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        while (myNode != NULL)
        {
            printf("%d\t\t", k++);
            printf("%s\t\t\t", myNode->token);
            printf("%s\t\n", myNode->attr);
            myNode = myNode->next;
        }
}
    return;
}

int main()
{
int scan, slcline=0, mlc=0, mlcline=0, dq=0, dqline=0;
yyin = fopen("input.c","r");
printf("\n\n");
scan = yylex();
while(scan)
{
if(lineno == slcline)
{
scan = yylex();
continue;
}
if(lineno!=dqline && dqline!=0)
{
if(dq%2!=0)
printf("\n******** ERROR!! INCOMPLETE STRING at Line %d ********\n\n", dqline);
dq=0;
}
if(((scan>=1 && scan<=13) || scan==35 || scan==36) && mlc==0)
{
printf("%s\t\t\tKEYWORD\t\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "KEYWORD");
}
if(scan==14 && mlc==0)
{
printf("%s\t\t\tIDENTIFIER\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "IDENTIFIER");
}
if(scan==34 && mlc==0)
{
printf("%s\t\t\tMAIN_FUNCTION\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "MAIN_FUNCTION");
}
if(((scan>=15 && scan<=18) || scan==27 || scan==28) && mlc==0)
{
printf("%s\t\t\tRELATIONAL_OPERATOR\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "RELATIONAL_OPERATOR");
}
if((scan==19 || scan==20) && mlc==0)
{
printf("%s\t\t\tLOGICAL_OPERATORS\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "LOGICAL_OPERATOR");
}
if(scan==21 && mlc==0)
{
printf("%s\t\t\tASSIGNMENT_OPERATOR\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "ASSIGNMENT_OPERATOR");
}
if((scan>=22 && scan<=26) && mlc==0)
{
printf("%s\t\t\tBINARY_OPERATOR\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "BINARY_OPERATOR");
}
if((scan==29 || scan==30) && mlc==0)
{
printf("%s\t\t\tUNARY_OPERATOR\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "UNARY_OPERATOR");
}
/*if((scan>=31 && scan<=33) && mlc==0)
{
printf("%s\t\t\tSYMBOLS\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "SYMBOLS");
}*/
if((scan==37 || scan==38 ||  scan==49 || scan==50) && mlc==0)
{
printf("%s\t\t\tCONSTANT\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "CONSTANT");
}
if(scan==39 && mlc==0)
{
printf("%s\t\t\tTYPE_SPECIFIER\t\t\tLine %d\n", yytext, lineno);
}

if((scan==31||scan==32||scan==40|| scan==33 || (scan>=41 && scan<=44)) && mlc==0)
{
printf("%s\t\t\tSPECIAL_SYMBOL\t\t\tLine %d\n", yytext, lineno);
if(scan==40)
{
dq++;
dqline = lineno;
//printf("%d",dq);

}
insertToHash(yytext, "SPECIAL_SYMBOL");
}

if(scan==45 && mlc==0)
{
printf("%s\t\t\tARRAY\t\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "ARRAY");
}
if(scan==46 && mlc==0)
{
printf("%s\t\t\tUSER DEFINED FUNCTION\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "USER DEFINED FUNCTION");
}
if(scan==47 && mlc==0)
{
printf("\n******** ERROR!! CONSTANT ERROR %s at Line %d ********\n\n", yytext, lineno);
}
if(scan==48 && mlc==0)
{
printf("\n******** ERROR!! UNKNOWN TOKEN %s at Line %d ********\n\n", yytext, lineno);
}
if(scan==51 && mlc==0)
{
printf("%s\t\t\tERROR\t\t\tLine %d\n", yytext, lineno);
insertToHash(yytext, "ERROR");
}
if(scan==52)
{
printf("%s\t\t\tSingleline Comment\t\tLine %d\n", yytext, lineno);
slcline = lineno;
}
if(scan==53 && mlc==0)
{
printf("%s\t\t\tMultiline Comment Start\t\tLine %d\n", yytext, lineno);
mlcline = lineno;
mlc = 1;
}
if(scan==54 && mlc==0)
{
printf("\n******** ERROR!! UNMATCHED MULTILINE COMMENT END %s at Line %d ********\n\n", yytext, lineno);
}
if(scan==54 && mlc==1)
{
mlc = 0;
printf("%s\t\t\tMultiline Comment End\t\tLine %d\n", yytext, lineno);
}

scan = yylex();
}
if(mlc==1)
printf("\n******** ERROR!! UNMATCHED COMMENT STARTING at Line %d ********\n\n",mlcline);
printf("\n");
printf("\n\t******** SYMBOL TABLE ********\t\t\n");
display();
        printf("-------------------------------------------------------------------\n\n");
}
int yywrap()
{
return 1;
}  
