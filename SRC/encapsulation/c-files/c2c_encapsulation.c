#include "c2c_encapsulation_defs.h"


static Box _z8largeBoxV;
int _z9flagBox99V = 0;
int _z9flagBox88V = 0;


void _z8thisFuncF()
{
    static Box box99;
    if(_z9flagBox99V == 2)
    {
        _z3Box10destractorF(&box99);
        return;
    }

    printf("\n--- thisFunc() ---\n\n");
    if(!_z9flagBox99V)
    {
        _z3Box4initFd(&box99,99);
        _z9flagBox99V++;
    }
    _z3Box8multEqualFd(&box99,10);

}

void _z8thatFuncF()
{
    static Box box88;
    if(_z9flagBox88V == 2)
    {
        _z3Box10destractorF(&box88);
        return;
    }
    printf("\n--- thatFunc() ---\n\n");
    if(!_z9flagBox88V)
    {
        _z3Box4initFd(&box88,88);
        _z9flagBox88V++;
    }
    _z3Box8multEqualFd(&box88,10);

}

void _z7doBoxesF()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1,b2,b3,b4,ret;
    _z3Box4initFd(&b1,3);
    _z3Box4initFddd(&b2,4,5,6);

    printf("b1 volume: %f\n", b1._length*b1._width*b1._height);
    printf("b2 volume: %f\n", b2._length*b2._width*b2._height);

    _z3Box8multEqualFd(&b1,1.5);
    _z3Box8multEqualFd(&b2,0.5);

    printf("b1 volume: %f\n",  b1._length*b1._width*b1._height);
    printf("b2 volume: %f\n", b2._length*b2._width*b2._height);

    _z3Box10assignmentF(&b3, &b2);
    _z3Box10assignmentF(&ret, &b2);
    _z3Box8multEqualFd(&ret,3);
    _z3Box10assignmentF(&b4, &ret);
    printf("b3 %s b4\n", b3._height == b4._height && b3._width == b4._width
                         && b3._length == b4._length ? "equals" : "does not equal");

    _z3Box8multEqualFd(&b3,1.5);
    _z3Box8multEqualFd(&b4,0.5);

    printf("Now,b3 %s b4\n", b3._height == b4._height && b3._width == b4._width
                             && b3._length == b4._length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    _z3Box10destractorF(&b4);
    _z3Box10destractorF(&b3);
    _z3Box10destractorF(&b2);
    _z3Box10destractorF(&b1);
}

void _z9doShelvesF()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox,ret,b,b1;
    _z3Box4initFd(&ret,5);
    _z3Box10assignmentF(&aBox, &ret);
    Shelf aShelf;
    _z5Shelf4initF(&aShelf);
    _z5Shelf5printF(&aShelf);
    _z5Shelf6setBoxiKb(&aShelf,1, &_z8largeBoxV);
    _z5Shelf6setBoxiKb(&aShelf,0, &aBox);

    _z5Shelf5printF(&aShelf);
    _z5Shelf7message = "This is the total volume on the shelf:";
    _z5Shelf5printF(&aShelf);
    _z5Shelf7message = "Shelf's volume:";
    _z5Shelf5printF(&aShelf);

    _z3Box4initFddd(&b,2,4,6);
    _z5Shelf6setBoxiKb(&aShelf,1, &b);
    _z3Box10destractorF(&b);

    _z3Box4initFd(&b1,2);
    _z5Shelf6setBoxiKb(&aShelf,2, &b1);
    _z3Box10destractorF(&b1);
    _z5Shelf5printF(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    _z3Box10destractorF(&aShelf.boxes[2]);
    _z3Box10destractorF(&aShelf.boxes[1]);
    _z3Box10destractorF(&aShelf.boxes[0]);
    _z3Box10destractorF(&aBox);
}

int main()
{
    _z3Box4initFddd(&_z8largeBoxV, 10, 20, 30);
    printf("\n--- Start main() ---\n\n");
    _z7doBoxesF();
    _z8thisFuncF();
    _z8thisFuncF();
    _z8thisFuncF();
    _z8thatFuncF();
    _z8thatFuncF();
    _z9doShelvesF();


    printf("\n--- End main() ---\n\n");
    _z3Box10destractorF(&_z8largeBoxV);

    return 0;
}

