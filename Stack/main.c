#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"


typedef struct Stack_int Stack;

int STACK_CAPACITY = 4;

int main(int argc, char const *argv[])
{
    
    Stack *s = Stack_int_create(STACK_CAPACITY);
    
    for (size_t i = 0; i < STACK_CAPACITY; i++)
    {
        Stack_int_push(s, i);
        printf("Stack inserted: %d\n", Stack_int_peek(s));
    }

    printf("\n");

    printf("Expects Stack Overflow\n");
    Stack_int_push(s, 999);
    printf("Stack last element: %d\n", s->lastElement);

    printf("\n");

    for (size_t i = 0; i < STACK_CAPACITY; i++)
    {
        printf("Stack removed: %d\n", Stack_int_pop(s));
    }

    printf("Expects Stack Underflow\n");
    printf("Stack removed?\n");
    if(Stack_int_pop(s) == NULL){
        printf("\tSTACK_UNDERFLOW_EXCEPTION\n");
    }
    else{
        printf("No\n");
    }

    Stack_int_destroy(s);
    return 0;
}
