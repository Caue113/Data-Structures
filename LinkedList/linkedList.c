#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
This linked list cab be built in two ways, simpler with only 1 typedef, and more complex, with linkedList being composite of nodes.

1. Simple build means the proper linkedList is the node itself. Outer functions operate on him.
2. Complex separate concerns. Nodes are agnostic of what kindo of collection; linkedList, "tries" to provide different methods and initializations on nodes.

Sadly for now, you always must reference outer functions which linkedList (and sometimes which node) to operate on.

*/


typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct linkedList{
    node* head;
    node* tail;
} linkedList;



void print_ll(linkedList* addr){
    if(!addr->head){
        printf("Linked List is Empty (NULL head)\n");
    }
    else{
        printf("Head: %p\n", addr->head);
    }
}

void print_node(node* addr){
    printf("Data: %d | Next: ", addr->data);
    if(addr->next == NULL){
        printf("NULL\n");
    }
    else{
        printf("%p\n", addr->next);
    }
}

/**
 * Given a node. Transverse foward until no other node is linked.
*/
void transverse_nodes(node* addr){
    print_node(addr);

    if(addr->next != NULL){
        transverse_nodes(addr->next);
    }
    else{
        printf("\tNo next node found.\n");
    }
}

/**
 * Given a LinkedList, tranverses it entirely from the head until the end.
 * Works similarly to "transverse_nodes"
*/
void transverse_ll(linkedList* addr){
    printf("[transverse_ll] Invoked!!\n");

    if(addr->head == NULL){
        printf("This linkedList is Empty\n");
    }
    else{
        transverse_nodes(addr->head);
    }
}

void ll_push(linkedList *linkedList, node *newNode){
    if(!linkedList->head){
        printf("[ll_push] LinkedList is empty. Pushing to head.\n");
        linkedList->head = newNode;
    }
    else{
        printf("[ll_push] running push\n");
        node *current = linkedList->head;
        while(current->next){
            printf("[ll_push] step through\n");
            current = current->next;
        }
        //printf("[ll_push] the node is %p with %d\n", current, current->data);
        current->next = newNode;
    }
}



int main(int argc, char const *argv[])
{
    //We are manually assigning in the linkings.
    linkedList ll;
    node d1 = {5, NULL};
    ll.head = &d1;

    printf("value: %d\n", d1.data);

    node d2 = {10, NULL};
    d1.next = &d2;
    //d1.head = &d2.data;   //Also works, but compiler worried me about incompatible data.

    printf("D1 - value: %d nextPointer: %p\n", d1.data, d1.next);
    printf("D2 - value: %d dataAddr: %p addr by prev pointer: %p\n", d2.data, &d2.data, d1.next);

    printf("\n\n");

    print_ll(&ll);
    print_node(&d1);
    print_node(&d2);
    print_node(d1.next);

    transverse_ll(&ll); //Should print all data up here again

    printf("\n|\t\t|");
    printf("\n|\t\t|");
    printf("\n|\t\t|");
    printf("\n");

    printf("Test function? Y/N - \t");
    char opt[1];
    scanf("%s",&opt);

    if(strcmp(opt, "Y") == 0){
        linkedList ll_1 = {NULL, NULL};
        linkedList ll_2 = {NULL, NULL};

        linkedList *ptr_ll_3 = malloc(sizeof(linkedList));
        print_ll(&ll_1);
        print_ll(&ll_2);
        print_ll(ptr_ll_3);
        

        node n1 = {1, NULL};
        node n2 = {13, NULL};
        node n3 = {534, NULL};
        node n4 = {6, NULL};
        node n5 = {111111, NULL};
        node n6 = {2222, NULL};

        ll_push(&ll_1, &n1);
        ll_push(&ll_1, &n4);

        transverse_ll(&ll_1);

        ll_2.head = &n3;
        ll_push(&ll_2, &n6);
        ll_push(&ll_2, &n2);

        transverse_ll(&ll_2);



        //ll_push(ptr_ll_3, &n1);



        

        /* ll_2.head = &n1;
        ll_push(&ll_2, n3);
        ll_push(&ll_2, n2); */

        /* print_node(&n3);
        print_node(&n1); */
        /* print_node(&n4); */
        /* transverse_ll(&ll_1); */
        //transverse_ll(&ll_2);
    }
    return 0;
}