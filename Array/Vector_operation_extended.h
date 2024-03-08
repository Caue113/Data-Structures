#include <stdlib.h>
#include <stdio.h>

#include "Vector.h"

/**
 * @param index 0 based index access
*/
void Vector_int_insertAt(struct Vector_int *vector, int index, int value){
    
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

void Vector_int_insertBegin(struct Vector_int *vector, int value){
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

void Vector_int_deleteAt(struct Vector_int *vector, int index){
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


void Vector_int_deleteBegin(struct Vector_int *vector){
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
