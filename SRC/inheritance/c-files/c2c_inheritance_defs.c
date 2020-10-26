
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
void _z11PhysicalBox4copyF(PhysicalBox* PhysicalBox1,const PhysicalBox* PhysicalBox2)
{
    _z3Box4copyF((Box*)PhysicalBox1,(Box*)PhysicalBox2);
    _z10Material_t4copyF((Material_t*)((char*)PhysicalBox1 + sizeof(Box)), (Material_t*)((char*)PhysicalBox2 + sizeof(Box)));

}
void _z11PhysicalBox6printp(PhysicalBox* PhysicalBox)
{
    printf("PhysicalBox, made of %s; ", names[PhysicalBox->_material._material]);
    _z3Box5printF((Box*)PhysicalBox);
}
void _z11PhysicalBox4initFddd(PhysicalBox* PhysicalBox,double l, double w, double h)
{
    _z3Box4initFddd((Box*)PhysicalBox,l,w,h);
    _z9Materials4initF((Materials*)(Material_t*)PhysicalBox);
    PhysicalBox->_material._material = OTHER;
    printf("Material created, set to %s\n",names[PhysicalBox->_material._material]);
    _z11PhysicalBox6printp(PhysicalBox);

}
void _z11PhysicalBox4initFdddT(PhysicalBox* PhysicalBox,double l, double w, double h,Types t)
{
    _z3Box4initFddd((Box*)PhysicalBox,l,w,h);
    _z9Materials4initF((Materials*)(Material_t*)PhysicalBox);
    PhysicalBox->_material._material = t;
    printf("Material created, set to %s\n",names[PhysicalBox->_material._material]);
    _z11PhysicalBox6printp(PhysicalBox);
}
void _z11PhysicalBox4initFT(PhysicalBox* PhysicalBox,Types t)
{
    _z3Box4initFd((Box*)PhysicalBox,1);
    _z9Materials4initF((Materials*)(Material_t*)PhysicalBox);
    PhysicalBox->_material._material = t;
    printf("Material created, set to %s\n",names[PhysicalBox->_material._material]);
    _z11PhysicalBox6printp(PhysicalBox);
}
void _z11PhysicalBox10destractorF(PhysicalBox* PhysicalBox)
{

    printf("PhysicalBox dtor, %f x %f x %f, %s; ", PhysicalBox->_box._length, PhysicalBox->_box._width,
           PhysicalBox->_box._height, names[PhysicalBox->_material._material]);
    _z10Material_t10destractorF((Material_t*)((char*)PhysicalBox + sizeof(Box)));
    _z3Box10destractorF((Box*)PhysicalBox);
}
PhysicalBox* _z11PhysicalBox10assignmentF(PhysicalBox* PhysicalBox1,const PhysicalBox* PhysicalBox2)
{
    if(PhysicalBox1 == PhysicalBox2)
        return PhysicalBox1;

    _z3Box10assignmentF((Box*)PhysicalBox1,(Box*)PhysicalBox2);
    _z10Material_t10assignmentF((Material_t*)((char*)PhysicalBox1 + sizeof(Box)),(Material_t*)((char*)PhysicalBox2 + sizeof(Box)));
    return PhysicalBox1;
}


