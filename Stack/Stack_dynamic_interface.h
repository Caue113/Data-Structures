struct Stack_Dynamic_int;

struct Stack_Dynamic_int *Stack_Dynamic_int_create();
void Stack_Dynamic_int_destroy(struct Stack_Dynamic_int *stack);

void Stack_Dynamic_int_push(struct Stack_Dynamic_int *stack, int value);
int Stack_Dynamic_int_pop(struct Stack_Dynamic_int *stack);
int Stack_Dynamic_int_peek(struct Stack_Dynamic_int *stack);

int Stack_Dynamic_int_isEmpty(struct Stack_Dynamic_int *stack);