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

int main()
{
    printf("\n--- Start main() ---\n\n");

    _z11doMaterialsF();


    printf("\n--- End main() ---\n\n");

    return 0;

}