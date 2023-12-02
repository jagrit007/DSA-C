#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * start;

void deleteAtPos(int pos){
    struct node * temp, * prev;
    if(start == NULL){
        printf("Nothing is there to delete!");
    }
    else{
        temp = start;
        for(int i=1; i<pos; i++){
            prev = temp;
            temp = temp->next;
            if(temp == NULL){
            printf("No such position!");
        }
        }
        prev->next = temp->next;
        free(temp);

        
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
    deleteAtPos(3);
    deleteAtPos(2);
    
    display();
}