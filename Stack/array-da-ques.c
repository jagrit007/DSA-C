// 1.	Students of a Programming class arrive to submit assignments. Their register numbers are stored in a LIFO list in the order in which the assignments are submitted. Write a program using array to display the register number of the ten students who submitted first. 

// Register number of the ten students who submitted first will be at the bottom of the LIFO list. Hence pop out the required number of elements from the top so as to retrieve and display the first 10 students.

// Low Level: Display the register number of the last submitted record [6 Marks]

// Middle Level: Display the register number of the ten students who submitted first [2 Marks]

// High Level: Any query posed by faculty such as checking if a particular student has submitted the assignment or not [2 Marks]


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100
char stack[SIZE][15]; //15 for each reg no.
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
        // printf("\nPopped: %s", stack[top]);
        top -= 1;
    }
}

void push(char data[15]){
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
        // stack[top] = data;
        strcpy(stack[top], data);
        // printf("\nAdded %s to stack", data);
    }
}

void print(){
    if(!isEmpty()){
        for(int i=0; i<=top; i++){
            printf("\n%s", stack[i]);
    }
    }
}


// solving ques
//middle level
void firstTen(){
    while(top != 9){
        pop();
    }
    print();
}

void search(char key[15]){
    while(strcmp(stack[top], key)){
        if(top!=-1)
        pop();
        else{
        printf("\nNot found");
        return;}
    }
    printf("%s is found!", stack[top]);
}


int main(){
    push("23MCA0289");
    push("23MCA0291");
    push("23MCA0292");
    push("23MCA0293");
    push("23MCA0294");
    push("23MCA0295");
    push("23MCA0296");
    push("23MCA0297");
    push("23MCA0298");
    push("23MCA0299");
    push("23MCA0211");
    push("23MCA0212");
    push("23MCA0213");
    push("23MCA0214");
    push("23MCA0215");
    push("23MCA0216");
    push("23MCA0217");
    push("23MCA0218");
    push("23MCA0219");
    push("23MCA0220");
    push("23MCA0221");
    // firstTen();
    search("23MCA0218");
    // print();
    return 0;
}