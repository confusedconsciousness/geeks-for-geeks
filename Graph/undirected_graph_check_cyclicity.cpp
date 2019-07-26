#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int EDGES = 100;
int INPUTS[EDGES][2]; // at max we can have 100 edges


/*
    In this problem we'll be given an undirected graph, our aim is to detect whether there is a cycle present?
    We can approach this question by BFS,
    We will visit each node but we'll also maintain an extra attribute i.e. parent, which will tell us from where actually we ended
    to the given node
 */
// *************** CREATE GRAPH UNDIRECTED *******************
struct Node{
    int value; 
    vector<struct Node*> neighbours;
    struct Node* parent;
    bool visited;
};

struct Node* create_node(int value){
    struct Node* new_node = new Node();
    new_node->value = value;
    new_node->parent = nullptr;
    new_node->visited = false;
    return new_node;
}

void link_them(int n1, int n2, struct Node** arrayOfNodes){
    // this function takes two parameters
    // the value of nodes i.e n1 and n2
    // this function adds n2 to n1s neighbour and n1 to n2s neighbour
    struct Node* node1 = arrayOfNodes[n1];
    struct Node* node2 = arrayOfNodes[n2];

    node1->neighbours.push_back(node2);
    node2->neighbours.push_back(node1);
}

int bfs(struct Node* S){
    queue<struct Node*> Q;
    S->visited = true;
    S->parent = nullptr;
    Q.push(S);
    while(!Q.empty()){
        struct Node* current_node = Q.front();
        //cout<<"total neighbours: "<<current_node->neighbours.size()<<"\n";
        Q.pop();
        // we will look at its all neighbours
        for(int i = 0; i < current_node->neighbours.size(); ++i){
            if(current_node->neighbours[i]->visited == true && current_node->neighbours[i]->value != current_node->parent->value){
                // there exist a cycle
                //cout<<"I've been here";
                return 1;
            }else if(current_node->neighbours[i]->visited == false){
                // visit the node
                current_node->neighbours[i]->visited = true;
                current_node->neighbours[i]->parent = current_node;
                Q.push(current_node->neighbours[i]);
            }
        }

    }
    return 0;
}

int main(){
    // input will be in the following format
    // n, e // n is total nodes and e is total edges
    // followed by e lines taking input
    // e1, e2 means e1 is connected to e2
    int n, e;
    cin>>n>>e;
    
    for(int i = 0; i < e; ++i){
        for(int j = 0; j < 2; ++j){
            cin>>INPUTS[i][j];
        }
    }
    // let's create n nodes
    struct Node* arrayOfNodes[n];
    for(int i = 0; i < n; ++i){
        arrayOfNodes[i] = create_node(i); // we are naming the nodes from 0 to n - 1
    }
    // it's time to make links
    int n1, n2;
    for(int i = 0; i < e; ++i){
        n1 = INPUTS[i][0];
        n2 = INPUTS[i][1];
        link_them(n1, n2, arrayOfNodes);
    }
    cout<<"Cycle? : "<<bfs(arrayOfNodes[0]);

}