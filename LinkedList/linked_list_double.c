#include <stdlib.h>
#include <stdio.h>

#include "linked_list_double.h"


typedef struct linkedlist_node_double node;
typedef struct linkedlist_double linked_list;

int main(int argc, char const *argv[])
{
    
    //Node creations
    node *n1 = ll_double_node_create(1, NULL, NULL);
    node *n2 = ll_double_node_create(2, NULL, NULL);
    node *n3 = ll_double_node_create(3, NULL, NULL);
    node *n4 = ll_double_node_create(7, NULL, NULL);
    node *n5 = ll_double_node_create(55, NULL, NULL);
    node *n6 = ll_double_node_create(1001, NULL, NULL);




    

    linked_list *ll = ll_double_create(NULL, NULL);

    linked_list *ll_one_node = ll_double_create(NULL, NULL);

    // Insertion
    ll_double_insert(ll, n1);
    ll_double_insert(ll, n2);
    ll_double_insert(ll, n3);
    ll_double_insert(ll, n4);

    ll_double_insert(ll_one_node, n5);

    // Transverses
    ll_double_transverse(ll);
    ll_double_transverse_reverse(ll);

    printf("\n");

    // Delete
    ll_double_remove(ll);

    ll_double_transverse(ll);
    printf("\n");
    ll_double_node_print(n4);   //Expect next and prev to be null


    //Clear memory
    ll_double_node_destroy(n4);
    ll_double_node_destroy(n6); //Unused

    ll_double_destroy(ll);
    ll_double_destroy(ll_one_node);    
    return 0;
}
