#include <stdio.h>
#include <stdlib.h>

typedef struct Array_int{
    int *values;
    int length;     //N. elements
    int (*isEmpty)();
} Array_int;

/**Returns the first index containing the value*/
void find(Array_int *vector, int value){

    return -1;
}

void insert(Array_int *vector, int value){

}

void remove(Array_int *vector){

}

void resize(Array_int *vector){

}

void isEmpty(Array_int *vector){

}


Array_int *newArray(int *values){
    Array_int arr = {values, 0};
    return &arr;
}


void transverse_array(int *array){
    printf("Array value of: %d", array);
}


int main(int argc, char const *argv[])
{
   

    return 0;
}
