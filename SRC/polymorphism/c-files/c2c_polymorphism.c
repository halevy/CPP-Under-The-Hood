
#include "c2c_polymorphism_defs.h"

void _z14doPrePostFixerF()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    _z12PrePostFixer4initF(&angleBrackets,"<<< ", " >>>");
    _z12PrePostFixer5printFKc(&angleBrackets,"Hello World!");
    _z12PrePostFixer5printFlc(&angleBrackets,-777,'\0');
    _z12PrePostFixer5printFlc(&angleBrackets,350,'#');
    _z12PrePostFixer5printFlc(&angleBrackets,(long)3.14,'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    _z12PrePostFixer10destractorF(&angleBrackets);
}

void _z20doPrePostDollarFixerF()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    _z18PrePostDollarFixer4initF(&asterisks,"***** ", " *****");
    _z18PrePostDollarFixer5printFic(&asterisks,-777,'$');
    _z18PrePostDollarFixer5printFic(&asterisks,350,'#');
    _z18PrePostDollarFixer5printdc(&asterisks,3.14f,'$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _z18PrePostDollarFixer10destractorF(&asterisks);
}
void _z25doPrePostFloatDollarFixerF()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;
    _z23PrePostFloatDollarFixer4initF(&hashes,"### ", " ###");
    _z23PrePostFloatDollarFixer5printFf(&hashes,-777);
    _z23PrePostFloatDollarFixer5printFfc(&hashes,350, '#');
    _z23PrePostFloatDollarFixer5printFf(&hashes,3.14f);

    _z18PrePostDollarFixer4copyF(&hashes2,(PrePostDollarFixer*)&hashes);
    _z18PrePostDollarFixer5printdc(&hashes2,7.5,'$');
    _z18PrePostDollarFixer5printFic(&hashes2,100,'$');


    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    _z18PrePostDollarFixer10destractorF(&hashes2);
    _z23PrePostFloatDollarFixer10destractorF(&hashes);
}

void _z16doPrePostCheckerF()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    _z14PrePostChecker4initF(&check);
    _z14PrePostChecker24printThisSymbolUsingFuncF(&check);
    _z14PrePostChecker23printThisSymbolDirectlyF(&check);
    _z14PrePostChecker29printDollarSymbolByCastDirectlyF(&check);
    _z14PrePostChecker30printDollarSymbolByScopeDirectlyF(&check);
    _z14PrePostChecker30printDollarSymbolByCastUsingFuncF(&check);
    _z14PrePostChecker31printDollarSymbolByScopeUsingFuncF(&check);


    printf("\n--- end doPrePostChecker() ---\n\n");
    _z14PrePostChecker10destractorF(&check);
}
void _z20runAsPrePostFixerRefF(PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((pPrintLongAndChar) ((((TextFormatter *) pp)->_vptr)[E_PRINT_LONG_AND_CHAR]))(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}
void _z26runAsPrePostDollarFixerRefF(PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    _z18PrePostDollarFixer5printFic(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}
void _z26runAsPrePostDollarFixerObjF(PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    _z18PrePostDollarFixer5printFic(&pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");

}

void _z24runAsPrePostHashFixerRefF(PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    _z16PrePostHashFixer5printicF(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void _z12doMultiplierF()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1,m2,m3,m4;
    _z20DefaultTextFormatter4initF((DefaultTextFormatter*)&m1);
    ((TextFormatter*)&m1)->_vptr = MultiplierVtable;
    m1._times = 3;
    printf("--- Multiplier CTOR: times = %d\n", m1._times);

    _z20DefaultTextFormatter4initF((DefaultTextFormatter*)&m2);
    ((TextFormatter*)&m2)->_vptr = MultiplierVtable;
    m2._times = 5;
    printf("--- Multiplier CTOR: times = %d\n", m2._times);

    _z10Multiplier4copyF(&m3,&m1);
    _z10Multiplier4copyF(&m4,&m2);

    _z10Multiplier5printFKc(&m1,"abc ");
    _z10Multiplier5printFKc(&m2,"abc ");
    _z10Multiplier5printFKc(&m3,"abc ");
    _z10Multiplier5printFKc(&m4,"abc ");

    printf("\n--- end doMultiplier() ---\n\n");
    _z10Multiplier10destractorF(&m4);
    _z10Multiplier10destractorF(&m3);
    _z10Multiplier10destractorF(&m2);
    _z10Multiplier10destractorF(&m1);

}
void _z16doFormatterArrayF()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    int i;
    DefaultTextFormatter formatters[3];

    PrePostDollarFixer temp;
    _z18PrePostDollarFixer4initF(&temp,"!!! ", " !!!");
    _z20DefaultTextFormatter4copyF(formatters,(DefaultTextFormatter*)&temp);
    _z18PrePostDollarFixer10destractorF(&temp);

    Multiplier temp1;
    _z20DefaultTextFormatter4initF((DefaultTextFormatter*)&temp1);
    ((TextFormatter*)&temp1)->_vptr = MultiplierVtable;
    temp1._times = 4;
    printf("--- Multiplier CTOR: times = %d\n", temp1._times);
    _z20DefaultTextFormatter4copyF(formatters+1,(DefaultTextFormatter*)&temp1);
    _z10Multiplier10destractorF(&temp1);

    PrePostChecker temp2;
    _z14PrePostChecker4initF(&temp2);
    _z20DefaultTextFormatter4copyF(formatters+2,(DefaultTextFormatter*)&temp2);
    _z14PrePostChecker10destractorF(&temp2);

    for (i = 0; i < 3; ++i)
        _z20DefaultTextFormatter5printFKc(formatters+i,"Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
    for (i = 2; i >= 0; --i)
    {
        _z20DefaultTextFormatter10destractorF(formatters+i);
    }

}
void _z15doFormatterPtrsF()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");
    int i;

    PrePostDollarFixer* prePostDollarFixer = malloc(sizeof(PrePostDollarFixer));
    _z18PrePostDollarFixer4initF(prePostDollarFixer,"!!! ", " !!!");

    Multiplier* multiplier = malloc(sizeof(Multiplier));
    _z20DefaultTextFormatter4initF((DefaultTextFormatter*)multiplier);
    ((TextFormatter*)multiplier)->_vptr = MultiplierVtable;
    multiplier->_times = 4;
    printf("--- Multiplier CTOR: times = %d\n", multiplier->_times);

    PrePostChecker* prePostChecker = malloc(sizeof(PrePostChecker));
    _z14PrePostChecker4initF(prePostChecker);
    DefaultTextFormatter* pfmt[] = {
            (DefaultTextFormatter*)prePostDollarFixer,
            (DefaultTextFormatter*)multiplier,
            (DefaultTextFormatter*)prePostChecker
    };

    for (i = 0; i < 3; ++i)
        ((pPrintChar) ((((TextFormatter *)pfmt[i])->_vptr)[E_PRINT_CHAR]))(pfmt[i],"Hello World!");

    for (i = 2; i >= 0; --i)
    {
        ((pDestractor) ((((TextFormatter *)pfmt[i])->_vptr)[E_DESTRACTOR]))(pfmt[i]);
        free(pfmt[i]);
    }

    printf("\n--- end doFormatterPtrs() ---\n\n");
}
void _z23doFormatterDynamicArrayF()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");
    int i;

    DefaultTextFormatter* formatters = generateFormatterArray();

    for (i = 0; i < 3; ++i)
        _z20DefaultTextFormatter5printFKc(formatters+i,"Hello World!");

    for (i = 2; i >= 0; --i)
    {
        _z20DefaultTextFormatter10destractorF(formatters+i);
    }
    free(formatters);


    printf("\n--- end doFormatterDynamicArray() ---\n\n");
}


int main()
{
    printf("\n--- Start main() ---\n\n");

    PrePostHashFixer hfix;
    PrePostDollarFixer temp;

    _z14doPrePostFixerF();
    _z20doPrePostDollarFixerF();
    _z25doPrePostFloatDollarFixerF();
    _z16doPrePostCheckerF();

    _16PrePostHashFixer4initF(&hfix,4);
    _z20runAsPrePostFixerRefF((PrePostFixer *) &hfix);
    _z26runAsPrePostDollarFixerRefF((PrePostDollarFixer *) &hfix);
    _z18PrePostDollarFixer4copyF(&temp,(PrePostDollarFixer*)&hfix);
    _z26runAsPrePostDollarFixerObjF(temp);
    _z18PrePostDollarFixer10destractorF(&temp);
    _z24runAsPrePostHashFixerRefF(&hfix);

    _z12doMultiplierF();
    _z16doFormatterArrayF();
    _z15doFormatterPtrsF();
    _z23doFormatterDynamicArrayF();

    printf("\n--- End main() ---\n\n");
    _z16PrePostHashFixer10destractorF(&hfix);

    return 0;
}

