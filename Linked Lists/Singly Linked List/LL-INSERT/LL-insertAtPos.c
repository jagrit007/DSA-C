#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node * next;
};

struct node * start;

void insertAtEnd(int data){
    struct node * new_node, * temp, * prev;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(start==NULL){
        start = new_node;
    }
    else{
        temp = start;
        while(temp!=NULL){
            if(temp->next == NULL){
                temp->next = new_node;
                break;
            }
            temp = temp->next;
        }
    }
        
    }

void insertAtPos(int data, int pos){
    struct node * new_node, * temp, * prev;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(start==NULL){
        start = new_node;
    }
    else{
        temp = start;
        for(int i=1; i<pos; i++){
            if(temp->next == NULL){
                printf("Pos does not exist re!");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        new_node->next = temp;
        prev->next = new_node;
        
    }}

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
    insertAtEnd(4);
    insertAtEnd(3);
    insertAtEnd(2);
    insertAtEnd(1);

    insertAtPos(69, 2);
    insertAtPos(100, 100); //pos does not exist!
    display();
}