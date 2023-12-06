#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int *values;
    int length;
    int lastIdx;
} Queue;


Queue *newQueue(int length){
    Queue *queue = malloc(sizeof(queue));
    queue->values = malloc(sizeof(int) * length);
    queue->length = length;
    queue->lastIdx = 0;
    return queue;
}


int isEmpty(Queue *queue){
    return queue->lastIdx == 0 ? 1 : 0;
}

int isFull(Queue *queue){
    if(queue->lastIdx + 1 > queue->length){
        return 1;
    }
    else{
        return 0;
    }
}

void insert(Queue *queue, int value){
    if(isFull(queue)){
        printf("Error - Queue Overflow Exception\n");
        return;
    }
    queue->values[queue->lastIdx] = value;
    queue->lastIdx++;
}

void delete(Queue *queue){
    if(isEmpty(queue)){
        printf("Error - Queue Underflow Exception\n");
        return;
    }    

    for (size_t i = 0; i < queue->length; i++)
    {
        queue->values[i] = queue->values[i+1];
    }
    queue->lastIdx--;
}
int peek(Queue *queue){
    if(isEmpty(queue)){
        printf("Exception - Empty Stack\n");
        return;
    }

    return queue->values[0];
}

void printQueue(Queue *queue){
    printf("=== Printing Queue Data ===\n");
    printf("Queue | length: %d\nQueue | lastIdx: %d\n", queue->length, queue->lastIdx);

    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return;
    }
    else{
        for (size_t i = 0; i < queue->lastIdx; i++)
        {
            printf("Queue[%d]: %d\n", i, queue->values[i]);
        }
    }
}

void destructQueue(Queue *queue){
    free(queue->values);
    free(queue);
}

int main(int argc, char const *argv[])
{
    Queue *queue = newQueue(3);
    
    //Test insert
    insert(queue, 2);
    printQueue(queue);

    //Test pop
    delete(queue);
    printQueue(queue);

    //Test overflow
    insert(queue, 2);
    insert(queue, 123);
    insert(queue, 55566);
    printQueue(queue);
    insert(queue, 9494949); //Overflow
    printQueue(queue);
    
    //Test underflow
    delete(queue);
    delete(queue);
    delete(queue);
    printQueue(queue);
    delete(queue);
    printQueue(queue);

    //Test peek
    insert(queue, 123);
    printf("Peeking: %d\n",peek(queue));
    insert(queue, 21343);
    printf("Peeking: %d\n",peek(queue));
    delete(queue);
    printf("Peeking: %d\n",peek(queue));
    delete(queue);
    printf("Peeking: %d\n",peek(queue));

    destructQueue(queue);
    return 0;
}
