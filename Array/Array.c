#include <stdio.h>
#include <stdlib.h>

/**
 * Array is similar to Vector. Wont implement
*/

typedef struct Array_int{
    int length;     //N. elements
    int *values;
    int (*isEmpty)();
} Array_int;

/**Returns the first index containing the value*/
void find(Array_int *vector, int value){

    for (size_t i = 0; i < vector->length; i++)
    {
        /* code */
    }
    
    return -1;
}

void insert(Array_int *vector, int value){
    if(vector->length);
}

void remove(Array_int *vector){

}

/**
 * @param mode 0 decrease. 1 increase.
*/
void resize(Array_int *vector, int mode){
    int newLength = vector->length;

    if(mode == 0){
        if(newLength < 1){
            printf("Error: Cannot Decrease Length Below 1");
            return;
        }
        newLength--;
    }
    else if(mode == 1){
        newLength++;
    }

    Array_int *newArr = newArray(newLength);
}

int isEmpty(Array_int *vector){
    if(vector->length == 0){
        return 1;
    }
    else{
        return 0;
    }
}


Array_int *newArray(int length){
    Array_int *arr = malloc(sizeof(Array_int));
    arr->values = malloc(sizeof(int) * length);
    arr->length = length;

    return arr;
}

void destructArray(Array_int *vector){
    free(vector);
    free(vector->values);
}


void transverse_array(int *array){
    printf("Array value of: %d", array);
}


int main(int argc, char const *argv[])
{
   

    return 0;
}
