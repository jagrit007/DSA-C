#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

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

char pop(){
    if(isEmpty() == 1){
        printf("\nThe Stack is empty!");
        return;
    }
    else{
        // printf("\nPopped: %c", stack[top]);
        char temp = stack[top];
        top -= 1;
        return temp;
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

void printChArray(char c1[]){
    printf("\n");
    for(int i=0; c1[i]!='\0'; i++){
        printf("%c\t", c1[i]);
    }
}

int getPrecedence(char exp){
    switch(exp){
        case'(':
        return 0;
        case'+':
        case'-':
        return 1;
        case'*':
        case'/':
        return 2;
        case '^':
        return 3;
    }
}

int main(){
    char exp[SIZE], result[SIZE];
    int k=0;
    printf("Enter the expression: ");
    // gets(exp);
    scanf("%s", &exp);
    printf("\nRecieved the expression: %s", exp);
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            printf("\npushing ( to the stack");
            push(exp[i]);
        }
        else if(isalnum(exp[i])){
            printf("\npushing alnum to final result");
            result[k++] = exp[i];
        }
        else if(exp[i] == ')'){
            printf("\ngot ), now i will pop till i find opening bracket");
            while(stack[top] != '('){
                printf("\npopping %c and adding to final result", stack[top]);
                result[k++] = pop();
            }
            pop(); // now for the '('
        }
        else{
            // not ( ) but some other operators, check precedence
            if(getPrecedence(stack[top]) >= getPrecedence(exp[i])){
                while(getPrecedence(stack[top]) >= getPrecedence(exp[i])){
                    printf("\npopping %c", stack[top]);
                    result[k++] = pop();
                }
                push(exp[i]);
            }
            else{
                push(exp[i]);
            }
        }
    }
    while(!isEmpty()){
        printf("\npopping %c", stack[top]);
        result[k++] = pop();
    }
    printChArray(result);
}