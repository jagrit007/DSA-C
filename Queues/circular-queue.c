#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void enqueue(int data){
    if(!isFull()){
        if(isEmpty()){
            front = 0;
        }
        rear= (rear+1) % MAX;
        queue[rear] = data;
    }
    else{
        printf("\nqueue is full!");
    }
}

void dequeue(){
    if(isEmpty()){return -1;}

    if (front==rear) {
    front =-1;
    rear=-1;
    }
    else{
        front = (front+1) % MAX;
    }
    }


void printQueue(){
    int i=0;
    if(!isEmpty()){
        for(i=front; i!=rear; i=(i+1) % MAX){
            printf("\n%d", queue[i]);
        }
        printf("\n%d", queue[i]);
    }
}

int isFull(){
    if((front == rear+1) || ( (front == 0) && rear == MAX-1) ){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front == -1 && rear==-1){
        printf("\nqueue is empty!");
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
    dequeue();
    dequeue();
    enqueue(343);
    enqueue(43);
    enqueue(4);
    enqueue(434);
    dequeue();
    enqueue(56);
    enqueue(8);
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    printQueue();
    
}