
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


int main()
{
    printf("\n--- Start main() ---\n\n");

    _z14doPrePostFixerF();
    _z20doPrePostDollarFixerF();

    printf("\n--- End main() ---\n\n");


    return 0;
}
