#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int topX = -1;
int topY = MAX;

int stack[MAX];

void pushX(int data){
    if(!isFullX()){
        if(isEmptyX()){
            topX = 0;
        }
        else{
            topX += 1;
        }
        stack[topX] = data;
    }
}

void pushY(int data){
    if(!isFullY()){
        if(isEmptyY()){
            topY = MAX-1;
        }
        else{
            topY -= 1;
        }
        stack[topY] = data;  
    }
}

int isFullX(){
    if(topX >= topY-1){
    printf("Stack X is full!");
    return 1;
    }
    else{
        return 0;
    }
}


int isFullY(){
    if(topY <= topX+1){
    printf("Stack Y is full!");
    return 1;
    }
    else{
        return 0;
    }
}

int isEmptyX(){
    if(topX == -1)
    return 1;
    else
    return 0;
}

int isEmptyY(){
    if(topY == MAX)
    return 1;
    else
    return 0;
}

void displayX(){
    if(!isEmptyX()){
    for(int i=0; i<=topX; i++){
        printf("\n %d", stack[i]);
    }
    }
}

void displayY(){
    if(!isEmptyY()){
    for(int i=MAX-1; i>=topY; i--){
        printf("\n %d", stack[i]);
    }
    }
}

void popX(){
    if(!isEmptyX()){
        topX -= 1;
    }
    else{
        printf("Stack is empty!");
    }
}
void popY(){
    if(!isEmptyY()){
        topY += 1;
    }
    else{
        printf("Stack is empty");
    }
}

int main(){
    pushX(2);
    pushX(4);
    pushY(10);
    pushY(20);
    pushY(30);
    pushY(40);
    displayX();
    printf("\n\n");
    displayY();
    return 0;
}