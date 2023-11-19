#include <stdio.h>
#include <stdbool.h>


/**
 * Aproach 1
 * Implement: 
 * - constructor()  --> Init array normally, allocate last byte to possible next element;
 * - addEntry()     --> find the last entry, check if next addresses are clear
 * - removeEntry()  --> find last entry, clear all data
 * 
 * 
 * The best way to make a dynamic array, is to keep it as maximum as a common array for pointer logic
 * 
*/

int myNum1 = 1;
char myName1[8] = {'C','H','A','R','L'};
int randomNumber1 = 784;
int randomNumber2 = 231;
char myName2[5] = {'L','I','N','G','G'};

int* pNum;
void* pCursor;  //Suppsed only to read

//Remember, booleans are INTEGERS
bool a = false;


int main(int argc, char const *argv[])
{
    printf("===   Dynamic Array Study   ===\n");
    printf("Data Table\n");
    printf("\tint: %d\n", sizeof(int));
    printf("\tchar: %d\n", sizeof(char));
    printf("\tfloat: %d\n", sizeof(float));
    printf("\n\n");

    printf("Read address: %p, MyNum: %d\n", &myNum1, myNum1);

    for (int i = 0; i < 8; i++)
    {
        printf("Address of %p has value of %c\n", &myName1[i], myName1[i]);
    }

    printf("Read address: %p, MyNum: %d\n", &randomNumber1, randomNumber1);
    printf("Read address: %p, MyNum: %d\n", &randomNumber2, randomNumber2);

    for (int i = 0; i < 5; i++)
    {
        printf("Address of %p has value of %c\n", &myName2[i], myName2[i]);
    }

    printf("\n\n");
    printf("Full reading memory");
    void* address = &myNum1;
    for (int i = 0; i < 15; i++)
    {
        printf("Address: %p has value of: %c", &myNum1 + i);
    }
    
    
    return 0;
}