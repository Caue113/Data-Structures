#include <stdio.h>
#include <stdlib.h>

#include "Stack_Dynamic_interface.h"
#include "../Array/Vector.h"

struct Stack_Dynamic_int {
    //Interface
    int *values;
    int lastElement;
    int length;

    //Underlying logic
    struct Vector_int *vector;
};

void Stack_Dynamic_int_push(struct Stack_Dynamic_int *stack, int value){
    stack->vector->insert(stack->vector, value);
    stack->lastElement = stack->vector->values[stack->vector->length - 1];
    stack->length = stack->vector->length;

    stack->values = stack->vector->values;  //Alwawys update pointer reference (there is a better wya, though its needed to update Vector logics)
}

int Stack_Dynamic_int_pop(struct Stack_Dynamic_int *stack){
    if(stack->lastElement < 1){
        return NULL;
    }

    int element = stack->lastElement;

    stack->vector->delete(stack->vector);
    stack->lastElement = stack->vector->values[stack->vector->length - 1];
    stack->length = stack->vector->length;
    
    stack->values = stack->vector->values;  //Alwawys update pointer reference (there is a better wya, though its needed to update Vector logics)

    return element;
}
int Stack_Dynamic_int_peek(struct Stack_Dynamic_int *stack){
    return stack->lastElement;
}

int Stack_Dynamic_int_isEmpty(struct Stack_Dynamic_int *stack){
    return stack->vector->isEmpty(stack->vector);
}

void Stack_Dynamic_int_display(struct Stack_Dynamic_int *stack){
    if(!stack){
        printf("Exception - No Stack Exists\n");
        return NULL;
    }
    printf("Display Stack: %p\n", stack);
    printf("Is Empty? : %d\n", Stack_Dynamic_int_isEmpty(stack));
    printf("Values\n");
    for (size_t i = 0; i < stack->length; i++)
    {
        printf("%d\t|\t%d\n", i, stack->values[i]);
    }
}

struct Stack_Dynamic_int *Stack_Dynamic_int_create(){
    struct Stack_Dynamic_int *stack = malloc(sizeof(struct Stack_Dynamic_int));
    struct Vector_int *vec = Vector_int_create(4);

    *stack = (struct Stack_Dynamic_int){
        .vector = vec,
        .values = vec->values,
        .lastElement = NULL,
        .length = vec->length,
    };

    return stack;
}

void Stack_Dynamic_int_destroy(struct Stack_Dynamic_int *stack){    
    Vector_int_destroy(stack->vector);
    free(stack);
}
