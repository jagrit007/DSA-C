#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node * next;
};

struct node * last;

struct node deleteOnPos(int pos){
    if(last==NULL){
        printf("The linked list in empty");
        return;
    }
    struct node * prev;
    struct node * temp = last->next;
    for(int i=1; i<pos; i++){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("pos does not exist!");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);

}

void insertAtEnd(char data){

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

void flames(int charCount){
    struct node * temp, * prev;
    temp=last->next;
    prev = temp;
    while(temp != last){
        for(int i=0; i<charCount; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if(last == temp){
            last = prev;
        }
        free(temp);
        display();
        temp = prev;
    }
    switch(last->data){
        case 'F':
        printf("\nfriends");
        break;
        case 'L':
        printf("\nlovers");
        break;
        case 'A':
        printf("\naffection");
        break;
        case 'M':
        printf("\nmarriage");
        break;
        case 'E':
        printf("\nenemies");
        break;
        case 'S':
        printf("\nsisters");
        break;
    }
}

void display(){
    if(last == NULL){
        printf("Empty LL");
        return;
    }
    struct node * start;
    start = last->next;
    printf("\n");
    while(start != last){
        printf("%c ", start->data);
        start = start->next;
    }
    printf("%c", start->data);
}

int main(){
    insertAtEnd('F');
    insertAtEnd('L');
    insertAtEnd('A');
    insertAtEnd('M');
    insertAtEnd('E');
    insertAtEnd('S');
    
    display();

    printf("\nEnter the number of characters: ");
    int charCount;
    scanf("%d", &charCount);
    printf("\nCalculating...\n");
    flames(charCount);
}