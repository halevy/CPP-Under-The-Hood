#include "c2c_polymorphism_defs.h"


int next_id = 0;

void*(*TextFormatterVtable[])(void*) = {(void*(*)(void*))_z13TextFormatter10destractorF, NULL};

void*(*DefaultTextFormatterVtable[])(void*) = {(void*(*)(void*))_z20DefaultTextFormatter10destractorF,
                                               (void*(*)(void*))_z20DefaultTextFormatter5printFKc};


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
