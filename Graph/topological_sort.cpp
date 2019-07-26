#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

const int EDGES = 100;
int INPUTS[EDGES][2]; // at max we can have 100 edges


/*
    In this problem we'll be given an directed graph, our aim is to find the topological sort
    We can approach this question by DFS and maintaining two more attributes i.e. start and finish,
 */
// *************** CREATE GRAPH UNDIRECTED *******************
struct Node{
    int value; 
    int start;
    int finish;
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
}

// we'll have start counter which will be global
int timer = 0;
void DFS_VISIT(struct Node* S){
    S->visited = true;
    ++timer;
    S->start = timer;
    for(int i = 0; i < S->neighbours.size(); ++i){
        if(S->neighbours[i]->visited == false){
            DFS_VISIT(S->neighbours[i]);
        }
    }
    ++timer;
    S->finish = timer;
}

void DFS(struct Node** arrayOfNodes, int n){
    for(int i = 0; i < n; ++i){
        if(arrayOfNodes[i]->visited == false){
            DFS_VISIT(arrayOfNodes[i]);
        }
    }
}

// we can have one more solution i.e. via BFS
// but we need to have maintain two stacks
// those two stacks will be global
stack<struct Node*> S1; // this is an auxilary stack
stack<struct Node*> S2; // this will contain topological sorted answer
void BFS(struct Node* S){
    int flag = 0;
    queue<struct Node*>Q;
    S->visited = true;
    Q.push(S);
    while(!Q.empty()){
        flag = 1;
        struct Node* current_node = Q.front();
        Q.pop();
        // if it has no neighbour to go to we'll push it in S2 otherwise in S1
        for(int i = 0; i < current_node->neighbours.size(); ++i){
            if(current_node->neighbours[i]->visited == false){
                // neighbour push to S1
                flag = 0;
                current_node->neighbours[i]->visited = true;
                Q.push(current_node->neighbours[i]);
            }
        }

        if(flag == 1){
            S2.push(current_node);
        }else{
            S1.push(current_node);
        }
    }
    
}

void reinitialise(struct Node** arrayOfNodes, int n){
    struct Node* temp;
    for(int i = 0; i < n; ++i){
        temp = arrayOfNodes[i];
        temp->visited = false;
    }
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
    DFS(arrayOfNodes, n);
    // in topological sort we actually arrange the nodes in descending order of their finish time
    // we need to apply sorting based on the finish time
    struct Node* sorted_nodes[n];
    for(int i = 0; i < n; ++i){
        sorted_nodes[i] = arrayOfNodes[i];
    }
    // we'll apply simple bubble sort
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(sorted_nodes[i]->finish < sorted_nodes[j]->finish){
                swap(sorted_nodes[i], sorted_nodes[j]);
            }
        }
    }
    // topological sort
    for(int i = 0; i < n; ++i){
        cout<<"Node: "<<i<<", (S: "<<arrayOfNodes[i]->start<<", F: "<<arrayOfNodes[i]->finish<<")\n";
    }
    cout<<"\nTOPOLOGICAL SORT: \n";
    for(int i = 0; i < n; ++i){
        cout<<sorted_nodes[i]->value<<" ";
    }

    // BFS APPROACH
    reinitialise(arrayOfNodes, n);
    cout<<"\n **** BFS approach ****\n";
    for(int i = 0; i < n; ++i){
        if(arrayOfNodes[i]->visited == false){
            BFS(arrayOfNodes[i]);
        }   
    }
    // print them
    while(!S1.empty()){
        S2.push(S1.top());
        S1.pop();
    }
    while(!S2.empty()){
        cout<<S2.top()->value<<" ";
        S2.pop();
    }
}