#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
    in this problem we need to compute the height of the binary tree
 */
// basic definition of node in our tree
//***************************** CREATION OF BST ******************************
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* create_node(int data){
    struct Node* new_node = new Node();
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

struct Node* place_node(struct Node* node, struct Node* root){
    // this function takes two pointers, one to the root of the tree and other to the node that need to be inserted
    if(root == nullptr){
        root = node;
    }else if(root->data >= node->data){
        // go to the left and find your position
        root->left = place_node(node, root->left);
    }else{
        // go to the right and find your position
        root->right = place_node(node, root->right);
    }
    return root;
}

struct Node* create_tree(int *A, int n){
    struct Node* root = nullptr;
    struct Node* node;
    for(int i = 0; i < n; ++i){
        node = create_node(A[i]);
        root = place_node(node, root);
    }
    return root;
}
//*******************************************************************************

int find_height(struct Node* root){
    if(root == nullptr){
        return -1;
    }
    return max(1 + find_height(root->left), 1 + find_height(root->right));

}

int main(){
    int A[] = {10, 5, 18, 30};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    cout<<"height of the tree: "<<find_height(root) + 1;

}