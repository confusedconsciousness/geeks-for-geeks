#include<iostream>
#include<vector>
using namespace std;

int LIS(int *A, int n){
    // we maintain L[i]s // which are nothing but vectors
    vector<vector<int> > L; 
    vector<int> temp;
    temp.push_back(A[0]); // base case L[0] = A[0]
    L.push_back(temp);
    for(int i = 1; i < n; ++i){
        int di = A[i];
        //cout<<"D[i]: "<<di<<endl;
        int s = 0;
        int pos = -1;
        for(int j = 0; j < i; ++j){
            int dj = L[j].back(); // retrieve last element of the L[j]
            int size = L[j].size();
            //cout<<"size:"<<L[j].size();
            //cout<<"D[j]: "<<dj<<endl;
            // we need to find the maximum L

            if(dj <= di && size >= s){
                // valid Li
                s = size;
                pos = j;
            }
        }
        // if we get -1
        temp.clear();
        if(pos == -1){
            temp.push_back(di);
            L.push_back(temp);
        }else{
            // here we'll be having the largest subsequence
            for(int i = 0; i < L[pos].size(); ++i){
                temp.push_back(L[pos][i]);
            }
            temp.push_back(di);
            L.push_back(temp);
        }
       
 
    }
    // for(int i = 0; i < L.size(); ++i){
    //     for(int j = 0; j < L[i].size(); ++j){
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // show the Lis
    int max_size = 0;
    for(int i = 0; i < L.size(); ++i){
        int temp = L[i].size();
        if(temp > max_size){
            max_size = temp;
        }
    }
    return max_size;
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0; i < n; ++i){
            cin>>A[i];
        }
        cout<<LIS(A, n)<<endl;
        --t;
    }
}