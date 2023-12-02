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

void deletion(int data){
    struct node * temp, * q;
    // empty ll
    if(last == NULL){
        printf("The linked list in empty!");
        return;
    }
    //just one node
    if(last->next == last && last->data == data){
        printf("%d deleted from list!", last->data);
        last = NULL;
        return;
    }
    temp = last->next;
    // first position!
        if(temp->data == data){
            last->next = temp->next;
            printf("%d deleted from LL!", temp->data);
            free(temp);
            return;
        }
    while(temp->next != last){
        if(temp->next->data == data){
            q = temp->next;
            temp->next = q->next;
            printf("%d deleted from LL!", q->data);
            free(q);
            return;
        }
    temp = temp->next;
    }
    if(last->data == data){
        temp->next = last->next;
        printf("%d deleted from LL!", last->data);
        last = temp;
        return;
    }
    // printf("No such data found!");
}

void display(){
    if(last == NULL){
        printf("Empty LL");
        return;
    }
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
    // insertAtEnd(2);
    // insertAtEnd(1);
    display();
    deletion(5);
    display();
}