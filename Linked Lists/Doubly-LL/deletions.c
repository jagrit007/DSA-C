#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node * tail, * head;

void insertAtBeg(int data){
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    // prep node
    new_node-> data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if(head == NULL){
        // printf("\nThe linked list is empty!");
        tail = new_node;
        head = new_node;
        return;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        // printf("\nnew node inserted");
    }
}

void insertAtEnd(int data){
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if(tail == NULL){
        // empty ll
        head = tail = new_node;
        return;
    }
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }
}

void insertAtPos(int data, int pos){
    struct node * new_node, * temp;
    new_node = (struct node *) malloc(sizeof(struct node));
    // prep
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;

    //ll null?
    if(head == NULL){
        printf("LL is empty!");
        return;
    }
    else{
        temp = head;
        //insert at pos! (not after pos!)
        if(pos == 0 || pos == 1){
            insertAtBeg(data);
            return;
        }
        if(pos < 0){
        printf("invalid pos!");
        return;
        }
        for(int i=1; i<pos; i++){
            if(temp==NULL){
                printf("The pos doesnt exist!");
                return;
            }
            temp = temp->next;
        }
        printf("i am here bro: %d", temp->data);
        new_node->prev = temp->prev;
        new_node->next = temp;
        temp->prev->next = new_node;
        // new_node->prev = temp;
        // new_node->next = temp->next;
        // temp->next->prev = new_node;
    }
}

void deleteFromBeg(){
    struct node * temp;
    temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    free(temp);
}

void deleteFromEnd(){
    struct node * temp;
    temp = tail;
    temp->prev->next = NULL;
    tail = temp;
    // free(temp);
}

void deleteAtPos(int pos){
    struct node * temp;
    temp = head;
    
    if(head == NULL){
        printf("\nEmpty ll!\n");
        return;
    }
    else{
        for(int i=1; i<pos; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("\nPos does not exist\n");
                return;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void deleteData(int data){
    int pos = 0;
    struct node * temp=head;
    while(temp != NULL){
        pos +=1;
        if(temp->data == data){
            printf("\nFound data!\n");
            deleteAtPos(pos);
            break;
        }
        if(temp->next == NULL){
            printf("\nData not found!\n");
            return;
        }
        temp = temp->next;
    }
}

void display(){
    struct node * temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
        if(temp == NULL){
            break;
        }
    }
}

int main(){
    insertAtBeg(5);
    insertAtBeg(4);
    insertAtBeg(3);
    insertAtBeg(2);
    insertAtBeg(1);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtEnd(9);
    insertAtPos(69, 4);
    display();
    // deleteFromBeg();
    // deleteFromBeg();
    // deleteFromEnd();
    // deleteFromEnd();
    // deleteAtPos(2);
    deleteAtPos(2);
    deleteData(7);
    
    display();
    return 0;
}