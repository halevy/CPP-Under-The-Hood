
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


extern int next_id;

extern void*(*TextFormatterVtable[])(void*);
extern void*(*DefaultTextFormatterVtable[])(void*);

void _z13TextFormatter4initF(TextFormatter* this);
void _z13TextFormatter10destractorF(void* this);

void _z20DefaultTextFormatter4copyF(DefaultTextFormatter* this, const DefaultTextFormatter* other);
void _z20DefaultTextFormatter10destractorF(void* this);
void _z20DefaultTextFormatter4initF(DefaultTextFormatter* this);
DefaultTextFormatter* _z20DefaultTextFormatter10assignmentF(DefaultTextFormatter* this,const DefaultTextFormatter* other);
void _z20DefaultTextFormatter5printFKc(void* this,const char* text);
DefaultTextFormatter* generateFormatterArray();



#endif
