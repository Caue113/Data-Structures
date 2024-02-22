#include <stdio.h>
#include <stdlib.h>

int *array_bubblesort_ascend(int *array, int length){
    if(length < 1){
        printf("[bubblesort] Array Size not Valid");
        return array;
    }
    
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 1; j < length; j++)
        {
            int temp = 0;
            if(array[j] < array[j-1]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
    return array;
}

int *array_bubblesort_descend(int *array, int length){
    if(length < 1){
        printf("[bubblesort] Array Size not Valid");
        return array;
    }
    
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 1; j < length; j++)
        {
            int temp = 0;
            if(array[j] > array[j-1]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
    return array;
}

void array_transverse(int *array, int length){
    printf("The array is\n\t{");
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("}\n");
    
}

int main(int argc, char const *argv[])
{
    int array_size = 5;
    int *arr1 = malloc(sizeof(int) * array_size);
    arr1[0] = 18;
    arr1[1] = 55535;
    arr1[2] = 0;
    arr1[3] = 2;
    arr1[4] = 75;

    //Show unsorted. Expects: 18, 55535, 0, 2, 75
    array_transverse(arr1, array_size);

    printf("Showing sorted array\n");

    //Expects: 0 2 18 75 55535
    array_bubblesort_ascend(arr1, array_size);
    array_transverse(arr1, array_size);


    //Find Kth lower value. 
    int kLowerValue = 3;
    //Expects 18
    printf("%dth lower value is: %d\n", kLowerValue, arr1[kLowerValue - 1]);

    //Find Kth bigger value.
    int kHigherValue = 2;
    //Expects 75
    printf("%dth larger value is: %d\n", kHigherValue, arr1[array_size - kHigherValue]);
    return 0;
}
