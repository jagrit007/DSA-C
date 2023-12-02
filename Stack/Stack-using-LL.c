 #include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next; 
};

// stack using LL 
// Insert At Beg

struct node * top;

void insert(int data){
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    if(top == NULL){
        top = new_node;
        return;
    }

    new_node-> next = top;
    top = new_node;
}

void delete(){
    if(top == NULL){
        printf("The stack is empty!");
        return;
    }
    struct node * tmp;
    tmp = top;
    top = tmp->next;
    free(tmp);
}

void display(){
    printf("\n");
    struct node * temp;
    if(top == NULL){
        printf("Linked list is empty!");
        return;
    }
    temp = top;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void main(){
    insert(2);
    insert(3);
    insert(5);
    insert(7);
    display();
    delete();
    delete();
    display();
}