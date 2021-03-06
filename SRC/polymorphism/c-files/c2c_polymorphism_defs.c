#include "c2c_polymorphism_defs.h"


int next_id = 0;
const char _z18PrePostDollarFixer14DEFAULT_SYMBOL = '$';
const char _z16PrePostHashFixer14DEFAULT_SYMBOL = '#';
const char _z23PrePostFloatDollarFixer14DEFAULT_SYMBOL = '@';

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

void*(*PrePostHashFixerVtable[])(void*) = {(void*(*)(void*))_z16PrePostHashFixer10destractorF,
                                           (void*(*)(void*))_z12PrePostFixer5printFKc,
                                           (void*(*)(void*))_z16PrePostHashFixer5printlcF,
                                           (void*(*)(void*))_z16PrePostHashFixer16getDefaultSymbolF};

void*(*PrePostFloatDollarFixerVtable[])(void*) = {(void*(*)(void*))_z23PrePostFloatDollarFixer10destractorF,
                                                  (void*(*)(void*))_z12PrePostFixer5printFKc,
                                                  (void*(*)(void*))_z18PrePostDollarFixer5printlc,
                                                  (void*(*)(void*))_z23PrePostFloatDollarFixer16getDefaultSymbolF};

void*(*PrePostCheckerVtable[])(void*) = {(void*(*)(void*))_z14PrePostChecker10destractorF,
                                         (void*(*)(void*))_z12PrePostFixer5printFKc,
                                         (void*(*)(void*))_z18PrePostDollarFixer5printlc,
                                         (void*(*)(void*))_z23PrePostFloatDollarFixer16getDefaultSymbolF};

void*(*MultiplierVtable[])(void*) = {(void*(*)(void*))_z10Multiplier10destractorF,
                                     (void*(*)(void*))_z10Multiplier5printFKc};

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

void _16PrePostHashFixer4initF(PrePostHashFixer* this,int prc /*= 4*/)
{
    _z18PrePostDollarFixer4initF((PrePostDollarFixer*)this,"===> ", " <===");
    ((TextFormatter*)this)->_vptr = PrePostHashFixerVtable;
    this->_precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post, this->_precision);
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, _z16PrePostHashFixer14DEFAULT_SYMBOL , this->_precision, 9999.9999, ((PrePostFixer*)this)->_post);

}
void _z16PrePostHashFixer10destractorF(void* this)
{

    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post);
    _z18PrePostDollarFixer10destractorF((PrePostDollarFixer*)this);
}
void _z16PrePostHashFixer5printicF(PrePostHashFixer* this,int num, char symbol/*= DEFAULT_SYMBOL*/)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, symbol, this->_precision,
           (double)num, ((PrePostFixer*)this)->_post);

}
void _z16PrePostHashFixer5printlcF(void* this,long num, char symbol /*= DEFAULT_SYMBOL*/)
{
    PrePostHashFixer* pointToThis = this;
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->_pre, symbol, pointToThis->_precision,
           (double)num, ((PrePostFixer*)this)->_post);

}

char _z16PrePostHashFixer16getDefaultSymbolF(void* this)
{
    return _z16PrePostHashFixer14DEFAULT_SYMBOL;
}
void _z23PrePostFloatDollarFixer4initF(PrePostFloatDollarFixer* this,const char* prefix, const char* postfix)
{
    _z18PrePostDollarFixer4initF((PrePostDollarFixer*)this,prefix,postfix);
    ((TextFormatter*)this)->_vptr = PrePostFloatDollarFixerVtable;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post);
}
void _z23PrePostFloatDollarFixer10destractorF(void* this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post);
    _z18PrePostDollarFixer10destractorF((PrePostDollarFixer*)this);
}
void _z23PrePostFloatDollarFixer5printFf(PrePostFloatDollarFixer* this,float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");
    _z23PrePostFloatDollarFixer5printFfc(this,num, _z23PrePostFloatDollarFixer14DEFAULT_SYMBOL);

}
void _z23PrePostFloatDollarFixer5printFfc(PrePostFloatDollarFixer* this,float num, char symbol)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", ((PrePostFixer*)this)->_pre, symbol, num, ((PrePostFixer*)this)->_post);
}
char _z23PrePostFloatDollarFixer16getDefaultSymbolF(void* this)
{
    return _z23PrePostFloatDollarFixer14DEFAULT_SYMBOL;
}

void _z14PrePostChecker4initF(PrePostChecker* this)
{
    _z23PrePostFloatDollarFixer4initF((PrePostFloatDollarFixer*)this,"[[[[ ", " ]]]]");
    ((TextFormatter*)this)->_vptr = PrePostCheckerVtable;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post);

}
void _z14PrePostChecker10destractorF(void* this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->_pre,
           ((PrePostFixer*)this)->_post);
    _z23PrePostFloatDollarFixer10destractorF((PrePostChecker*)this);
}
void _z14PrePostChecker24printThisSymbolUsingFuncF(PrePostChecker* this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    printf("Default symbol is %c\n",
           ((pGetDefaultSymbol)((((TextFormatter*)this)->_vptr)[E_GET_DEFAULT_SYMBOL]))(this));
}
void _z14PrePostChecker23printThisSymbolDirectlyF(PrePostChecker* this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");
    printf("Default symbol is %c\n", _z23PrePostFloatDollarFixer14DEFAULT_SYMBOL);
}
void _z14PrePostChecker30printDollarSymbolByCastUsingFuncF(PrePostChecker* this)
{

    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    printf("Default symbol is %c\n",
           ((pGetDefaultSymbol)((((TextFormatter*)this)->_vptr)[E_GET_DEFAULT_SYMBOL]))(this));
}
void _z14PrePostChecker31printDollarSymbolByScopeUsingFuncF(PrePostChecker* this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", _z18PrePostDollarFixer16getDefaultSymbolF(this));
}
void _z14PrePostChecker29printDollarSymbolByCastDirectlyF(PrePostChecker* this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n", _z18PrePostDollarFixer14DEFAULT_SYMBOL);
}
void _z14PrePostChecker30printDollarSymbolByScopeDirectlyF(PrePostChecker* this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n", _z18PrePostDollarFixer14DEFAULT_SYMBOL);
}
void _z10Multiplier10destractorF(void* this)
{
    Multiplier* pointToThis = this;
    printf("--- Multiplier DTOR: times = %d\n", pointToThis->_times);
    _z20DefaultTextFormatter10destractorF((DefaultTextFormatter*)this);
}
void _z10Multiplier5printFKc(void* this,const char* text)
{
    int i;
    Multiplier* pointToThis = this;
    printf("%-60s | ", "[Multiplier::print(const char*)]");
    for (i = 0; i < pointToThis->_times; ++i)
        printf("%s", text);
    printf("\n");
}
void _z10Multiplier4copyF(Multiplier* this,const Multiplier* other)
{
    _z20DefaultTextFormatter4copyF((DefaultTextFormatter*)this,(DefaultTextFormatter*)other);
    ((TextFormatter*)this)->_vptr = MultiplierVtable;
    this->_times = other->_times;
}