#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * start;

void deleteFromBeg(){
    // struct node * temp;
    if(start == NULL){
        printf("Nothing is there to delete!");
    }
    else{
        // temp = start;
        start = start->next;
        
    }
}

void insertAtBeg(int data){
    struct node * new_node, * temp;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(start==NULL){
        // printf("Start was null\n");
        start = new_node;
        // printf("%d\n", start->data);
    }
    else{
        // printf("In else part!\n");
        new_node->next = start;
        start = new_node;
        // start->next = temp;
        // free(temp);
        
    }
}

void display(){
    struct node * temp = start;
    if(start==NULL){
        printf("Linked list is empty!");
    }
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    insertAtBeg(4);
    insertAtBeg(3);
    insertAtBeg(2);
    insertAtBeg(1);
    deleteFromBeg();
    deleteFromBeg();
    display();
}