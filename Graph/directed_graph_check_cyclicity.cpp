#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int EDGES = 100;
int INPUTS[EDGES][2]; // at max we can have 100 edges


/*
    In this problem we'll be given an directed graph, our aim is to detect whether there is a cycle present?
    This problem is little bit tricky than its undirected counterpart
    The idea is you are given a source and if you reach your source again while searching then there exists a cycle

 */
// *************** CREATE GRAPH UNDIRECTED *******************
struct Node{
    int value; 
    vector<struct Node*> neighbours;
    bool visited;
};

struct Node* create_node(int value){
    struct Node* new_node = new Node();
    new_node->value = value;
    new_node->visited = false;
    return new_node;
}

void link_them(int n1, int n2, struct Node** arrayOfNodes){
    // this function takes two parameters 
    // the value of nodes i.e n1 and n2
    // this function adds n2 to n1s neighbour and not n1 to n2s since it is directed
    struct Node* node1 = arrayOfNodes[n1];
    struct Node* node2 = arrayOfNodes[n2];

    node1->neighbours.push_back(node2);
}

int bfs(struct Node* S){
    queue<struct Node*> Q;
    S->visited = true;
    Q.push(S);
    while(!Q.empty()){
        struct Node* current_node = Q.front();
        //cout<<"total neighbours: "<<current_node->neighbours.size()<<"\n";
        Q.pop();
        // we will look at its all neighbours
        for(int i = 0; i < current_node->neighbours.size(); ++i){
            if(current_node->neighbours[i]->visited == true && current_node->neighbours[i] == S){
                // there exist a cycle
                return 1;
            }else if(current_node->neighbours[i]->visited == false){
                // visit the node
                current_node->neighbours[i]->visited = true;
                Q.push(current_node->neighbours[i]);
            }
        }

    }
    return 0;
}

void reinitialise(struct Node** arrayOfNodes, int n){
    struct Node* temp;
    for(int i = 0; i < n; ++i){
        temp = arrayOfNodes[i];
        temp->visited = false;
    }
}

// Different approach
// we'll store the ancestor into a vector and as we check if there is a neighbour which is visited and ancestor then you return true
vector<struct Node*> ancestors;
bool dfs_visit(struct Node* S){
    S->visited = true;
    // we'll look its neighbours but before let's push it into the ancestors
    ancestors.push_back(S);
    for(int i = 0; i < S->neighbours.size(); ++i){
        if(S->neighbours[i]->visited == true){
            // let's look in the ancestor list
            for(int j = 0; j < ancestors.size(); ++j){
                if(ancestors[j] == S->neighbours[i]){
                    cout<<" called";
                    return 1;
                }
            }
            return 0;
        }else if(S->neighbours[i]->visited == false){
            dfs_visit(S->neighbours[i]);
        }
    }
    return 0;
}
int dfs(struct Node** arrayOfNodes, int n){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        if(arrayOfNodes[i]->visited == false){
            sum += dfs_visit(arrayOfNodes[i]);
        }
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
    // BFS approach kind of poor irony

    int sum = 0;
    for(int i = 0; i < n; ++i){
        if(sum > 0){
            break;
        }
        sum += bfs(arrayOfNodes[i]);
        reinitialise(arrayOfNodes, n);
    }
    
    if(sum > 0){
        cout<<"There exists a cycle";
    }else{
        cout<<"No cycle exists";
    }

    // DFS approach
    //cout<<"Cycle?: "<<dfs(arrayOfNodes, n);
    return 0;

}