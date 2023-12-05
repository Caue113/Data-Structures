#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expectsAllToBeEqual(int *array, int len, int *truthArray, int truthLen){
    if(len != truthLen){
        printf("Lengths are different\n");
    }
    if(truthLen < len){
        printf("Error: Length not compatible Exception. Array is bigger than truth\n");
        return -1;
    }

    for (size_t i = 0; i < len; i++)
    {
        if(array[i] == truthArray[i]){
            printf("array1[%d] = %d is equal to both\n", i, array[i]);
        }
        else{
            printf("Not Equal -> array1[%d] = %d | Truth[%d] = %d.\n", i, array[i], i, truthArray[i]);
            return 0;
        }
    }

    return 1;
}

int expectsToBeEqual(int value, int checkValue){
    return value == checkValue;
}




int main(int argc, char const *argv[])
{
    printf("is 1 equal to 1 - %d\n", expectsToBeEqual(1, 1));
    printf("is 1 equal to -65 - %d\n", expectsToBeEqual(1, 65));

    
    int arr[3] = {1, 5, 8};
    int arr2[3] = {1, 5, 8};
    int arr3[3] = {1, 5, 7};
    int arr4[3] = {2, 5, 7};

    int arrLen1 = sizeof(arr) / sizeof(arr[0]);

    int *pArr = arr;

    printf("is arr1 equal to arr2 - %d\n", expectsAllToBeEqual(arr, arrLen1, arr3, arrLen1));
    printf("sizeof arr %d, sizeof *arr %d, sizeof[0] %d, *sizeof[0] %d\n", sizeof(arr), sizeof(&arr), sizeof(arr[0]), sizeof(&pArr));
    printf("sizeof arr %d", sizeof(arr)/sizeof(arr[0]));
    return 0;
}
