#include <stdlib.h>
#include <stdio.h>

/**
 * Create a new reversed array. Since mutating data isn't always the best option.
*/
int *reverseArray(int arr[], int length){
    if(length == 0){
        printf("Error: EmptyArray. Returning the same array back.\n");
        return arr;
    }
    int *newArr = malloc(sizeof(int) * length);

    for (size_t i = 0; i < length; i++)
    {
        newArr[i] = arr[(length-1)-i];
    };

    return newArr;    
}

void printArray(int arr[], int length){
    printf("Array[");
    for (size_t i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 7, 123, 66666, 867};   //Expects [867, 66666, 123, 7, 1]
    int *rev1 = reverseArray(arr1, 5);

    int arr2[] = {867};                     //Expects [867]
    int (*rev2) = reverseArray(arr2, 1);

    int arr3[] = {};                        //Expects the same array
    int *rev3 = reverseArray(arr3, 0);

    int arr4[] = {1, 7};                    //Expects [7, 1]
    int *rev4 = reverseArray(arr4, 2);
    
    printf("Reversing Array 1\n");
    printArray(arr1, 5);
    printArray(rev1, 5);
    printf("Reversing Array 2\n");
    printArray(arr2, 1);
    printArray(rev2, 1);
    printf("Reversing Array 3\n");
    printArray(arr3, 0);
    printArray(rev3, 0);
    printf("Reversing Array 4\n");
    printArray(arr4, 2);
    printArray(rev4, 2);


    free(rev1);
    free(rev2);
    free(rev3);
    free(rev4);
    return 0;
}
