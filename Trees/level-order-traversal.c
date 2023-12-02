#include<stdio.h>
#include<stdlib.h>

// queue start
#define MAX 15

int rear = -1, front = -1;
struct Node * queue[MAX];

void enqueue(struct Node * data){
    if(!isFull()){
        if(isEmpty()){
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
    // else{
    //     printf("\nqueue is full!");
    // }
}

struct Node * dequeue(){
    if(!isEmpty()){
        return queue[(front++)];
    }
}

// void printQueue(){
//     if(!isEmpty()){
//         for(int i=front; i<=rear; i++){
//             printf("\n%d", queue[i]->data);
//         }
//     }
// }

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front == -1 || front >= rear){
        // printf("\nqueue is empty!");
        return 1;
    }
    else{
        return 0;
    }
}
// Queue end



struct Node {
    int data;
    struct Node * right;
    struct Node * left;
};

int tree_index = -1;

struct Node * buildTree(int nodes[]){
    tree_index++;

    if(nodes[tree_index] == -1){
        return NULL;
    }
    
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = nodes[tree_index];
    new_node->left = buildTree(nodes);
    new_node->right = buildTree(nodes);

    return new_node;
}

void levelOrder(struct Node * root){
    if(root == NULL)
        return;
    
    enqueue(root);
    enqueue(NULL);
    while(!isEmpty()){
        struct Node * currNode = dequeue();
        if(currNode == NULL){
            printf("\n");
            if(isEmpty()){
                break;
            }
            else{
                enqueue(NULL);
            }
        }
        else{
            printf("%d\t", currNode->data);
            if(currNode->left !=NULL){
                enqueue(currNode->left);
            }
            if(currNode->right !=NULL){
                enqueue(currNode->right);
            }
        }
    }

}

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct Node * root = buildTree(nodes);
    // printf("%d\n", root->data);
    levelOrder(root);
    return 0;
}