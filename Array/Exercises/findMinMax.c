#include <stdlib.h>
#include <stdio.h>


int findMax(int arr[], int length){
    if(length == 0){
        printf("Error: EmptyArrayException");
        return -1;
    }

    if(length == 1){
        return arr[0];
    }

    int max = arr[0];

    for (size_t i = 0; i < length; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}
int findMin(int arr[], int length){
    if(length == 0){
        printf("Error: EmptyArrayException");
        return -1;
    }

    if(length == 1){
        return arr[0];
    }

    int min = arr[0];
    
    for (size_t i = 0; i < length; i++)
    {
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1, 7, 123, 66666, 867};   //Expects 66666 or 1
    int arr2[] = {867};                     //Expects 867 or 867
    int arr3[] = {};                        //Expects to throw Error
    int arr4[] = {1, 7};                    //Expects 7 or 1
    int arr5[] = {7, 4, 1};                 //Expects 7 or 1

    


    
    printf("Max Value from arr1: %d\n", findMax(arr1, 5));    
    printf("Min Value from arr1: %d\n", findMin(arr1, 5));    

    printf("Max Value from arr2: %d\n", findMax(arr2, 1));    
    printf("Min Value from arr2: %d\n", findMin(arr2, 1));    

    printf("Max Value from arr3: %d\n", findMax(arr3, 0));    
    printf("Min Value from arr3: %d\n", findMin(arr3, 0));    

    printf("Max Value from arr4: %d\n", findMax(arr4, 2));    
    printf("Min Value from arr4: %d\n", findMin(arr4, 2));    

    printf("Max Value from arr5: %d\n", findMax(arr5, 3));    
    printf("Min Value from arr5: %d\n", findMin(arr5, 3));    
    
    return 0;
}
