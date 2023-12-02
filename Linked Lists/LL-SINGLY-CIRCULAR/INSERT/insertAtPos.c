#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * last;

void insertAtEnd(int data){
    // prepare the node
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    //last exists?
    if(last == NULL){
        last = new_node;
        last->next = last;
    }
    else{
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
}

void insertAtPos(int data, int pos){
    // prepare the node
    struct node * new_node, * prev, * temp;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;

    //last exists?
    if(last == NULL || last->next == last){
        printf("Linked list is empty!");
        return;
    }
    else{
        temp = last->next;
        for(int i=1; i<pos; i++){
            prev = temp;
            temp = temp->next;
            if(temp == last->next){
                printf("The linked list does not have enought elements to insert at given postition!\n");
                break;
            }
        }
        if(temp == last->next) return;
        new_node->next = prev->next;
        prev->next = new_node;
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
    insertAtEnd(5);
    insertAtEnd(4);
    insertAtEnd(3);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtPos(69, 4);
    display();
}