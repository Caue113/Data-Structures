#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_int{
    int *values;
    int length;     //N. elements
    int capacity;
    int (*find)(struct Vector_int *vector, int value);
    void (*insert)(struct Vector_int *vector, int value);
    void (*insertAt)(struct Vector_int *vector, int index, int value);
    void (*insertBegin)(struct Vector_int *vector, int value);
    void (*delete)(struct Vector_int *vector);
    void (*deleteAt)(struct Vector_int *vector, int index);
    void (*deleteBegin)(struct Vector_int *vector);
    void (*resize)(struct Vector_int *vector, int operation);
    int (*isEmpty)(struct Vector_int *vector);

    void (*displayValues)(struct Vector_int *vector);
} Vector_int;

/**Returns the first index containing the value*/
int Vector_int_find(Vector_int *vector, int value){
    for (size_t i = 0; i < vector->length; i++){
        if(vector->values[i] == value){
            return i;
        }
    }

    return -1;
}

/**
 * @param operation 1 - increase. 0 - decrease
 * @todo Study increasing factor
*/
void Vector_int_resize(Vector_int *vector, int operation){ 
    int newCapacity = 0;

    if(operation == 1){
        newCapacity = vector->capacity * 2;
    }
    else if(operation == 0){
        newCapacity = vector->capacity / 2 + vector->length;
    }

    int *newValues = malloc(sizeof(int)*newCapacity);

    for (size_t i = 0; i < vector->length; i++)
    {
        newValues[i] = vector->values[i];
    }

    free(vector->values);
    vector->values = newValues;
    vector->capacity = newCapacity;
}

void Vector_int_insert(Vector_int *vector, int value){
    vector->values[vector->length] = value;
    vector->length++;

    //The remaining spaces are smaller than 25% threshhold?
    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}

/**
 * @param index 0 based index access
*/
void Vector_int_insertAt(Vector_int *vector, int index, int value){
    
    //We use length instead of capacity due to unknown behavior between indexes (fill with 0? NULL?)
    if(index > vector->length - 1 || index < 0){
        printf("Error - IndexOutOfBounds\n");
        return;
    }

    vector->length++;
    for (size_t i = vector->length; i > index; i--)
    {
        vector->values[i] = vector->values[i-1];
    }
    vector->values[index] = value;

    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}

/**
 * 
*/
void Vector_int_insertBegin(Vector_int *vector, int value){
    vector->length++;
    for (size_t i = vector->length; i > 0; i--)
    {
        vector->values[i] = vector->values[i-1];
    }
    vector->values[0] = value;

    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}

void Vector_int_delete(Vector_int *vector){
    if(vector->length == 0){
        printf("Error - Vector is Empty\n");
        return;
    }

    //By simply restricting access, we "reduce" the vector size. Although, the data still exist.
    //Todo: Clear data (this case: set to null)
    vector->length--;

    if(vector->capacity - vector->length >= vector->capacity / 4){
        vector->resize(vector, 0);
    }
    
}
/**
 * 
*/
void Vector_int_deleteAt(Vector_int *vector, int index){
    if(vector->length == 0){
        printf("Error - Vector is Empty\n");
        return;
    }

    if(index > vector->length - 1 || index < 0){
        printf("Error - IndexOutOfBounds\n");
        return;
    }


    vector->length--;
    //Hard override all data. Although, values[length] still exist
    for (size_t i = index; i < vector->length; i++){
        vector->values[i] = vector->values[i+1];
    }
}
/**
 *
*/
void Vector_int_deleteBegin(Vector_int *vector){
    if(vector->length == 0){
        printf("Error - Vector is Empty\n");
        return;
    }
   
    //Hard override all data. Although, values[length] still exist.
    for (size_t i = 0; i < vector->length; i++){
        vector->values[i] = vector->values[i+1];
    }

    vector->length--;
}


/**
 * @return 1 - true; 0 false
*/
int Vector_int_isEmpty(Vector_int *vector){
    if(vector->length == 0){
        return 1;
    }
    return 0;
}

void Vector_int_display_values(Vector_int *vector){
    printf("Printing Vector\n");

    printf("Length: \t%d\n", vector->length);
    printf("Capacity: \t%d\n", vector->capacity);
    printf("isEmpty: \t%d\n", vector->isEmpty(vector));

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

/**
 * 
*/
Vector_int *Vector_int_create(int capacity){
    /* Vector_int *vec = malloc(sizeof(Vector_int));     */
    if(capacity < 1){
        printf("Error - CapacityOutOfBounds\n");
    }
    else{

        Vector_int *vec = malloc(sizeof(Vector_int));

        //Find capacity closest a base 2^n
        int newCapacity = 0;
        int numResizes = 0;

        while (capacity >> numResizes > 0)
        {
            numResizes++;
        }

        newCapacity = 1 << numResizes;  //2^0 * 2^n
        

        *vec = (Vector_int){
            .values = malloc(sizeof(int)*newCapacity),
            .length = 0,
            .capacity = newCapacity,

            .find = Vector_int_find,
            .insert = Vector_int_insert,
            .insertAt = Vector_int_insertAt,
            .insertBegin = Vector_int_insertBegin,
            .delete = Vector_int_delete,
            .deleteAt = Vector_int_deleteAt,
            .deleteBegin = Vector_int_deleteBegin,
            .resize = Vector_int_resize,
            .displayValues = Vector_int_display_values,
            .isEmpty = Vector_int_isEmpty,
        };

        return vec;
    }
    
}

void Vector_int_destroy(Vector_int *vector){
    free(vector->values);
    free(vector);
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

    vec1->displayValues(vec1);
    vec2->displayValues(vec2);
    vec3->displayValues(vec3);
    vec4->displayValues(vec4);
    vec5->displayValues(vec5);
    vec6->displayValues(vec6);
    
    printf("\n===========\n\n");

    printf("# Test switch 2 - Insertion and increase resizing\n");
    printf("## Expects Capacity to be [2, 2, 4, 8]\n");

    Vector_int_display_values(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 1);

    Vector_int_display_values(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 2);

    Vector_int_display_values(vec1);
    printf("> Insert\n");
    Vector_int_insert(vec1, 3);
    Vector_int_display_values(vec1);

    printf("\n===========\n\n");

    printf("# Test switch 3 - Deletion and decrease resizing\n");
    printf("## Expects Capacity to be [8, 6, 4, 2]\n");

    Vector_int_display_values(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display_values(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display_values(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_display_values(vec1);
    printf("> Delete\n");
    Vector_int_delete(vec1);

    Vector_int_destroy(vec1);
    Vector_int_destroy(vec2);
    Vector_int_destroy(vec3);
    Vector_int_destroy(vec4);
    Vector_int_destroy(vec5);
    Vector_int_destroy(vec6);
    return 0;
}
