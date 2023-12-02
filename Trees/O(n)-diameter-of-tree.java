// max distance from one node to anther
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * right;
    struct Node * left;
};

struct TreeInfo {
    int ht;
    int diam;
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


struct TreeInfo diameterOfTree(struct Node * root){
    if(root == NULL){
        return (struct TreeInfo){.ht=0, .diam=0};
    }

    struct TreeInfo leftStruct = diameterOfTree(root->left);
    struct TreeInfo rightStruct = diameterOfTree(root->right);
    
    int heightOfTree = 0;
    if(leftStruct.ht > rightStruct.ht) {
        heightOfTree = leftStruct.ht + 1;
    }
    else{
        heightOfTree = rightStruct.ht + 1;
    }
    int max_diam = 0;
    
    if(leftStruct.diam > rightStruct.diam){
        if(leftStruct.diam > heightOfTree){
            max_diam = leftStruct.diam;
        }
        else{
            max_diam = heightOfTree;
        }
    }
    else {
        if(rightStruct.diam > heightOfTree){
            max_diam = rightStruct.diam;
        }
        else{
            max_diam = heightOfTree;
        }
    }
    return (struct TreeInfo){.ht=heightOfTree, .diam=max_diam};
}

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct Node * root = buildTree(nodes);
    printf("%d\n", root->data);
    struct TreeInfo x = diameterOfTree(root);
    printf("\n%d", x.diam);
    return 0;
}