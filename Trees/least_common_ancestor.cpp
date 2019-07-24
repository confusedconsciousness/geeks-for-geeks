#include<iostream>
using namespace std;
/*
    In this program we need to find the least common ancestor of two given nodes
    we can approach this problem by finding the parent of the two nodes and we will continue to find parents of parent 
    until they become equal
 */
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

void find_parent(struct Node* root, int value, struct Node** parent){
    // this function basically takes the data of the current node and give us the its parent
    if(root == nullptr){
        return;
    }else if(root->left != nullptr && root->left->data == value){
            *parent = root;
    }
    else if(root->right != nullptr && root->right->data == value){
            *parent = root;
    }
    if(root->data > value){
        // go left
        find_parent(root->left, value, parent);
    }else{
        // go right
        find_parent(root->right, value, parent);
    }
}


int find_level(struct Node* root, int v, int c){
    // this helper function takes the pointer to the root and the node value whose level we need to determine
    // c contains the current level in the beginning it will be zero
    if(root->data == v){
        return c;
    }else if(root->left != nullptr && root->data > v){
        // look in the left
        return find_level(root->left, v, c + 1);
    }else if(root->right != nullptr && root->data < v){
        // look in the right
        return find_level(root->right, v, c + 1);
    }else{
        cout<<"here i am ";
        return c;
    }
}

struct Node* pointer_to_node(struct Node* root, int v){
    // this return the pointer to the node having data equals to v
    if(root->data == v){
        return root;
    }else if(root->left != nullptr && root->data > v){
        // look in the left
        return pointer_to_node(root->left, v);
    }else if(root->right != nullptr && root->data < v){
        // look in the right
        return pointer_to_node(root->right, v);
    }else{
        cout<<"again ";
        return root;
    }
}

int least_common_ancestor(struct Node* root, int v1, int v2){
    // this least common ancestor can be easily found if we somehow can know the level of the 
    // two given nodes, we can then find the parent of the node which is at higher level  so that in the end 
    // both the nodes are at the same level and from there we can move up in the tree till there ancestors are same

    struct Node* parent1 = nullptr;
    struct Node* parent2 = nullptr;
    int l1 = find_level(root, v1, 0);
    int l2 = find_level(root, v2, 0);
     
    while(true){
        
        if(l1 > l2){
            // we need to find the parent of v1
            find_parent(root, v1, &parent1);
            l1 = find_level(root, parent1->data, 0);
            v1 = parent1->data;
        }else if(l2 > l1){
            // we need to find the parent of v2
            find_parent(root, v2, &parent2);
            l2 = find_level(root, parent2->data, 0);
            v2 = parent2->data;
        }else{
            break;
        }

    }
    
    // at this point they have the same level
    
    struct Node* n1;
    struct Node* n2;
    if(parent1 == nullptr && parent2 == nullptr){
        // it means it was never updated in the above while
        n1 = pointer_to_node(root, v1);
        n2 = pointer_to_node(root, v2);
    }else if(parent1 == nullptr){
        n1 = pointer_to_node(root, v1);
        n2 = parent2;
    }else if(parent2 == nullptr){
        n1 = parent1;
        n2 = pointer_to_node(root, v2);
    }else{
        // both were updated this can never happen
        cout<<"both updated, impossible";
    }
        
    while(true){
        if(n1->data == n2->data){
            return n1->data;
        }else{
            // move up
            find_parent(root, n1->data, &parent1);
            find_parent(root, n2->data, &parent2);
            n1 = parent1;
            n2 = parent2;
        }
    }

}

int main(){
    int A[] = {10, 5, 18, 12, 2, 8, 6, 20};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    int v1, v2;
    cin>>v1>>v2;
    cout<<"least common ancestor: "<<least_common_ancestor(root, v1, v2)<<"\n";
}