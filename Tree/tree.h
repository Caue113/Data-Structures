#include <stdlib.h>
#include <stdio.h>

#include "tree_node_interface.h"

struct tree_node *tree_node_create(){
    struct tree_node *node = malloc(sizeof(struct tree_node));

    *node = (struct tree_node){
        .key = 0,
        .left = NULL,
        .right = NULL
    };

    return node;
}

void tree_node_destroy(struct tree_node *node){
    free(node);
}

void tree_insert(struct tree_node *tree, struct tree_node *node){
    struct tree_node *parentNode = tree;
    struct tree_node *targetNode = parentNode->left;  //First check left if can insert

    while (targetNode)
    {
        if(parentNode->left){
            targetNode = parentNode->right;
        }

        if(parentNode->right){
            parentNode = parentNode->left;
            targetNode = parentNode->left;
        }
    }

    //Sucessfully found NULL node position, we add
    if(!parentNode->left){
        parentNode->left = node;
    }
    else if(!parentNode->right){
        parentNode->right = node;
    }
}

void tree_delete(struct tree_node *tree, int key){

}


struct tree_node *tree_search(struct tree_node *tree, int key){

}

//Depth First Search
void tree_transverse_preorder(struct tree_node *tree){  
    struct tree_node *node = tree;
    if(node){
        printf("Curr node: %p Key: %d\n", node, node->key);
        tree_transverse_preorder(node->left);
        tree_transverse_preorder(node->right);
    }  
}

//Depth First Search
void tree_transverse_inorder(struct tree_node *node){
    struct tree_node *curr_node = node;
    if(curr_node){
        tree_transverse_inorder(curr_node->left);
        printf("Curr node: %p Key: %d\n", curr_node, curr_node->key);
        tree_transverse_inorder(curr_node->right);
    }
}

//Depth First Search
void tree_transverse_postorder(struct tree_node *tree){
    struct tree_node *node = tree;
    if(node){
        tree_transverse_postorder(node->left);
        tree_transverse_postorder(node->right);
        printf("Curr node: %p Key: %d\n", node, node->key);
    }
}
