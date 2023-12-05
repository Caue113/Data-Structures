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
void resize(Vector_int *vector, int operation){ 
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
}

void insert(Vector_int *vector, int value){
    vector->values[vector->length] = value;
    vector->length++;

    if(vector->capacity - vector->length <= vector->capacity / 4){
        vector->resize(vector, 1);
    }
}

/**
 * @param index 0 based index access
*/
void insertAt(Vector_int *vector, int index, int value){
    
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
void insertBegin(Vector_int *vector, int value){
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

void delete(Vector_int *vector){
    if(vector->length == 0){
        printf("Error - Vector is Empty\n");
        return;
    }

    //By simply restricting access, we "reduce" the vector size. Although, the data still exist.
    vector->length--;

    if(vector->capacity - vector->length >= vector->capacity / 4){
        vector->resize(vector, 0);
    }
    
}
/**
 * 
*/
void deleteAt(Vector_int *vector, int index){
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
void deleteBegin(Vector_int *vector){
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
    //Vector_int vecSub = {malloc(sizeof(int)*5), 0, 5*1.5, find, insert, insertAt, insertBegin, delete, deleteAt, deleteBegin, resize, isEmpty, displayValues};
    
    Vector_int *newVec = newVector(10);
    Vector_int *vec1 = newVector(2);

    newVec->insert(newVec, 1);
    newVec->insert(newVec, 4);
    newVec->insert(newVec, 6);
    newVec->displayValues(newVec);

    insert(vec1, 333);
    displayValues(vec1);
    deleteBegin(vec1);
    displayValues(vec1);
    insert(vec1, 2123);
    insert(vec1, 11);
    displayValues(vec1);
    insertAt(vec1, 1, 9999);
    displayValues(vec1);
    deleteAt(vec1, 2);
    displayValues(vec1);
    insert(vec1, 1);
    displayValues(vec1);
    insertBegin(vec1, 3434);
    displayValues(vec1);
    insertBegin(vec1, 69);
    insertBegin(vec1, 1337);
    displayValues(vec1);



    destructVector(newVec);
    destructVector(vec1);
    return 0;
}
