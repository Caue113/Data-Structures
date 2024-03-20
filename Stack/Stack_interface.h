struct Stack_int;

struct Stack_int *Stack_int_create();
void Stack_int_destroy(struct Stack_int *stack);

void Stack_int_push(struct Stack_int *stack, int value);
int Stack_int_pop(struct Stack_int *stack);
int Stack_int_peek(struct Stack_int *stack);

int Stack_int_isEmpty(struct Stack_int *stack);