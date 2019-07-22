#include<iostream>
#include<queue>
using namespace std;
/*
    We need to print the nodes present at a particular level
    I/P: 
                10
               /  \
            5       18
           / \      / \
          2   6    12  20
         /              \
        1               30
    k = 2
    O/P:  2,6,12,20
    k = 3
    O/P: 1, 30
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

void level_order(struct Node* root, int level){
    // my solution way too complicated
    Queue Q;
    int childs = 0;
    int parents = 1;
    struct Node* temp;
    int k = 0;
    int flag = 0;
    Q.enqueue(root);
    while(!Q.empty()){
        if(k == level){
            flag = 1;
        }else if(k > level){
            break;
        }
        ++k;
        while(parents > 0 && !Q.empty()){

            temp = Q.dequeue(); // dequeue will be perform based on the number of children
            if(flag == 1){
                cout<<temp->data<<" ";
            }
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
        flag = 0;
        parents = childs;
        childs = 0;
    }
    
}

void alternate_solution(struct Node* root, int level){
    // i think we can do it with pairs stuff
    queue<pair<struct Node*, int> > Q;
    // the pair will contain the pointer to the node and the level
    // let's push the root
    pair<struct Node*, int> P;
    P.first = root;
    P.second = 0; // for root level = 0
    Q.push(P);
    int k;
    struct Node* temp;
    while(!Q.empty()){
        P = Q.front();
        Q.pop();
        temp = P.first;
        k = P.second;
        if(k == level){
            cout<<temp->data<<" ";
        }
        if(k > level){
            // no need for traversing further
            break;
        }
        if(temp->left != nullptr){
            P.first = temp->left;
            P.second = k + 1;
            Q.push(P);
        }
        if(temp->right != nullptr){
            P.first = temp->right;
            P.second = k + 1;
            Q.push(P);
        }

    }

}

void print_given_level(struct Node* root, int k){
    // best solution
    if(root == nullptr){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }
    // this is basically traversal but with one extra parameter which checks your depth as well
    print_given_level(root->left, k - 1);
    print_given_level(root->right, k - 1);
}


int main(){
    // we'll provide an array and it will be converted into a binary search tree
    //int A[] = {10, 5, 18, 2, 7, 12, 20};
    int A[] = {10, 5, 18, 2, 12, 20, 6, 1, 30};
    // assuming that the level of the root is zero
    int level = 2;
    struct Node* root = create_tree(A, sizeof(A) / sizeof(int));
    level_order(root, level);
    cout<<"\n";
    alternate_solution(root, level);
    cout<<"\n";
    print_given_level(root, level);
    return 0;
}