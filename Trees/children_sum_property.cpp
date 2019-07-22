#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
    in this problem we need to find whether the binary tree follows children sum property
    in this property the root node value equals to the sum of the left child and right child
    for e.g.  
            10
           /  \
          4    6
         / \   / \
        1   3 2   4
           /
          3
    as you can the above tree follows the children sum property
    O/P: true



 */
// basic definition of node in our tree

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

bool check_property(struct Node* root){

    if(root == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    int sum = 0;
    if(root->left != nullptr){
        sum = sum + root->left->data;
    }
    if(root->right != nullptr){
        sum = sum + root->right->data;
    }
    cout<<"\nsum is: "<<sum<<"\n";
    cout<<"Node value is: "<<root->data<<"\n";
    if((root->data == sum) && check_property(root->left) && check_property(root->right)){
        return true;
    }else{
        return false;
    }

}


int main(){
    // the question requires a normal tree not a BST but above is the method and not the function to create a tree

}