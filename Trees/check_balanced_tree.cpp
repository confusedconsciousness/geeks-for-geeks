#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
    in this problem we need to check whether the given tree is a balanced tree
    what is a balanced tree?
    it is a tree in which the difference between the height of their children is atmost 1
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
    // this function will give us the height of the complete tree provided its root
    // here it is not just we need to check for the root but the condition is put upon their children as well
    if(root == nullptr){
        return 0;
    }else{
        return 1 + max(find_height(root->left), find_height(root->right));
    }
}

bool check_balanced(struct Node* root){
    // this solution being intuitive takes a lot computation, its time complexity is O(n ^ 2)
    if(root == nullptr){
        // base condition
        return true;
    }
    // we will use the find_height() function to find whether the difference between the heights is atmost 1
    int h1 = find_height(root->left);
    int h2 = find_height(root->right);
    
    if((abs(h1 - h2) <= 1) && check_balanced(root->left) && check_balanced(root->right)){
        // it is balanced at the top level now check whether there children satisfy it or not
        return true;
    }else{
        return false;
    }

}

int main(){
    int A[] = {10, 5, 3, 18, 30, 1};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    cout<<"Trees are balanced? "<<check_balanced(root);

}