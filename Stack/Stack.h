#include <stdio.h>
#include <stdlib.h>

#include "Stack_interface.h"

struct Stack_int{
    int *values;
    int capacity;
    int length;
    int lastElement;
};

struct Stack_int *Stack_int_create(int capacity){
    struct Stack_int *stack = malloc(sizeof(struct Stack_int));
    *stack = (struct Stack_int){
        .values = malloc(sizeof(int) * capacity),
        .capacity = capacity,
    };
}

void Stack_int_destroy(struct Stack_int *stack){
    free(stack->values);
    free(stack);
}

int Stack_int_isEmpty(struct Stack_int *stack){
    return stack->length == 0;
}

int Stack_int_peek(struct Stack_int *stack){
    return stack->lastElement;
}
int Stack_int_pop(struct Stack_int *stack){
    if(stack->length < 1){
        return;
    }

    int element = stack->lastElement;
    stack->length--;
    stack->lastElement = stack->values[stack->length - 1];
    return element;
}
void Stack_int_push(struct Stack_int *stack, int value){
    if(stack->length + 1 > stack->capacity){
        return;
    }

    stack->values[stack->length - 1] = value;
    stack->lastElement = value;
    stack->length++;
}
