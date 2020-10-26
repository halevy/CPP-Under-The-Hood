
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

typedef struct PhysicalBox
{
    Box _box;
    Material_t _material;
}PhysicalBox;

typedef struct  WeightBox
{
    Box _box;
    double _weight;
}WeightBox;

void _z9Materials4initF(Materials* materials);
void _z9Materials10destractorF(Materials* materials);
void _z9Materials4copyF(Materials* materials1,const Materials* materials2);
Materials* _z9Materials10assignmentF(Materials* materials1,const Materials* materials2);
void _z10Material_t10destractorF(Material_t* material_t);
void _z10Material_t4copyF(Material_t* material_t1,const Material_t* material_t2);
Material_t* _z10Material_t10assignmentF(Material_t* material_t1,const Material_t* material_t2);

void _z11PhysicalBox4copyF(PhysicalBox* PhysicalBox1,const PhysicalBox* PhysicalBox2);
void _z11PhysicalBox6printp(PhysicalBox* PhysicalBox);
void _z11PhysicalBox4initFddd(PhysicalBox* PhysicalBox,double l, double w, double h);
void _z11PhysicalBox4initFdddT(PhysicalBox* PhysicalBox,double l, double w, double h,Types t);
void _z11PhysicalBox4initFT(PhysicalBox* PhysicalBox,Types t);
void _z11PhysicalBox10destractorF(PhysicalBox* PhysicalBox);
PhysicalBox* _z11PhysicalBox10assignmentF(PhysicalBox* PhysicalBox1,const PhysicalBox* PhysicalBox2);

void _z9WeightBox4initFdddd(WeightBox* weightBox,double l, double w, double h,double wgt/* = 0.0*/);
void _z9WeightBox4copyF(WeightBox* weightBox1,const WeightBox* weightBox2);
void _z9WeightBox10destractorF(WeightBox* weightBox);
WeightBox* _z9WeightBox10assignmentF(WeightBox* weightBox1,const WeightBox* weightBox2);
void _z9WeightBoxprintw(WeightBox* weightBox);

#endif
