#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

void print_ll_reverse(node *node){
    if(node->next){
        print_ll_reverse(node->next);
    }
    printf("Value: %d\n", node->data);
}

int main(int argc, char const *argv[])
{
    node n5 = {0, NULL};
    node n4 = {2135, &n5};
    node n3 = {33, &n4};
    node n2 = {554, &n3};
    node n1 = {1, &n2};
    
    //Expects: 0, 2135, 33, 554, 1
    print_ll_reverse(&n1);

    return 0;
}
