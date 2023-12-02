#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * right;
    struct Node * left;
};

struct Node * root = NULL;

struct Node * insert(int data, struct Node * node){
    //Create node for the data to be inserted
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    //new node created
    
    // check if new and empty tree
    if(node == NULL){
        // node = new_node;
        // printf("Root empty");
        return new_node;
    }
    else{
        // printf("Root not empty");
        struct Node * insertedNode;
        // trees is not empty is has nodes already.
        // lets compare the root node data with our data
        if(data > node->data){
            insertedNode = insert(data, node->right);
            node->right = insertedNode;
        }
        else{
            insertedNode = insert(data, node->left);
            node->left = insertedNode;
        }
    }
}

//find min node from the given node
struct Node * findMin(struct Node * node){
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

struct Node * deleteNode(int data, struct Node * node){
    if(node == NULL){
        printf("Data does not exist!");
    }
    else{
        if(data == node->data){
            printf("Node to delete is found!");
            if(node->left == NULL){
                struct Node *temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL) {
                struct Node *temp = node->left;
                free(node);
                return temp;
                // it will get returned to the previous func call
            }
            else {
                //two children
                struct Node *temp = findMin(node->right);
                node->data = temp->data; // overwrite data of the node to be deleted
                node->right = deleteNode(temp->data, node->right);
                // we are doing this last line becase
                // we have already overwritten to new location
                // and now we have to delete it from the previous
                // location where it originally was placed!
            }
        }
        else if(data > node->data){
            node->right = deleteNode(data, node->right);
        }
        else{
            node-> left = deleteNode(data, node->left);
        }
    }
}
 
void preOrder(struct Node * node){
    if(node != NULL){
    printf("%d\t", node->data);
        preOrder(node->left);
        preOrder(node->right);
}
}

void printTree(struct Node *root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}



int main(){
    root = insert(23, root);
    insert(47, root);
    insert(67, root);
    insert(12, root);
    insert(44, root);
    insert(10, root);
    insert(7, root);
    insert(4, root);
    // preOrder(root);
    printTree(root, 0);
    deleteNode(23, root);
    printTree(root, 0);
    return 0;
}