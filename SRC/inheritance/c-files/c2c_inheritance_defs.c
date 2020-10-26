
#include "c2c_inheritance_defs.h"


const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

void _z9Materials4initF(Materials* materials){}
void _z9Materials10destractorF(Materials* materials){}
void _z9Materials4copyF(Materials* materials1,const Materials* materials2){}
Materials* _z9Materials10assignmentF(Materials* materials1,const Materials* materials2){}
void _z10Material_t10destractorF(Material_t* material_t)
{
    _z9Materials10destractorF((Materials*)material_t);
}
void _z10Material_t4copyF(Material_t* material_t1,const Material_t* material_t2)
{
    _z9Materials4initF((Materials*)material_t1);
    memcpy((Types*)((char*)material_t1 + sizeof(Materials)),(Types*)((char*)material_t2 + sizeof(Materials)), sizeof(Material_t));
}
Material_t* _z10Material_t10assignmentF(Material_t* material_t1,const Material_t* material_t2)
{
    if(material_t1 == material_t2)
        return material_t1;
    _z9Materials10assignmentF((Materials*)material_t1,(Materials*)material_t2);
    memcpy((Types*)((char*)material_t1 + sizeof(Materials)),(Types*)((char*)material_t2 + sizeof(Materials)), sizeof(Material_t));
    return material_t1;
}

