#include <stdio.h>
#include <stdlib.h>

typedef struct Vector_int{
    int *values;
    int length;     //N. elements
    int capacity;
    int (*find)();
    void (*insert)();
    void (*insertAt)();
    void (*insertBegin)();
    void (*delete)();
    void (*deleteAt)();
    void (*deleteBegin)();
    void (*resize)();
    int (*isEmpty)();

    void (*displayValues)();
} Vector_int;

/**Returns the first index containing the value*/
int find(Vector_int *vector, int value){
    for (size_t i = 0; i < vector->length; i++)
    {
        if(vector->values[i] == value){
            return vector->values[i];
        }
    }

    return -1;
}

/**
 * @param shouldIncrease Boolean to define resize behavior. It prevents constant unwanted resizes. (1 = true, 0 = false)
 * @todo Study increasing factor
*/
void resize(Vector_int *vector, int shouldIncrease){
    int newCapacity = 0;

    if(shouldIncrease == 1){
        newCapacity = vector->capacity * 2;
    }
    else if(shouldIncrease == 0 && vector->length < vector->capacity / 2){
        newCapacity = vector->capacity / 2 + vector->length;
    }

    int *newValues = malloc(sizeof(int)*newCapacity);

    for (size_t i = 0; i < vector->length; i++)
    {
        newValues[i] = vector->values[i];
    }

    free(vector->values);
    vector->values = newValues;
}

void insert(Vector_int *vector, int value){
    vector->values[vector->length] = value;
    vector->length++;

    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}
void insertAt(Vector_int *vector, int index, int value){}
void insertBegin(Vector_int *vector, int value){}

void delete(Vector_int *vector){
    if (vector->length > 0){
        vector->length--;
        vector->values[vector->length] = NULL;

        if(vector->capacity - vector->length >= vector->capacity / 4){
            vector->resize(vector, 0);
        }
    }
}
void deleteAt(Vector_int *vector){}
void deleteBegin(Vector_int *vector){}


/**
 * @return 1 - true; 0 false
*/
int isEmpty(Vector_int *vector){
    if(vector->length == 0){
        return 1;
    }
    return 0;
}

void displayValues(Vector_int *vector){
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
Vector_int *newVector(int capacity){
    /* Vector_int *vec = malloc(sizeof(Vector_int));     */
    if(capacity < 1){
        printf("Error - CapacityOutOfBounds\n");
    }
    else{

        Vector_int *vec = malloc(sizeof(Vector_int));

        *vec = (Vector_int){
            .values = malloc(sizeof(int)*capacity),
            .length = 0,
            .capacity = capacity * 1.5f,

            .find = find,
            .insert = insert,
            .insertAt = insertAt,
            .insertBegin = insertBegin,
            .delete = delete,
            .deleteAt = deleteAt,
            .deleteBegin = deleteBegin,
            .resize = resize,
            .displayValues = displayValues,
            .isEmpty = isEmpty,
        };

        return vec;
    }
    
}

void destructVector(Vector_int *vector){
    free(vector->values);
    free(vector);
}

int main(int argc, char const *argv[])
{
    Vector_int vecSub = {malloc(sizeof(int)*5), 0, 5*1.5, find, insert, insertAt, insertBegin, delete, deleteAt, deleteBegin, resize, isEmpty, displayValues};
    
    Vector_int *newVec = newVector(10);

    newVec->insert(newVec, 1);
    newVec->insert(newVec, 4);
    newVec->insert(newVec, 6);
    newVec->insert(newVec, 111);
    newVec->displayValues(newVec);
    newVec->delete(newVec);
    newVec->delete(newVec);
    newVec->displayValues(newVec);
    newVec->delete(newVec);
    newVec->delete(newVec);
    newVec->displayValues(newVec);
    //Expect nothing here
    newVec->delete(newVec);

    
    /* vecSub.insert(&vecSub, 2);
    vecSub.insert(&vecSub, 5);
    vecSub.insert(&vecSub, 18);
    vecSub.insert(&vecSub, 1);

    vecSub.displayValues(&vecSub);

    vecSub.delete(&vecSub);

    vecSub.displayValues(&vecSub); */

    free(vecSub.values);
    destructVector(newVec);
    return 0;
}
