#include <stdio.h>
#include <stdlib.h>

/**
 * The stated problem induces a solution where the sum must be within a contiguous
 * arrangement.
 * E.g: { 1, 3, 5, 7 } = 8;
 * Solution: {3, 5}
 * Other possible solution: {1, 7 }
*/

//This is needed to return a proper subarray
typedef struct array_int
{
    int length;
    int *values;
} array_int;

array_int *create_array_int(int length){
    array_int *arr = malloc(sizeof(array_int));
    arr->length = length;
    arr->values = malloc(sizeof(int) * length);
    return arr;
}

void destroy_array_int(array_int *array){
    free(array->values);
    free(array);
}


int *copyArray(int *originalArray, int start, int end){
    if(!originalArray){
        printf("[copyArray] Error - Provide pointers to arrays");
        return NULL;
    }

    if(end < start){
        int temp = start;
        start = end;
        end = temp;
    }

    int length = end - start + 1;   //Zero based indexes require +1;
    int *newArray = malloc(sizeof(int) * length);

    for (size_t i = 0; i < length; i++)
    {
        newArray[i] = originalArray[start + i];
    }

    return newArray;
}


//We naively checks EVERY SINGLE iteration until first is found
array_int *subarrayFromSum(int *array, int length, int sum){
    if(length < 1){
        return NULL;
    }

    int initialIndex = 0;
    int _sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        
        for (size_t j = initialIndex; j < length; j++)
        {
            _sum += array[j];
            if(_sum == sum){
                printf("Found sub-array\n");

                int *ptrArr = copyArray(array, initialIndex, j);
                int length = j - initialIndex + 1; //Zero based indexes need + 1

                array_int *arr = create_array_int(length);
                arr->values = ptrArr;
                return arr;
            }
        }
        _sum = 0;
        initialIndex++;
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 2, 76, 334, 2, 44, 1, 1, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    array_int *newArr = subarrayFromSum(arr, length, 561);

    if(!newArr){
        printf("No subarrays have been found\n");
    }
    else{
        printf("lengt: %d\n", newArr->length);
        for (size_t i = 0; i < newArr->length; i++)
        {
            printf("%p: %d\n", &newArr->values[i], newArr->values[i]);            
        }
    }
    

    free(newArr);
    return 0;
}
