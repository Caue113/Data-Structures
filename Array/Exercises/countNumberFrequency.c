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

int count_frequency(int *array, int length, int targetNumber){
    if(length < 1){
        printf("[count_frequency] Invalid Length");
        return -1;
    }

    int frequency = 0;
    for (size_t i = 0; i < length; i++)
    {
        if(array[i] == targetNumber){
            frequency++;
        }
    }

    return frequency;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 6, 2, 3, 5, 1, 5, 5, 2, 34, 7, 12, 4, 5, 6, 7, 8, 7, 34, 5, 13, 3, 2, 1, 24, 32, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    array_bubblesort_ascend(arr, length);
    int targetValue = 3;
    printf("count of %d in array is: %d\n", targetValue, count_frequency(arr, length, targetValue));

    //Every single data until array length
    for (size_t i = 0; i < length; i++)
    {
        printf("count of %d in array is: %d\n", i, count_frequency(arr, length, i));
    }
    
    return 0;
}
