

#ifndef BOX_SHELF_C2C_ENCAPSULATION_DEFS_H
#define BOX_SHELF_C2C_ENCAPSULATION_DEFS_H
#define NUM_BOXES 3
#include <stdio.h>
#include <string.h>

typedef struct Box{
    double _length;
    double _width;
    double _height;
}Box;

typedef struct Shelf{

    Box boxes[NUM_BOXES];
}Shelf;


extern const char* _z5Shelf7message;

void _z3Box4initFddd(Box* box,double length,double width,double height);
void _z3Box4initFd(Box* box,double dim);
void _z3Box4initF(Box* box);
void _z3Box4copyF(Box* box1, const Box* box2);
Box* _z3Box8multEqualFd(Box* box,double mult);
void _z3Box10destractorF(Box* box);
void _z3Box5printF(Box* box);
Box* _z3Box10assignmentF(Box* box1, const Box* box2);
void _z5Shelf4initF(Shelf *shelf);
void _z5Shelf6setBoxiKb(Shelf* shelf,int index, const Box* dims);
double _z5Shelf9getVolumeF(Shelf* shelf);
void _z5Shelf5printF(Shelf* shelf);



#endif
