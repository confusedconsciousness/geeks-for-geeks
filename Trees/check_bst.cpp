#include<iostream>
using namespace std;
/*
    in this problem we need to check whether the given tree is a BST 
     a binary search tree is a tree in which its left child is always smaller or equal to the parent node and its right child is
     always bigger than the parent node
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

bool check_bst_expensive(struct Node* root){
    // computationally expensive and i guess it fails for certain inputs
    if(root == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->left != nullptr && root->right == nullptr){
        if((root->left->data <= root->data) && check_bst_expensive(root->left)){
            return true;
        }else{
            return false;
        }
    }else if(root->left == nullptr && root->right != nullptr){
        if((root->right->data > root->data) && check_bst_expensive(root->right)){
            return true;
        }else{
            return false;
        }
    }else {
        if((root->right->data > root->data) && (root->left->data <= root->data) && check_bst_expensive(root->left) && check_bst_expensive(root->right)){
            return true;
        }else{
            return false;
        }
    }
}


bool check_bst(struct Node* root, int l, int h){
    // the bst will take a node to root and two more parameters that basically defines the range for its left child and for its right child
    if(root == nullptr){
        return true;
    }else if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->left != nullptr && root->right == nullptr){

        if((root->left->data <= root->data) && (root->left->data > l) && check_bst(root->left, l, root->left->data)){
            return true;
        }else{
            return false;
        }

    }else if(root->left == nullptr && root->right != nullptr){
        if((root->right->data > root->data) && (root->right->data < h) && check_bst(root->right, root->data, h)){
            return true;
        }else{
            return false;
        }
    }
    else{
        
        if((root->left->data <= root->data) && (root->left->data > l) && (root->right->data > root->data) && (root->right->data < h) && check_bst(root->left, l, root->data) && check_bst(root->right, root->data, h)){
            return true;
        }else{
            return false;
        }
    }

}


int main(){
    int A[] = {10, 5, 18, 12, 2, 6, 7, 20};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    cout<<"is balanced? "<<check_bst(root, -65536, 65536);
}