#include <stdio.h>
#include <stdlib.h>

#include "Stack_dynamic.h"

typedef struct Stack_int Stack_int;

int main(int argc, char const *argv[])
{
    Stack_int *stack = Stack_int_create();

    /* printf("Is Empty? %d", Stack_int_isEmpty(stack)); */
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_int_display(stack);

    for (size_t i = 1; i < 8; i++)
    {
        Stack_int_push(stack, i);
    }

    Stack_int_push(stack, 10);  //Expects array to resize
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_int_display(stack);
    
    Stack_int_pop(stack);
    Stack_int_pop(stack);
    printf("Capacity: %d\n", stack->vector->capacity);  //Expects array to resize
    Stack_int_pop(stack);
    Stack_int_pop(stack);
    printf("Capacity: %d\n", stack->vector->capacity);
    Stack_int_display(stack);

    //Cleanup
    Stack_int_destroy(stack);
    return 0;
}
