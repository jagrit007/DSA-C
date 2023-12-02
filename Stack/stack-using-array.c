#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == SIZE-1){
        printf("Stack is full!");
        return 1;
    }
    else{
        return 0;
    }
}

void pop(){
    if(isEmpty() == 1){
        printf("\nThe Stack is empty!");
        return;
    }
    else{
        printf("\nPopped: %d", stack[top]);
        top -= 1;
    }
}

void push(int data){
    if(isFull() == 1){
        // printf("\nThe Stack is full!");
        return;
    }
    else{
        if(isEmpty() == 1){
            top = 0;
        }
        else{
        top += 1;
        }
        stack[top] = data;
        printf("\nAdded %d to stack", data);
    }
}

void print(){
    if(!isEmpty()){
        for(int i=0; i<=top; i++){
            printf("\n%d", stack[i]);
    }
    }
}

int main(){
    push(4);
    push(3);
    push(5);
    push(6);
    pop();
    push(7);
    print();
    

    return 0;
}