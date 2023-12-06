#include <stdio.h>
#include <stdlib.h>


typedef struct Stack{
    int *values;
    int length;
    int lastIdx;
} Stack;

Stack *newStack(int length){
    Stack *pStack = malloc(sizeof(Stack));
    pStack->values = malloc(sizeof(int) * length);
    pStack->length = length;
    pStack->lastIdx = 0;
    return pStack;
}

int isEmpty(Stack *stack){
    return (stack->length == 0) ? 1 : 0;
}

int isFull(Stack *stack){
    if(stack->lastIdx + 1 > stack->length){
        return 1;
    }
    else{
        return 0;
    }
    
}

void push(Stack *stack, int value){
    if(isFull(stack)){
        printf("Error: Stack Overflow Exception\n");
        return;
    }   
    stack->values[stack->lastIdx] = value;
    stack->lastIdx++;
}

int peek(Stack *stack){
    return stack->values[stack->lastIdx];
}

void pop(Stack *stack){
    if(stack->lastIdx - 1 < 0 || isEmpty(stack)){
        printf("Error: Stack Underflow Exception\n");
        return;
    }
    
    stack->lastIdx--;
}


void printStack(Stack *stack){
    for (size_t i = 0; i < stack->lastIdx; i++)
    {
        printf("Stack[%d]: %d\n", i, stack->values[i]);
    }
}

void destructStack(Stack *stack){
    free(stack->values);
    free(stack);
}


int main(int argc, char const *argv[])
{
    Stack *pSt = newStack(4);

    //Empty test
    isEmpty(pSt);

    push(pSt, 1);
    printStack(pSt);

    isEmpty(pSt);

    //Pushing normal test

    push(pSt, 3);
    printStack(pSt);
    push(pSt, 1123);
    printStack(pSt);

    //Pop normal test
    pop(pSt);
    printStack(pSt);

    //Push overflow test
    push(pSt, 5555);
    printStack(pSt);
    push(pSt, 666666);
    printStack(pSt);
    push(pSt, 199191);  //Overflow
    printStack(pSt);

    //Pop underflow test
    pop(pSt);
    pop(pSt);
    pop(pSt);
    pop(pSt);
    pop(pSt);


    destructStack(pSt);
    return 0;
}
