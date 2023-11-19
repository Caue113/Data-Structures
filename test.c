#include <stdio.h>
#include <stdbool.h>

void test(){
    printf("im a test");
}

int sum(int a, int b){
    return a + b;
}

int main()
{
    void (*pFunc) ();
    void (*pFunc2) (void);

    int (*pSum) ();
    int (*pSum2) (int, int);
    void (*pSum3) ();   //will be casted. Future note

    printf("Hello\n");

    printf("test pointer %p\n", test);
    pFunc = test;
    pFunc2 = test;

    printf("should run??");
    pFunc();
    pFunc2();

    /*Different arguments*/
    pSum = sum;
    pSum2 = sum;
    pSum3 = sum;
    int a = 1, b = 2;

    printf("Should math?");
    printf("Sum Original: %d", sum(a, b));
    printf("Sum1: %d", pSum(a, b));
    printf("Sum2: %d", pSum2(a, b));
    //printf("Sum3: %d", pSum3(a, b));

    return 0;
}