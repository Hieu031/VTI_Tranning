#include<stdio.h>
#include<stdlib.h>

/*
circular queue is a update of standar queue.
it help reuse position deleted before that. 
*/

//Declare 1 structure Queue
typedef struct
{
    int front; //first element
    int rear; //end element
    int size; //nums eles
    unsigned capacity; //max size of Queue
    int *array; //array 1D sympolizes Queue
}Queue;

//Create queue
Queue* createQueue(unsigned capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

//check queue full
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

//check queue empty
int isEmpty(Queue* queue)
{   
    return (queue->size == 0);
}

//Add 1 item at end of queue
void enqueue(Queue* queue, int item)
{
    if(isFull(queue))//if queue full, can't add
        return;
    //add item at position empty which deleted before.
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

//Remove item from the first of queue
void dequeue(Queue* queue)
{
    if(isEmpty(queue))//if queue empty, can't remove
        return;
    int item = queue->array[queue->front];
    queue->front = (queue->front +1) % queue->capacity;
    queue->size = queue->size - 1;
}

//get the first value item of queue
int front(Queue* queue)
{
    return queue->array[queue->front];
} 

//get the end value item of queue
int rear(Queue* queue)
{
    return queue->array[queue->rear];
}

int main(){
    //creat queue with max 100 elements
    Queue* queue = createQueue(100);

    //add at position first queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    //print value first and end elements of queue before delete
    printf("Front item is %d\n", front(queue));
    printf("Rear Item is %d\n", rear(queue));

    //delete at the first position of queue after delete
    dequeue(queue);

    //print value first and end elements of queue
    printf("Front item is %d\n", front(queue));
    printf("Rear Item is %d\n", rear(queue));

    return 0;
}