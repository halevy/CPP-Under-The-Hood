
#ifndef BOX_SHELF_C2C_INHERITANCE_DEFS_H
#define BOX_SHELF_C2C_INHERITANCE_DEFS_H

#include "c2c_encapsulation_defs.h"

extern const char* const names[];

typedef enum
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct Materials
{
}Materials;

typedef struct Material_t
{
    Materials _materials;
    Types _material;
}Material_t;


void _z9Materials4initF(Materials* materials);
void _z9Materials10destractorF(Materials* materials);
void _z9Materials4copyF(Materials* materials1,const Materials* materials2);
Materials* _z9Materials10assignmentF(Materials* materials1,const Materials* materials2);
void _z10Material_t10destractorF(Material_t* material_t);
void _z10Material_t4copyF(Material_t* material_t1,const Material_t* material_t2);
Material_t* _z10Material_t10assignmentF(Material_t* material_t1,const Material_t* material_t2);


#endif
