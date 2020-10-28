#include "c2c_polymorphism_defs.h"


int next_id = 0;
const char _z18PrePostDollarFixer14DEFAULT_SYMBOL = '$';


void*(*TextFormatterVtable[])(void*) = {(void*(*)(void*))_z13TextFormatter10destractorF, NULL};

void*(*DefaultTextFormatterVtable[])(void*) = {(void*(*)(void*))_z20DefaultTextFormatter10destractorF,
                                               (void*(*)(void*))_z20DefaultTextFormatter5printFKc};

void*(*PrePostFixerVtable[])(void*) = {(void*(*)(void*))_z12PrePostFixer10destractorF,
                                       (void*(*)(void*))_z12PrePostFixer5printFKc,
                                       (void*(*)(void*))_z12PrePostFixer5printFlc,
                                       (void*(*)(void*))_z12PrePostFixer16getDefaultSymbolF};

void*(*PrePostDollarFixerVtable[])(void*) = {(void*(*)(void*))_z18PrePostDollarFixer10destractorF,
                                             (void*(*)(void*))_z12PrePostFixer5printFKc,
                                             (void*(*)(void*))_z18PrePostDollarFixer5printlc,
                                             (void*(*)(void*))_z18PrePostDollarFixer16getDefaultSymbolF};


void _z13TextFormatter10destractorF(void* this){}
void _z13TextFormatter4initF(TextFormatter* this)
{
    this->_vptr = TextFormatterVtable;
}
void _z20DefaultTextFormatter4initF(DefaultTextFormatter* this)
{
    _z13TextFormatter4initF((TextFormatter *) this);
    ((TextFormatter*)this)->_vptr = DefaultTextFormatterVtable;
    this->_id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->_id);
}
void _z20DefaultTextFormatter10destractorF(void* this)
{

    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", ((DefaultTextFormatter *)this)->_id);
    _z13TextFormatter10destractorF((TextFormatter *) this);
}

void _z20DefaultTextFormatter4copyF(DefaultTextFormatter* this, const DefaultTextFormatter* other)
{
    _z13TextFormatter4initF((TextFormatter*)this);
    ((TextFormatter*)this)->_vptr = DefaultTextFormatterVtable;
    this->_id = next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->_id, this->_id);
}
DefaultTextFormatter* _z20DefaultTextFormatter10assignmentF(DefaultTextFormatter* this,const DefaultTextFormatter* other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->_id, this->_id);
    return this;
}
void _z20DefaultTextFormatter5printFKc(void* this,const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}
DefaultTextFormatter* generateFormatterArray()
{
    int i;
    DefaultTextFormatter *generateFormatterArray = malloc(sizeof(DefaultTextFormatter)*3);
    for (i = 0; i < 3; ++i)
    {
        _z20DefaultTextFormatter4initF(generateFormatterArray+i);
    }
    return  generateFormatterArray;
}

void _z12PrePostFixer4initF(PrePostFixer* this,const char* prefix, const char* postfix)
{
    _z20DefaultTextFormatter4initF((DefaultTextFormatter*)this);
    ((TextFormatter*)this)->_vptr = PrePostFixerVtable;
    this->_pre = prefix;
    this->_post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->_pre, this->_post);
}
void _z12PrePostFixer4copyF(PrePostFixer* this,const PrePostFixer* other)
{
    _z20DefaultTextFormatter4copyF((DefaultTextFormatter*)this,(DefaultTextFormatter*)other);
    ((TextFormatter*)this)->_vptr = PrePostFixerVtable;
    this->_pre = other->_pre;
    this->_post = other->_post;

}
void _z12PrePostFixer10destractorF(void* this)
{
    PrePostFixer* pointToThis = this;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pointToThis->_pre, pointToThis->_post);
    _z20DefaultTextFormatter10destractorF((DefaultTextFormatter*)this);
}
void _z12PrePostFixer5printFKc(void* this,const char* text)
{
    PrePostFixer* pointToThis = this;
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", pointToThis->_pre, text, pointToThis->_post);
}
void _z12PrePostFixer5printFlc(void* this,long num, char symbol /*= '\0'*/)
{
    PrePostFixer* pointToThis = this;
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", pointToThis->_pre, symbol, num, pointToThis->_post);
    }

    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", pointToThis->_pre, num, pointToThis->_post);
    }

}
char _z12PrePostFixer16getDefaultSymbolF(void* this)
{
    return '\0';
}

void _z18PrePostDollarFixer4initF(PrePostDollarFixer* this,const char* prefix, const char* postfix)
{
    _z12PrePostFixer4initF((PrePostFixer*)this,prefix,postfix);
    ((TextFormatter*)this)->_vptr = PrePostDollarFixerVtable;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);

}
void _z18PrePostDollarFixer4copyF(PrePostDollarFixer* this,const PrePostDollarFixer* other)
{
    _z12PrePostFixer4copyF((PrePostFixer*)this,(PrePostFixer*)other);
    ((TextFormatter*)this)->_vptr = PrePostDollarFixerVtable;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);

}
void _z18PrePostDollarFixer10destractorF(void* this)
{

    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre, ((PrePostFixer*)this)->_post);
    _z12PrePostFixer10destractorF((PrePostFixer*)this);
}

void _z18PrePostDollarFixer5printFic(PrePostDollarFixer* this,int num, char symbol /*= DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    ((pPrintLongAndChar)((((TextFormatter*)this)->_vptr)[E_PRINT_LONG_AND_CHAR]))(this, (long)num, symbol);
}
void _z18PrePostDollarFixer5printlc(void* this,long num, char symbol /*= DEFAULT_SYMBOL*/)
{
    PrePostDollarFixer* pointToThis = this;
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    _z12PrePostFixer5printFlc(pointToThis,num, symbol);

}
void _z18PrePostDollarFixer5printdc(PrePostDollarFixer* this,double num, char symbol/*= DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->_pre, symbol, num, ((PrePostFixer*)this)->_post);
}
char _z18PrePostDollarFixer16getDefaultSymbolF(void* this)
{
    return _z18PrePostDollarFixer14DEFAULT_SYMBOL;
}

