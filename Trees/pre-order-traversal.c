#include<stdio.h>
#include<stdlib.h>

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

void preOrder(struct Node * root){
    printf("%d\t", root->data);
    if(root->left != NULL){
        preOrder(root->left);
    }
    if(root->right != NULL){
        preOrder(root->right);
    }
}

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct Node * root = buildTree(nodes);
    printf("%d\n", root->data);
    preOrder(root);
    return 0;
}