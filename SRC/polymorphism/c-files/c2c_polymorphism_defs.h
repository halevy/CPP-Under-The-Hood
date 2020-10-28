
#ifndef BOX_SHELF_C2C_POLYMORPHISM_DEFS_H
#define BOX_SHELF_C2C_POLYMORPHISM_DEFS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum FuncName
{
    E_DESTRACTOR,
    E_PRINT_CHAR,
    E_PRINT_LONG_AND_CHAR,
    E_GET_DEFAULT_SYMBOL
}FuncName;

typedef void(*pDestractor)(void*);
typedef void(*pPrintChar)(void*,const char*);
typedef void(*pPrintLongAndChar)(void*,long,char);
typedef char(*pGetDefaultSymbol)(void*);

typedef struct TextFormatter
{
    void*(**_vptr)(void*);
}TextFormatter;

typedef struct DefaultTextFormatter
{
    TextFormatter textFormatter;
    int _id;
}DefaultTextFormatter;

typedef struct PrePostFixer
{
    DefaultTextFormatter defaultTextFormatter;
    char* _pre;
    char* _post;
}PrePostFixer;

typedef struct PrePostDollarFixer
{
    PrePostFixer prePostFixer;
}PrePostDollarFixer;


extern int next_id;
extern const char _z18PrePostDollarFixer14DEFAULT_SYMBOL;


extern void*(*TextFormatterVtable[])(void*);
extern void*(*DefaultTextFormatterVtable[])(void*);
extern void*(*PrePostFixerVtable[])(void*);
extern void*(*PrePostDollarFixerVtable[])(void*);

void _z13TextFormatter4initF(TextFormatter* this);
void _z13TextFormatter10destractorF(void* this);

void _z20DefaultTextFormatter4copyF(DefaultTextFormatter* this, const DefaultTextFormatter* other);
void _z20DefaultTextFormatter10destractorF(void* this);
void _z20DefaultTextFormatter4initF(DefaultTextFormatter* this);
DefaultTextFormatter* _z20DefaultTextFormatter10assignmentF(DefaultTextFormatter* this,const DefaultTextFormatter* other);
void _z20DefaultTextFormatter5printFKc(void* this,const char* text);
DefaultTextFormatter* generateFormatterArray();

void _z12PrePostFixer4initF(PrePostFixer* this,const char* prefix, const char* postfix);
void _z12PrePostFixer4copyF(PrePostFixer* this,const PrePostFixer* other);
void _z12PrePostFixer10destractorF(void* this);
void _z12PrePostFixer5printFKc(void* this,const char* text);
void _z12PrePostFixer5printFlc(void* this,long num, char symbol /*= '\0'*/);
char _z12PrePostFixer16getDefaultSymbolF(void* this);

void _z18PrePostDollarFixer4initF(PrePostDollarFixer* this,const char* prefix, const char* postfix);
void _z18PrePostDollarFixer4copyF(PrePostDollarFixer* this,const PrePostDollarFixer* other);
void _z18PrePostDollarFixer10destractorF(void* this);
void _z18PrePostDollarFixer5printFic(PrePostDollarFixer* this,int num, char symbol /*= DEFAULT_SYMBOL*/);
void _z18PrePostDollarFixer5printlc(void* this,long num, char symbol /*= DEFAULT_SYMBOL*/);
void _z18PrePostDollarFixer5printdc(PrePostDollarFixer* this,double num, char symbol/*= DEFAULT_SYMBOL*/);
char _z18PrePostDollarFixer16getDefaultSymbolF(void* this);



#endif
