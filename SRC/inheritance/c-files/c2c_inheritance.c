#include "c2c_inheritance_defs.h"

void _z11doMaterialsF()
{
    typedef struct MatTest { Materials mat; Material_t mat_t;char c; }MatTest;
    printf("\n--- Start doMaterials() ---\n\n");

    Materials mat;
    printf("Size of Materials: %lu\n", sizeof(Materials)+1);
    printf("Size of mat: %lu\n", sizeof(mat)+1);
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));


    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    Material_t mat1,mat2;
    _z9Materials4initF(&mat1._materials);
    mat1._material = OTHER;
    printf("Material created, set to %s\n", names[mat1._material]);
    _z9Materials4initF(&mat2._materials);
    mat2._material = METAL;
    printf("Material created, set to %s\n",names[mat2._material]);


    printf("\n--- End doMaterials() ---\n\n");
    _z10Material_t10destractorF(&mat2);
    _z10Material_t10destractorF(&mat1);
    _z9Materials10destractorF(&mat);
}
void _z13doPhysicalBoxF()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");
    PhysicalBox pb1,pb2,pb3,pb4;
    _z11PhysicalBox4initFdddT(&pb1,8, 6, 4, PLASTIC);
    _z11PhysicalBox4initFT(&pb2,WOOD);
    _z11PhysicalBox4initFddd(&pb3,7,7,7);
    printf("\npb4 is copy-constructed from pb1\n");
    _z11PhysicalBox4copyF(&pb4,&pb1);
    _z11PhysicalBox6printp(&pb4);
    _z11PhysicalBox6printp(&pb1);
    printf("pb4 %s pb1\n", pb4._box._height == pb1._box._height && pb4._box._width == pb1._box._width
                           && pb4._box._length == pb1._box._length && pb4._material._material == pb1._material._material ? "equals" : "does not equal");
    printf("\npb4 is copy-assigned from pb3\n");
    _z11PhysicalBox10assignmentF(&pb4,&pb3);
    _z11PhysicalBox6printp(&pb4);
    _z11PhysicalBox6printp(&pb3);
    printf("pb4 %s pb3\n", pb4._box._height == pb3._box._height && pb4._box._width == pb3._box._width
                           && pb4._box._length == pb3._box._length && pb4._material._material == pb3._material._material ? "equals" : "does not equal");
    printf("\n--- End doPhysicalBox() ---\n\n");
    _z11PhysicalBox10destractorF(&pb4);
    _z11PhysicalBox10destractorF(&pb3);
    _z11PhysicalBox10destractorF(&pb2);
    _z11PhysicalBox10destractorF(&pb1);
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    _z11doMaterialsF();

    _z13doPhysicalBoxF();


    printf("\n--- End main() ---\n\n");

    return 0;

}