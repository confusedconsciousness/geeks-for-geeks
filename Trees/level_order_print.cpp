#include<iostream>
#include<queue>
using namespace std;
/*
    We want to not only follow level order traversal but also print the next level in the next line
    *** find the max width is one of its variant ***
 */
// basic definition of node in our tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// basic definition of Queue
struct Node* ARRAY[256];
class Queue{
    int front;
    int rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        void enqueue(struct Node* node);
        struct Node* dequeue();
        bool empty();

};

void Queue::enqueue(struct Node* node){
    if(front == -1 && rear == -1){
        ++front;
        ++rear;
        ARRAY[rear] = node;
    }else{
        ++rear;
        ARRAY[rear] = node;
    }
}

struct Node* Queue::dequeue(){
    struct Node* temp = ARRAY[front];
    ++front;
    return temp;
}

bool Queue::empty(){
    if(front == rear + 1){
        return true;
    }else{
        return false;
    }
}

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

void level_order(struct Node* root){
    // my solution way too complicated
    Queue Q;
    int childs = 0;
    int parents = 1;
    struct Node* temp;
    Q.enqueue(root);
    while(!Q.empty()){
        while(parents > 0 && !Q.empty()){

                temp = Q.dequeue(); // dequeue will be perform based on the number of children
                cout<<temp->data<<" ";
                parents--; 

                if(temp->left != nullptr){
                    Q.enqueue(temp->left);
                    ++childs;
                }
                if(temp->right != nullptr){
                    Q.enqueue(temp->right);
                    ++childs;
                }
            }
        cout<<"\n";
        parents = childs;
        childs = 0;
    }
    
}

void alternative_1(struct Node* root){
    // we will maintain a level variable
    struct Node* temp;
    queue<pair<struct Node*, int> > Q;
    int level = 0;
    // we will create a pair
    pair<struct Node*, int> P;
    P.first = root;
    P.second = level;
    Q.push(P);
    int current_level;
    while(!Q.empty()){
        P = Q.front();
        Q.pop();

        temp = P.first;
        current_level = P.second;
        
        if(current_level != level){
            level = current_level;
            cout<<"\n";
        }

        cout<<temp->data<<" ";

        if(temp->left != nullptr){
            P.first = temp->left;
            P.second = current_level + 1;
            Q.push(P);
        }
        if(temp->right != nullptr){
            P.first = temp->right;
            P.second = current_level + 1;
            Q.push(P);
        }

    }

}

// void alternative_2(struct Node* root){
//     // we will maintain a level variable
//     // this will not work
//     Queue Q;
//     Q.enqueue(root);
//     Q.enqueue(nullptr);
//     struct Node* temp;
//     while(!Q.empty()){
//         temp = Q.dequeue();
//         if(temp == nullptr){
//             cout<<"\n";
//             temp = Q.dequeue();
//         }
//         cout<<temp->data<<" ";

//         if(temp->left != nullptr){
//             Q.enqueue(temp->left);
//         }
//         if(temp->right != nullptr){
//             Q.enqueue(temp->right);
//         }

//     }

// }
int main(){
    // we'll provide an array and it will be converted into a binary search tree
    //int A[] = {10, 5, 18, 2, 7, 12, 20};
    int A[] = {10, 5, 18, 2, 12, 20};
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    level_order(root);
    cout<<"\n";
    alternative_1(root);
    cout<<"\n";
    return 0;
}