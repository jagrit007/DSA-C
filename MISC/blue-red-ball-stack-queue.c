// There are N numbers of the balls in the box. The colours of the balls are red and 
// blue. You are requested to stack the balls in the bottom sealed basket one by one. 
// The order of placing the balls is two consecutive red balls followed by the two 
// consecutive blue balls. Later, create two empty queues Q1 and Q2. Remove the 
// last inserted ball from the basket and place it in Q1. Similarly remove the next ball 
// from the basket and insert in Q2. Develop a program to repeat this process until 
// the basket is empty and also print the colour of the balls in the both queues.

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

//stack stuff
int top = -1;
char stack[MAXSIZE];

//queue stuff
int queueLength = ((MAXSIZE/2) + (MAXSIZE%2));

struct Queue{
    char data[10];
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

void push(char data){
    if(isFull()){
        printf("\nThe stack is full!\n");
        return;
    }
    top +=1;
    stack[top] = data;
}

void pop(){
    if(isEmpty()){
        printf("\nStack is empty!\n");
        return;
    }
    top -= 1;
}

void printStack(){
    printf("\n");
    for(int i=0; i<=top; i++){
        printf("%c ", stack[i]);
    }
}

void stackInBasket(){
    printf("\nStacking %d balls in basket", MAXSIZE);
    for(int i=0; i<(MAXSIZE/2); i++){
        if(i%2 == 0){
            push('B');
            push('B');
        }
        else{
            push('R');
            push('R');
        }
    }
}

// void dequeue(struct Queue q){

// }

void enqueue(struct Queue * q, char data){
    if(isQueueFull(q)){
        printf("The queue is full!");
        return;
    }
    if(isQueueEmpty(q)){
        q->front +=1;
    }
    q->rear += 1;
    q->data[q->rear] = data;
}

int isQueueEmpty(struct Queue * q){
    if(q->front==-1){
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
        printf("%c ", q->data[i]);
    }
}

void ballsToQueue(){
    int i = 0;
    while(!isEmpty()){
        if(i%2 == 0){
            enqueue(q1, stack[top--]);
        }
        else{
            enqueue(q2, stack[top--]);
        }
        i++;
    }
    // for(int i=0; i<=top; i++){
    //     char data = stack[top--];
    //     if(i%2 == 0){
    //         enqueue(q1, data);
    //     }
    //     else{
    //         enqueue(q2, data);
    //     }
    // }
}


int main(){
    q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q2 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->rear = -1;
    q2->rear = -1;
    q1->front = -1;
    q2->front = -1;
    stackInBasket();
    printStack();

    ballsToQueue();
    printQueue(q1);
    printQueue(q2);
}