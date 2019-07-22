#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
    We want to not only follow level order traversal but also print the next level in the next line in a zig zag fashion
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
void zig_zag(struct Node* root){
    struct Node* temp;
    queue<struct Node*> Q;
    Q.push(root);
    int parent = 1; // root is one parent
    int child = 0;
    vector<int> values;
    int flag = 1; // 0 means print left->right, otherwise right->left
    cout<<root->data<<" ";
    while(!Q.empty()){
        while(parent > 0 && !Q.empty()){
            temp = Q.front();
            Q.pop();
            parent--;
            if(temp->left != nullptr){
                Q.push(temp->left);
                values.push_back(temp->left->data);
                ++child;
            }
            if(temp->right != nullptr){
                Q.push(temp->right);
                values.push_back(temp->right->data);
                ++child;
            }

        }
        if(flag == 0){
            
            for(int i = 0; i < values.size(); ++i){
                cout<<values[i]<<" ";
            }
            flag = 1;
            
            while(values.size() != 0){
                values.pop_back();
            }
        }else{

            for(int i = values.size() - 1; i > -1; --i){
                cout<<values[i]<<" ";
            }
            flag = 0;
            
            while(values.size() != 0){
                values.pop_back();
            }
        }

        parent = child;
        child = 0;

    }
}

int main(){
    // we'll provide an array and it will be converted into a binary search tree
    int A[] = {10, 5, 18, 2, 12, 20};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    zig_zag(root);
    return 0;
}