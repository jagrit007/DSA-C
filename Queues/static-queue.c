#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int rear = -1, front = -1;
int queue[MAX];

void enqueue(int data){
    if(!isFull()){
        if(isEmpty()){
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
    else{
        printf("\nqueue is full!");
    }
}

void dequeue(){
    if(!isEmpty()){
        front++;
    }
}

void printQueue(){
    if(!isEmpty()){
        for(int i=front; i<=rear; i++){
            printf("\n%d", queue[i]);
        }
    }
}

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front == -1 || front >= rear){ // front >= rear means all elements of queue are deleted
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
    enqueue(343);
    enqueue(43);
    enqueue(4);
    enqueue(434);
    enqueue(56);
    enqueue(8);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    
}