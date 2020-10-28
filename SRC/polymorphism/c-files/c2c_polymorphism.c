
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

int main()
{
    printf("\n--- Start main() ---\n\n");

    _z14doPrePostFixerF();
    _z20doPrePostDollarFixerF();
    _z25doPrePostFloatDollarFixerF();
    _z16doPrePostCheckerF();
    
    return 0;
}

