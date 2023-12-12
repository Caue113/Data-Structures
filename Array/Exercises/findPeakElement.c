#include <stdio.h>
#include <stdlib.h>



/**
 * This is a naive implementation, looping the entire array to find the first occurence.
 * Many edge cases need to be handled separatly
*/
int findFirstPeakElement(int arr[], int length){
    if(length < 0){
        printf("Error: NegativeLengthException\n");
        return -1;
    }
    if(length == 0){
        printf("Error: EmptyArrayException\n");
        return -1;
    }

    if(length == 1){
        return arr[0];
    }

    if(length == 2){
        return (arr[0] > arr[1]) ? arr[0] : arr[1];
    }

    for (size_t i = 1; i < length; i++)
    {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return arr[i];
        }
    }    
}


int main(int argc, char const *argv[])
{
    int baseTest1[] = {5, 10, 20, 15};               //From GFG - Output: 20
    int baseTest2[] = {10, 20, 15, 2, 23, 90, 67};   //From GFG - Output: 20 or 90

    int test1[] = {};           //Should throw exception
    int test2[] = {0};          //Expects 0
    int test3[] = {1000, 5};    //Expects 1000
    int test4[] = {5, 1000};    //Expects 1000
    int test5[] = {5, 4, 6};    //Expects 6
    int test6[] = {7, 7, 7, 7, 7, 7, 7};    //Expects 7


    printf("Base Test switch\n");
    printf("Value: %d\n", findFirstPeakElement(baseTest1, 4));
    printf("Value: %d\n", findFirstPeakElement(baseTest2, 7));
    
    printf("\n\n");
    printf("Self Test switch\n");
    printf("Value: %d\n", findFirstPeakElement(test1, 0));
    printf("Value: %d\n", findFirstPeakElement(test2, 1));
    printf("Value: %d\n", findFirstPeakElement(test3, 2));
    printf("Value: %d\n", findFirstPeakElement(test4, 2));
    printf("Value: %d\n", findFirstPeakElement(test5, 3));
    printf("Value: %d\n", findFirstPeakElement(test6, 7));

    return 0;
}
