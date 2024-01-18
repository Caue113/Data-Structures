#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

int ll_length(node *head){
    int length = 1;
    if(!head){
        printf("Linked List is empty");
        return -1;
    }
    
    while(head->next)
    {
        length++;
        head = head->next;
    }
    return length;
}

int main(int argc, char const *argv[])
{
    node n5 = {0, NULL};
    node n4 = {2135, &n5};
    node n3 = {33, &n4};
    node n2 = {554, &n3};
    node n1 = {1, &n2};
    
    //Expects: 5
    printf("length: %d", ll_length(&n1));

    return 0;
}
