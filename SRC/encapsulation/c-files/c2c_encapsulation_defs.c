
#include "c2c_encapsulation_defs.h"

/*   Box  */


void _z3Box4initF(Box* box)
{
    box->_length = 1;
    box->_width = 1;
    box->_height = 1;
    _z3Box5printF(box);
}
void _z3Box4initFd(Box* box,double dim)
{
    box->_length = dim;
    box->_width = dim;
    box->_height = dim;
    _z3Box5printF(box);

}

void _z3Box4initFddd(Box* box,double length,double width,double height)
{
    box->_length = length;
    box->_width = width;
    box->_height = height;
    _z3Box5printF(box);

}
void _z3Box4copyF(Box* box1, const Box* box2)
{
    memcpy(box1,box2, sizeof(Box));
}
void _z3Box5printF(Box* box)
{
    printf("Box: %f x %f x %f\n", box->_length, box->_width, box->_height);
}
Box* _z3Box8multEqualFd(Box* box,double mult)
{
    box->_length *= mult;
    box->_width *= mult;
    box->_height *= mult;
    return box;
}
void _z3Box10destractorF(Box* box)
{
    printf("Box destructor, %f x %f x %f\n",box->_width, box->_height,box->_length );
}
Box* _z3Box10assignmentF(Box* box1, const Box* box2)
{
    if(box1 == box2)
        return box1;
    box1->_length = box2->_length;
    box1->_width = box2->_width;
    box1->_height = box2->_height;
    return box1;
}


/*  Shelf   */
const char* _z5Shelf7message = "The total volume held on the shelf is";

void _z5Shelf4initF(Shelf *shelf)
{
    int i = 0;
    for (; i < 3; ++i){
        _z3Box4initF(&shelf->boxes[i]);
    }
}

void _z5Shelf6setBoxiKb(Shelf* shelf,int index, const Box* dims)
{
    _z3Box10assignmentF(&(shelf->boxes[index]), dims);
}
double _z5Shelf9getVolumeF(Shelf* shelf)
{
    double vol = 0;
    size_t i;
    for (i = 0; i < NUM_BOXES; ++i)
        vol += (shelf->boxes[i]._length*shelf->boxes[i]._width*shelf->boxes[i]._height);

    return vol;
}
void _z5Shelf5printF(Shelf* shelf)
{
    printf("%s %f\n", _z5Shelf7message, _z5Shelf9getVolumeF(shelf));
}







