struct node{
    int data;
    struct node* next;
};

struct linkedList{
    struct node* head;
    struct node* tail;
};

struct linkedList *ll_create();
void ll_remove(struct linkedList *node);
void ll_insert(struct linkedList *node, struct node *newNode);
void ll_print(struct linkedList *node);
void ll_transverse(struct linkedList *node);