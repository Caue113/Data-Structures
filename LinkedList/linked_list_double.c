#include <stdlib.h>
#include <stdio.h>

#include "linked_list_double.h"


typedef struct linkedlist_node_double node;
typedef struct linkedlist_double linked_list;

int main(int argc, char const *argv[])
{
    

    node *n1 = ll_create_node_double(1, NULL, NULL);
    node *n2 = ll_create_node_double(2, NULL, NULL);
    node *n3 = ll_create_node_double(3, NULL, NULL);
    node *n4 = ll_create_node_double(7, NULL, NULL);
    node *n5 = ll_create_node_double(55, NULL, NULL);
    node *n6 = ll_create_node_double(1001, NULL, NULL);

    linked_list *ll = ll_double_create(NULL, NULL);

    ll_double_insert(ll, n1);
    ll_double_insert(ll, n2);
    ll_double_insert(ll, n3);
    ll_double_insert(ll, n4);

    ll_double_transverse(ll);
    ll_double_transverse_reverse(ll->head);

    ll_double_destroy(ll->head);
    return 0;
}