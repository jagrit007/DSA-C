#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
char stack[SIZE];
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
        // printf("\nPopped: %c", stack[top]);
        top -= 1;
    }
}

void push(char data){
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
        // printf("\nAdded %c to stack", data);
    }
}

void print(){
    if(isEmpty() == 0){
        for(int i=0; i<=top; i++){
            printf("\n%c", stack[i]);
    }
    }
}

int main(){
    char exp[SIZE];
    printf("Enter the expression: ");
    // gets(exp);
    scanf("%s", &exp);
    printf("\nRecieved the expression: %s", exp);
    for(int i=0; exp[i]!='\0'; i++){
        // printf("%c\t", exp[i]);
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
            // printf("\ntop: %d", top);
            continue;
        }
        
            if(exp[i] == ')'){
                // printf("got )");
                if(isEmpty() == 0){
                    if(stack[top] == '('){
                        pop();
                        continue;
                    }
                    else{
                        continue;
                    }
                }
            }
            if(exp[i] == ']'){
                if(isEmpty() ==0){
                    if(stack[top] == '['){
                        pop();
                        continue;
                    }
                    else{
                        continue;
                    }
                }
            }
            if(exp[i] == '}'){
                if(isEmpty() ==0){
                    if(stack[top] == '{'){
                        pop();
                        continue;
                    }
                    else{
                        continue;
                    }
                }
            }
        
    }
    // printf("top: %d", top);
    if( top == -1){
        printf("\nBalanced!");
    }
    else{
        printf("\nNot Balanced!");
    }
return 0;}
