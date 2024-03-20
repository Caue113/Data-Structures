#include <stdio.h>
#include <stdlib.h>

#include "Stack_dynamic.h"

typedef struct Stack_Dynamic_int Stack;

int main(int argc, char const *argv[])
{
    Stack *stack = Stack_Dynamic_int_create();

    /* printf("Is Empty? %d", Stack_Dynamic_int_isEmpty(stack)); */
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_Dynamic_int_display(stack);

    for (size_t i = 1; i < 8; i++)
    {
        Stack_Dynamic_int_push(stack, i);
    }

    Stack_Dynamic_int_push(stack, 10);  //Expects array to resize
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_Dynamic_int_display(stack);
    
    Stack_Dynamic_int_pop(stack);
    Stack_Dynamic_int_pop(stack);
    printf("Capacity: %d\n", stack->vector->capacity);  //Expects array to resize
    Stack_Dynamic_int_pop(stack);
    Stack_Dynamic_int_pop(stack);
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_Dynamic_int_display(stack);

    //Cleanup
    Stack_Dynamic_int_destroy(stack);
    return 0;
}