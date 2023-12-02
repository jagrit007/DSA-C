// max distance from one node to anther
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

int TreeHeight(struct Node * root){
    if(root == NULL){
        return 0;
    }

    int leftHt = TreeHeight(root->left);
    int rightHt = TreeHeight(root->right);
    int ht = 0;
    if(leftHt > rightHt)
    ht = leftHt+1;
    else
    ht = rightHt+1;

    return ht;
}

int diameterOfTree(struct Node * root){
    if(root == NULL){
        return 0;
    }

    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);
    int heightOfTree = TreeHeight(root->left) + TreeHeight(root->right) + 1;

    int diam = 0;

    if(leftDiameter > rightDiameter){
        if(leftDiameter > heightOfTree){
            return leftDiameter;
        }
        else{
            return heightOfTree;
        }
    }
    else {
        if(rightDiameter > heightOfTree){
            return rightDiameter;
        }
        else{
            return heightOfTree;
        }
    }
}

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct Node * root = buildTree(nodes);
    printf("%d\n", root->data);
    int x = diameterOfTree(root);
    printf("\n%d", x);
    return 0;
}