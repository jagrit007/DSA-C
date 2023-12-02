// Given an integer k and a queue of integers, we need to reverse the order of the first 
// k elements of the queue, leaving the other elements in the same relative order. 
// Implement this program dynamically and only following standard operations are 
// allowed on queue.
// a. enqueue(x) : Add an item x to rear of queue
// b. dequeue() : Remove an item from front of queue
// c. size() : Returns number of elements in queue.
// d. front() : Finds front item
// Input : Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100], k = 5
// Output : Q = [50, 40, 30, 20, 10, 60, 70, 80, 90, 100]


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

//stack stuff
int top = -1;
int stack[MAXSIZE];

//queue stuff
int queueLength = MAXSIZE;

struct Queue{
    int data[10];
    int rear;
    int front;
};

struct Queue * q1, * q2;

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == MAXSIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isFull()){
        printf("\nThe stack is full!\n");
        return;
    }
    top +=1;
    stack[top] = data;
}

int pop(){
    if(isEmpty()){
        printf("\nStack is empty!\n");
        return -1;
    }
    int temp = stack[top];
    top -= 1;
    return temp;
}

void printStack(){
    printf("\n");
    for(int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
}

int dequeue(struct Queue * q){
    if(isQueueEmpty(q)){
        printf("The queue is empty!");
        return -1;
    }
    int temp = q->data[q->front];
    q->front +=1;
    return temp;
}

void enqueue(struct Queue * q, int data){
    if(isQueueFull(q)){
        printf("The queue is full!");
        return;
    }
    if(isQueueEmpty(q)){
        q->front = 0;
    }
    q->rear += 1;
    q->data[q->rear] = data;
}

int isQueueEmpty(struct Queue * q){
    if(q->front==-2 || q->front>=q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isQueueFull(struct Queue * q){
    if(q->rear == queueLength-1){
        return 1;
    }
    else{
        return 0;
    }
}

void printQueue(struct Queue * q){
    if(isQueueEmpty(q)){
        printf("\nThe queue is empty!\n");
        return;
    }
    printf("\n");
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->data[i]);
    }
}


int main(){
    q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q2 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->rear = -1;
    q2->rear = -1;
    q1->front = -2;
    q2->front = -2;


    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);
    enqueue(q1, 60);
    enqueue(q1, 70);
    enqueue(q1, 80);
    enqueue(q1, 90);
    
    printQueue(q1);

    printf("\nEnter the number of digits to reverse from the start:");
    int numOfDigitsToReverse;
    scanf("%d", &numOfDigitsToReverse);

    for(int i=0; i<numOfDigitsToReverse; i++){
        if(!isQueueEmpty(q1))
        push(dequeue(q1));
        // printQueue(q1);
    }
    printStack();

    for(int i=0; i<numOfDigitsToReverse; i++){
        if(!isQueueFull(q2) && !isEmpty()){
            enqueue(q2, pop());
            printQueue(q2);
        }
    }

    while(!isQueueEmpty(q1)){
        if(!isQueueFull(q2))
        enqueue(q2, dequeue(q1));
    }


    printf("\nFinal state of the queue:\n");
    printQueue(q2);
    return 0;
}