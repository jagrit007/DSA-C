#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
};

struct node * head;

// void insertAtPos(int pos, int data){
//     struct node * new_node, * temp;
//     new_node->data = data;

//     if(head == NULL){
//         printf("The position does not exist!");
//         return;
//     }
//     else{
//         temp = head;
//         for(int i=1; i<pos; i++){
//             temp = temp->next;
//             if(temp == head){
//                 printf("Pos does not exist!");
//                 return;
//             }
//         }
//         new_node->prev = temp->prev;
//         new_node->next = temp;
//         temp->prev->next = new_node;
//         temp->prev = new_node;
//         return;
//     }
// }

void insertAtPos(int pos, int data){
    struct node * new_node, * temp;

    if(head == NULL){
        printf("The pos does not exist!");
        return;
    }
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->next;
        if(temp == head){
            printf("The pos does not exist!");
            return;
        }
    }
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev->next = new_node;
    temp->prev = new_node;


}

struct node * insertAtEnd(int data){
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;

    // check null
    if(head == NULL){
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
        return new_node;
    }
    else{
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
        return new_node;
    }
}

void insertAtBeg(int data){
    struct node * new_node;
    new_node = insertAtEnd(data);
    head = new_node;
}


void display(){
    struct node * temp = head;
    while(temp->next != head){
        printf("%d ", temp->data);
        if(temp == NULL){
            return;
        }
        temp = temp->next;
    }
    printf("%d ", temp->data);
}


int main(){
    insertAtBeg(6);
    insertAtBeg(5);
    insertAtBeg(4);
    insertAtBeg(3);
    insertAtBeg(2);
    insertAtBeg(1);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtPos(9, 69);
    display();
    return 0;
}