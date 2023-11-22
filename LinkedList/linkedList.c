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
        printf("[print_ll]Linked List is Empty (NULL head)\n");
    }
    else{
        printf("Linked List Head: %p | Data: ", addr->head);
        if(addr->head->data){
            printf("%d\n",addr->head->data);
        }
        else{
            printf("IS NULL\n");
        }
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

/**
 * Removes a node given an indes from head.
 * @todo Test with 0, 1 and 2 nodes.
*/
void ll_remove_at(linkedList *linkedList, int index){
    node *current = linkedList->head;
    //Read next next node
    //If exists, proceed
    //If not, halt and warn exception

    if(index == 0){
        node *ptr = linkedList->head;
        //free(linkedList->head);   //Should free?
        linkedList->head = linkedList->head->next;

        printf("[ll_remove_at] Removing first node. Ptr: %p\n", ptr);
    }

    for (size_t i = 0; i < index-1; i++)
    {
        if(current->next->next != NULL){
            current = current->next;
        }

        /* if(current->next == NULL){
            printf("[ll_remove_at] ERROR - IndexOutOfBounds");
            break;
        }
        else{
            current = current->next;
        } */
    }
    if(current != NULL){
        printf("[ll_remove_at] SUCESS. Removing node\n");
        current->next = current->next->next;
        printf("[ll_remove_at] Curr ptr | remove ptr | next ptr\n\t%p\t|\t%p\t|\t%p\t\n", current->data, current->next->data, current->next->next->data);
    }


    
}

/**
 * Inserts a node in the end of the linked list
*/
void ll_insert(linkedList *linkedList, node *newNode){
    /* printf("ll head : %p data %d", linkedList->head, linkedList->head->data); */
    if(linkedList->head == NULL){
        printf("[ll_insert] LinkedList is empty. Pushing to head.\n");
        linkedList->head = newNode;
    }
    else{
        printf("[ll_insert] running push\n");
        node *current = linkedList->head;
        while(current->next){
            printf("[ll_insert] step through\n");
            current = current->next;
        }
        printf("[ll_insert] the node is %p with %d\n", current, current->data);
        current->next = newNode;
    }
}

/**
 * Inserts a node at the beggining of the linked list. Effectively, becoming the new head.
*/
void ll_insert_begin(linkedList *linkedList, node *newNode){
    if(linkedList->head == NULL){
        printf("[ll_insert_begin] LinkedList is empty. Pushing to head.\n");
        linkedList->head = newNode;
    }
    else{
        printf("[ll_insert_begin] Inserting node at beggining.\n");
        node *temp = linkedList->head;
        linkedList->head = newNode;
        newNode->next = temp;
    }
}

/**
 * Inserts a node before another. To prevent positioning issues, every value within the linked list MUST be UNIQUE.
 * @todo Test with checkValue being a node or void pointer
*/
void ll_insert_before(linkedList *linkedList, int checkValue, node *newNode){
     if(!linkedList->head){
        printf("[ll_insert_before] LinkedList is empty. Pushing to head.\n");
        linkedList->head = newNode;
    }
    else{
        printf("[ll_insert_before] Inserting node before\n");
        node *current = linkedList->head;

        while (current->next){
            if(current->next->data != checkValue){
                current = current->next;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
        }
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

    printf("Test function? Y/N - ");
    char opt[1];
    scanf("%s",&opt);

    if(strcmp(opt, "Y") == 0){

        /* ALWAYS INITALIZE WHATEVER STRUCT YOU HAVE TO SOME VALUE OR NULL */
        linkedList ll_1 = {NULL};
        linkedList ll_2 = {NULL};

        /* linkedList *ptr_ll_3 = malloc(sizeof(linkedList)); */
        print_ll(&ll_1);
        print_ll(&ll_2);
        /* print_ll(ptr_ll_3); */
        

        node n1 = {1, NULL};
        node n2 = {13, NULL};
        node n3 = {534, NULL};
        node n4 = {6, NULL};
        node n5 = {111111, NULL};
        node n6 = {2222, NULL};

        
        ll_insert(&ll_1, &n1);  //Should create node at head
        transverse_ll(&ll_1);
        ll_insert(&ll_1, &n3);  //Push normally
        transverse_ll(&ll_1);
        ll_insert_begin(&ll_1, &n2);  //Substituite n1 with n2 as head
        transverse_ll(&ll_1);
        ll_insert(&ll_1, &n6);  
        transverse_ll(&ll_1);
        ll_insert_before(&ll_1, 2222, &n5); //Should be placed before n6. E.g: etc, 111111, 2222
        transverse_ll(&ll_1);
        ll_remove_at(&ll_1, 2); //Should remove n3
        transverse_ll(&ll_1);

        /* print_node(&n1); */
        /* 
        linkedList ll_rem;
        print_ll(&ll_rem);
        node nn1 = {2, NULL};
        node nn2 = {4, NULL};
        node nn3 = {8, NULL};
        node nn4 = {10, NULL};
        node nn5 = {14, NULL};
        node nn6 = {20, NULL};
        node nn7 = {100, NULL};
        
        ll_insert(&ll_rem, &nn1);
        ll_insert(&ll_rem, &nn2);
        ll_insert(&ll_rem, &nn3);
        ll_insert(&ll_rem, &nn4);
        ll_insert(&ll_rem, &nn5);
        ll_insert(&ll_rem, &nn6);
        ll_insert(&ll_rem, &nn7);

        transverse_ll(&ll_rem);

        printf("ptr: %p data %d", ll_rem.head, ll_rem.head->data);
 */
/* 
        //Test 1 - Transverse empty linked list. Should return empty list.
        transverse_ll(&ll_1);
    
        //Test 2 - For an empty linked list, attach node into head
        ll_insert(&ll_1, &n1);
        ll_insert(&ll_1, &n4);

        transverse_ll(&ll_1);

        ll_2.head = &n3;
        ll_insert(&ll_2, &n6);
        ll_insert(&ll_2, &n2);

        transverse_ll(&ll_2);
 */
    }
    return 0;
}