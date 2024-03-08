#include <stdio.h>
#include <stdlib.h>

#include "Vector_interface.h"

struct Vector_int{
    int *values;
    int length;     //N. elements
    int capacity;
    void (*resize)(struct Vector_int *vector, int operation);
    void (*insert)(struct Vector_int *vector, int value);
    void (*delete)(struct Vector_int *vector);
    int (*find)(struct Vector_int *vector, int value);
    int (*isEmpty)(struct Vector_int *vector);

    /* void (*deleteAt)(struct Vector_int *vector, int index);
    void (*deleteBegin)(struct Vector_int *vector);
    void (*insertAt)(struct Vector_int *vector, int index, int value);
    void (*insertBegin)(struct Vector_int *vector, int value); */
    
    void (*displayValues)(struct Vector_int *vector);
};

int Vector_int_find(struct Vector_int *vector, int value){
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
void Vector_int_resize(struct Vector_int *vector, int operation){ 
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

void Vector_int_insert(struct Vector_int *vector, int value){
    vector->values[vector->length] = value;
    vector->length++;

    //The remaining spaces are smaller than 25% threshhold?
    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}

void Vector_int_delete(struct Vector_int *vector){
    if(vector->length == 0){
        printf("Error - Vector is Empty\n");
        return;
    }
    
    //By simply restricting access, we "reduce" the vector size. Although, the data still exist.
    //Todo: Clear data (this case: set to null)
    vector->values[vector->length-1] = NULL;
    vector->length--;

    if(vector->capacity - vector->length >= vector->capacity / 4){
        vector->resize(vector, 0);
    }
    
}

int Vector_int_isEmpty(struct Vector_int *vector){
    if(vector->length == 0){
        return 1;
    }
    return 0;
}

struct Vector_int *Vector_int_create(int capacity){
    /* Vector_int *vec = malloc(sizeof(Vector_int));     */
    if(capacity < 1){
        printf("Error - CapacityOutOfBounds\n");
    }
    else{

        struct Vector_int *vec = malloc(sizeof(struct Vector_int));

        //Find capacity closest a base 2^n
        int newCapacity = 0;
        int numResizes = 0;

        while (capacity >> numResizes > 0)
        {
            numResizes++;
        }

        newCapacity = 1 << numResizes;  //2^0 * 2^n
        

        *vec = (struct Vector_int){
            .values = malloc(sizeof(int)*newCapacity),
            .length = 0,
            .capacity = newCapacity,

            .find = Vector_int_find,
            .insert = Vector_int_insert,
            .delete = Vector_int_delete,
            .resize = Vector_int_resize,
            .isEmpty = Vector_int_isEmpty,
        };

        return vec;
    }
    
}

void Vector_int_destroy(struct Vector_int *vector){
    free(vector->values);
    free(vector);
}