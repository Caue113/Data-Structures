#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char data;
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

char *ll_to_array_char(node *head){

    int length = ll_length(head);
    if(length == -1){
        printf("ll_to_array_char - LengthOutOfBoundsException");
        return NULL;
    }
    
    char *wordPtr = malloc(sizeof(char) * length);

    int idx = 0;
    node *curr = head;

    while (curr)
    {
        wordPtr[idx] = curr->data;

        idx++;
        curr = curr->next;
    }

    return wordPtr;
}

void ll_display(node *head){
    if(!head){
        printf("[ll_display] - linked list is empty\n");
        return;
    }

    node *curr = head;
    while (curr)
    {
        printf("[ll_display] - Node value: %c\n", curr->data);
        curr = curr->next;
    }
    
}
int main(int argc, char const *argv[])
{
    node n1 = {'H', NULL};
    node n2 = {'e', NULL};
    node n3 = {'l', NULL};
    node n4 = {'l', NULL};
    node n5 = {'o', NULL};
    node n6 = {'!', NULL};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    
    //Expects: 'H','e','l','l','o','!'
    printf("Show linked list\n");
    ll_display(&n1);

    //Expects 6
    printf("Size of linked list: %d\n", ll_length(&n1));

    printf("Linked List to Array\n");

    char *word = ll_to_array_char(&n1);

    printf("All values in Array:\n");

    //Expects: 'H','e','l','l','o','!'
    for (size_t i = 0; i < 6; i++)
    {
        printf("%c, ", word[i]);
    }

    free(word);
    return 0;
}
