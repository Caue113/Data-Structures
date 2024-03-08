struct Vector_int;

void Vector_int_resize(struct Vector_int *vector, int operation);
void Vector_int_insert(struct Vector_int *vector, int value);
void Vector_int_delete(struct Vector_int *vector);
int Vector_int_find(struct Vector_int *vector, int value);

struct Vector_int *Vector_int_create(int capacity);
void Vector_int_destroy(struct Vector_int *vector);

//Utility function. Not required, but useful.
int Vector_int_isEmpty(struct Vector_int *vector);