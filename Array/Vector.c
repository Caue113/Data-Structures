#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

typedef struct Vector_int Vector_int;


void Vector_int_display_values(Vector_int *vector){
    printf("Vector Values\n");
    if(vector->isEmpty(vector) == 1){
        printf("Vector is empty\n");    
    }
    else{
        printf("Index \t| \tValue\n");
        for (size_t i = 0; i < vector->length; i++)
        {
            printf("%d \t| \t%d\n",i, vector->values[i]);
        }
    }
}

void Vector_int_display(Vector_int *vector){
    printf("Printing Vector\n");

    printf("Length: \t%d\n", vector->length);
    printf("Capacity: \t%d\n", vector->capacity);
    printf("isEmpty: \t%d\n", vector->isEmpty(vector));
}

void Vector_int_display_all(Vector_int *vector){
    printf("Printing Vector\n");

    printf("Length: \t%d\n", vector->length);
    printf("Capacity: \t%d\n", vector->capacity);
    printf("isEmpty: \t%d\n", vector->isEmpty(vector));

    Vector_int_display_values(vector);
}



int main(int argc, char const *argv[])
{   
    printf("# Test switch 1 - Vector creation\n");
    printf("## Description: vector capacity to be the next base 2^n number\n");

    printf("\n--- Expects {2, 4, 4, 8, 16, 32}\n");
    Vector_int *vec1 = Vector_int_create(1);
    Vector_int *vec2 = Vector_int_create(2);
    Vector_int *vec3 = Vector_int_create(3);
    Vector_int *vec4 = Vector_int_create(5);
    Vector_int *vec5 = Vector_int_create(11);
    Vector_int *vec6 = Vector_int_create(27);


    Vector_int_display(vec1);
    Vector_int_display(vec2);
    Vector_int_display(vec3);
    Vector_int_display(vec4);
    Vector_int_display(vec5);
    Vector_int_display(vec6);

    printf("\n--- Expects {2, 4, 4, 8, 16, 32}\n");

    printf("\n===========\n\n");

    printf("# Test switch 2 - Insertion and increase resizing\n");
    printf("## Expects Capacity to be [2, 2, 4, 8]\n");

    Vector_int_display(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 1);

    Vector_int_display(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 2);

    Vector_int_display(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 3);
    Vector_int_display(vec1);

    printf("\n===========\n\n");

    printf("# Test switch 3 - Deletion and decrease resizing\n");
    printf("## Expects Capacity to be [8, 6, 4, 2]\n");

    Vector_int_display(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);


    printf("\n===========\n\n");

    printf("# Test switch 4 - Stress Test Insert many values\n");    
    
    for (size_t i = 0; i < 512; i++)
    {
        Vector_int_insert(vec1, rand());
    }

    Vector_int_display_values(vec1);
    Vector_int_display(vec1);

    //cleanup
    for (size_t i = 0; i < 512; i++)
    {
        Vector_int_delete(vec1);
    }

    //==================================//

    for (size_t i = 0; i < (2<<15); i++)
    {
        Vector_int_insert(vec1, rand());
    }

    Vector_int_display_values(vec1);
    Vector_int_display(vec1);

    //cleanup
    for (size_t i = 0; i < (2<<15); i++)
    {
        Vector_int_delete(vec1);
    }
    
    //Cleanup
    Vector_int_destroy(vec1);
    Vector_int_destroy(vec2);
    Vector_int_destroy(vec3);
    Vector_int_destroy(vec4);
    Vector_int_destroy(vec5);
    Vector_int_destroy(vec6);
    return 0;
}
