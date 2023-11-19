#include <stdio.h>
#include <string.h>

unsigned int numberPoints = 10;
int* pPoints; 

int nums[4] = { 1, 2, 3, 4 };
int* pnums;

int* rng[4];


int main(){
    pPoints = &numberPoints;
    printf("Num: %d\nMemory size(of): %d\nNum addr: %p\nPointer: %p\n", numberPoints, sizeof(numberPoints), &numberPoints, pPoints);


    printf("\n\nMemory Addr Array:\nValue\tAddress");
    for (int i = 0; i < 4; i++) {
        printf("\n%d\t%p", nums[i], &(nums[i]));
    }

    printf("\n\nMemory references and deferences");    
    //Should return first element normally
    rng[0] = &nums[0];
    printf("\n\nMemory Addr Array:\nValue\tAddress");
    printf("\n%d\t%p", *(rng[0]), rng[0]);

    //Should return second element normally
    rng[1] = &nums[0]+4;
    printf("\n%d\t%p", *(rng[1]), rng[1]);

    //Here the fun begins. Will it be first element?
    rng[2] = &nums[0] + -2;
    printf("\n%d\t%p", *(rng[2]), rng[2]);

    return 0;
}
