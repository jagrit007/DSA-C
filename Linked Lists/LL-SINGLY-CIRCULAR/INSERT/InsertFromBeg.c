#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * last;

void insertAtBeg(int data){

    // prepare the node
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    if(last == NULL){
        last = new_node;
        last->next = last;
    }   
    else{
        new_node->next = last->next;
        last->next = new_node;
    }
}

void display(){
    struct node * start;
    start = last->next;
    while(start != last){
        printf("%d\n", start->data);
        start = start->next;
    }
    printf("%d\n", start->data);
}

int main(){
    insertAtBeg(5);
    insertAtBeg(4);
    insertAtBeg(3);
    insertAtBeg(2);
    insertAtBeg(1);
    display();
}