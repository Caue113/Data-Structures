#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumAsciiValuesFromString(char *string, int length){
    if(length < 0){
        printf("LengthInvalidException\n");
        return -1;
    }
    
    int sum = 0;

    //Read letters
    for (size_t j = 0; j < length; j++)
    {
        sum += (int)string[j];
    }
    return sum;
}

/* 
typedef struct Array_string{
    int length;
    char string[];
} Array_string;

Array_string *newArrayString(char stringData[], int length){
    Array_string *arrStr = malloc(sizeof(Array_string));
    arrStr->length = length;
    strcpy(stringData, arrStr->string);
    return arrStr;
}

void destructArrayString(Array_string *ptrArrayString){
    free(ptrArrayString);
}
*/

/**
 * @return index of table
*/
int hashFunction(char *input, int length){
    int sum = sumAsciiValuesFromString(input, length);
    if(sum == -1){
        printf("[HashFunction] Unknow Error!");
    }
    return sum % 97;
}

int main(int argc, char const *argv[])
{
    int* hashTable[100];
    /* char tempData[] = "myDAta";
    Array_string *arrStr1 = newArrayString(tempData, 7); */
    /* Array_string *arrStr1 = newArrayString("MyData", 7); */

    /* printf("test length: %d\t data: %c\n", arrStr1->length, arrStr1->string); */

    /* destructArrayString(arrStr1); */

    const int dataSize = 4;
    char *inputs[dataSize];

    char input1[] = "abc";
    char input2[] = "zzz";
    char input3[] = "dff";
    char input4[] = "bca";

    inputs[0] = &input1;
    inputs[1] = &input2;
    inputs[2] = &input3;
    inputs[3] = &input4;


    //Using algorigthm 1 - Collisions happen on same characters in different positions
    for (size_t i = 0; i < dataSize; i++)
    {
        printf("Data[%d]: %d\n", i, sumAsciiValuesFromString(inputs[i], 3));
        int idx = hashFunction(inputs[i], 3);
        printf("\tidx: %d\n", idx);

        hashTable[idx] = inputs[i];
        printf("Original data: %p\nSaved data: %p\n", inputs[i], hashTable[idx]);
    }
    return 0;
}
