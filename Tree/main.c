#include <stdlib.h>
#include <stdio.h>

#include "tree.h"


typedef struct tree_node node;


void print_node(node *node){
    if(!node){
        return;
    }

    printf("Node Addr: %p", node);
    if(node->key){
        printf(" | K: %d | Left: %p | Right: %p", node->key, node->left, node->right);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    
    node *root = tree_node_create();

    node *node1 = tree_node_create();
    node *node2 = tree_node_create();
    node *node3 = tree_node_create();
    node *node4 = tree_node_create();
    
    root->key = 1;
    node1->key = 2;
    node2->key = 3;
    node3->key = 4;
    node4->key = 5;

    tree_insert(root, node1);
    tree_insert(root, node2);
    
    tree_insert(node1, node3);
    tree_insert(node1, node4);

    print_node(root);
    print_node(node1);
    print_node(node2);
    print_node(node3);
    print_node(node4);

    printf("Transversing\n");
    tree_transverse_preorder(root);

    printf("Transversing\n");
    tree_transverse_postorder(root);

    printf("Transversing\n");
    tree_transverse_inorder(root);

    tree_node_destroy(root);
    tree_node_destroy(node1);
    tree_node_destroy(node2);
    tree_node_destroy(node3);
    tree_node_destroy(node4);
    return 0;
}
