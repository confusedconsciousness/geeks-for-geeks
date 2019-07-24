#include<iostream>
using namespace std;
/*
    in this problem we need to convert a BST into a doubly linked list and that too inplace.
    the idea is to inorder traverse the BST and the order in which the nodes come we put it into a doubly linked list.
    We don't have to create a different doubly linked list but to use the left child pointer of the tree as its prev pointer 
    and right child as next pointer of Doubly linked list
    **a binary search tree is a tree in which its left child is always smaller or equal to the parent node and its right child is
    always bigger than the parent node**
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

struct Node* min_node(struct Node* root){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left == nullptr){
        return root;
    }else{
        return min_node(root->left);
    }
}

struct Node* pointer_to_node(struct Node* root, int value){
    // this function returns a pointer to the node having data equals to value
    if(root->data == value){
        return root;
    }else if(root->data > value){
        return pointer_to_node(root->left, value);
    }else{
        return pointer_to_node(root->right, value);
    }
}

void find_parent(struct Node* root, int value, struct Node** parent){
    // searching in an inorder way
    // i think it will we more optimized if we can use the property of the BST instead of just searching the whole tree
    // it will be more efficient
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        return;
    }
    // first check whether the current root is the parent or not
    
    if(root->left != nullptr && root->left->data == value){
        *parent = root;
    }
    if(root->right != nullptr && root->right->data == value){
        *parent = root;
    }
    // now we will go left or right based on the value
    if(root->right != nullptr && value > root->data){
        // go right 
        //cout<<"root->right->data: "<<root->right->data<<"\n";
        find_parent(root->right, value, parent);
    }else if(root->left != nullptr && value <= root->data){
        // go left
        find_parent(root->left, value, parent);
    }
    
}

bool has_right_child(struct Node* root, int value){
    // this functiont tells us whether the current node has right child or not
    if(root == nullptr){
        return false;
    }else if(root->data == value){
        // we found the current node
        //cout<<"horray";
        if(root->right == nullptr){
            return false;
        }else{
            return true;
        }
    }
    else if(root->data > value){
        // search in the left
        return has_right_child(root->left, value);
    }else{
        // search in the right
        return has_right_child(root->right, value);
    }

}

struct Node* find_inorder_successor(struct Node* root, int value){
    // this function will return the inorder successor of the given value
    // if parent->data < value we will need to find the parent of the parent and again check if the condition holds
    // until we get the parent->data >= value
    // we need to climb up the tree only when the node we are looking don't contain any child or doesn't contain the right child
    // **otherwise we can simply find the inorder traversal by finding the smallest element in the right subtree**
    // so there has to be a way which tell us whether the current node has right child or not or whether it is a leaf or not

    // we have a function specially for this purpose called has_right_child() which gives us true or false result
    struct Node* successor;
    if(has_right_child(root, value)){
        // we don't need to climb up
        successor = min_node(pointer_to_node(root, value)->right);
    }else{
        struct Node* parent;
        int temp = value;
        while(true){
            find_parent(root, temp, &parent);
            if(parent->data > value){
                break;
            }
            temp = parent->data;
        }
        successor = parent;   
    }
    return successor;
}


int main(){
    int A[] = {10, 5, 18, 12, 2, 8, 6, 20};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    struct Node* parent;
    //find_parent(root, 8, &parent);
    //cout<<"parent: "<<parent->data;
    //cout<<"has?: "<<has_right_child(root, 8);
    int n;
    cin>>n;
    // n is the node value to whom you want to find the inorder successor
    cout<<"inorder successor: "<<find_inorder_successor(root, n)->data;
}