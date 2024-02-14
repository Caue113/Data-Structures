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
    char* hashTable[100];

    const int dataSize = 4;
    char *inputs[] = {"abc", "zzz", "dff", "bca"};
    
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
