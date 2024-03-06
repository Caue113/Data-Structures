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

struct linkedlist_node_double *ll_double_node_create(int data, struct linkedlist_node_double *next, struct linkedlist_node_double *previous){
    struct linkedlist_node_double *node = malloc(sizeof(struct linkedlist_node_double));
    node->data = data ? data : 0;
    node->next = next ? next : NULL;
    node->previous = previous ? previous : NULL;

    return node;
}

void ll_double_node_destroy(struct linkedlist_node_double *node){
    node->next = NULL;
    node->previous = NULL;
    free(node);
}

void ll_double_node_print(struct linkedlist_node_double *node){
    printf("Node: %p\n", node);
    printf("\tPrev: %p | Next %p\n", node->previous, node->next);
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
void ll_double_destroy(struct linkedlist_double *ll){
    if(!ll->tail){
        return;
    }

    struct linkedlist_node_double *currNode = ll->tail;

    while (currNode->previous)
    {
        currNode = currNode->previous;
        ll_double_node_destroy(currNode->next);
    }
    ll_double_node_destroy(currNode);
    free(ll);
    ll->head = NULL;
    ll->tail = NULL;
}

void ll_double_insert(struct linkedlist_double *ll, struct linkedlist_node_double *newNode){
    if(!ll->head){
        ll->head = newNode;
        ll->tail = newNode;
        return;
    }

    ll->tail->next = newNode;
    newNode->previous = ll->tail;
    ll->tail = newNode;
}

void ll_double_remove(struct linkedlist_double *ll){
    if(!ll->head){
        return;
    }

    ll->tail = ll->tail->previous;
    ll->tail->next->previous = NULL;
    ll->tail->next = NULL;
}

void ll_double_transverse(struct linkedlist_double *ll){
    struct linkedlist_node_double *currNode = ll->head;

    while (currNode)
    {
        ll_double_node_print(currNode);
        currNode = currNode->next;
    }    
}

void ll_double_transverse_reverse(struct linkedlist_double *ll){
    struct linkedlist_node_double *currNode = ll->tail;
    while (currNode)
    {
        printf("Node: %p\n", currNode);
        currNode = currNode->previous;
    }
}