#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int findJumps(int *A, int i, int n){
    if(i >= n - 1){
        return 0;
    }
    if(A[i] == 0){
        // we can't go futher from this path we need to return something maximum
        return INT_MAX - 100;
    }
    int val = A[i];
    int res = INT_MAX;
    for(int j = i + 1; j <= min(i + val, n); ++j){
        res = min(res, 1 + findJumps(A, j, n));
    }
    return res;
}

int findJumpsDP(int *A, int i, int n, map<int, int> &M){
    if(M.find(i) != M.end()){
        //cout<<"called";
        return M[i];
    }
    if(i >= n - 1){
        M[i] = 0;
        return M[i];
    }
    if(A[i] == 0){
        // we can't go futher from this path we need to return something maximum
        M[i] = INT_MAX - 100;
        return M[i];
    }
    int val = A[i];
    int res = INT_MAX - 100;
    for(int j = i + 1; j <= min(i + val, n); ++j){
        res = min(res, 1 + findJumpsDP(A, j, n, M));
    }
    M[i] = res;
    return M[i];
}

int main(){
    int t;
    cin>>t;
    while(t){
        map<int, int> M;
        int n;
        cin>>n;
        int A[n];
        for(int i = 0; i < n; ++i){
            cin>>A[i];
        }
        int res = findJumpsDP(A, 0, n, M);
        if(res >= 2147483547 - 100){
            cout<<-1<<endl;
        }else{
            cout<<findJumpsDP(A, 0, n, M)<<endl;
        }
        
        // cout<<findJumps(A, 0, n)<<endl;
        --t;
    }
}