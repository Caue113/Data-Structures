#include <stdio.h>
#include <stdlib.h>

struct linkedlist_node_double{
    int data;
    struct linkedlist_node_double *next;
    struct linkedlist_node_double *previous;
};

struct linkedlist_double{
    struct linkedlist_node_double *head;
    struct linkedlist_node_double *tail;
};

struct linkedlist_node_double *ll_create_node_double(int data, struct linkedlist_node_double *next, struct linkedlist_node_double *previous){
    struct linkedlist_node_double *node = malloc(sizeof(struct linkedlist_node_double));
    node->data = data ? data : 0;
    node->next = next ? next : NULL;
    node->previous = previous ? previous : NULL;

    return node;
}

struct linkedlist_double *ll_double_create(struct linkedlist_node_double *head, struct linkedlist_node_double *tail){
    struct linkedlist_double *ll = malloc(sizeof(struct linkedlist_double));
    
    *ll = (struct linkedlist_double){
        .head = head ? head : NULL,
        .tail = tail ? tail : NULL
    };

    return ll;
}

/**
 * Free every node that comes next to the given node.
 * 
 * For clearing the entire linked list, provide head as starting point
*/
void ll_double_destroy(struct linkedlist_node_double *node){
    if(node){
        ll_double_destroy(node->next);
        free(node);
    }
}

void ll_double_insert(struct linkedlist_double *ll, struct linkedlist_node_double *newNode){
    if(!ll->head){
        ll->head = newNode;
        return;
    }

    struct linkedlist_node_double *currNode = ll->head;

    while (currNode->next)
    {
        currNode = currNode->next;
    }
    
    currNode->next = newNode;
}
void ll_double_remove(struct linkedlist_double *node){

}

void ll_double_transverse(struct linkedlist_double *ll){
    struct linkedlist_node_double *currNode = ll->head;

    while (currNode)
    {
        printf("Node: %p\n", currNode);
        currNode = currNode->next;
    }    
}

void ll_double_transverse_reverse(struct linkedlist_node_double *node){
    if(node){
        ll_double_transverse_reverse(node->next);
        printf("Node: %p\n", node);
    }
}