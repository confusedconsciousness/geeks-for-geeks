// This code is not complete
#include<iostream>
#include<vector>
using namespace std;

int product(int *A, int n, int k, int s){
    if(n == 0){
        return 0;
    }
    if(s > k){
        return 0;
        // prune this branch
    }
    if(s == k){
        return 1;
    }
    if(s < k){
        // we have three options
        // one option is to select the current element 
        // second option is to set it as the current element
        // third option is to skip it
        int a = 0, b = 0, c = 0;
        if(s * A[n - 1] < k){
            a = 1 + product(A, n - 1, k, s * A[n - 1]); // consider the element
        }
        if(A[n - 1] < k){
            b = 1 + product(A, n - 1, k, A[n - 1]); // consider that element as the starting point
        }
        c = 1 + product(A, n - 1, k , s); // third option skip that element
        return (a + b + c);
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n, k;
        cin>>n;
        int A[n];
        for(int i = 0; i < n; ++i){
            cin>>A[i];
        }
        cin>>k;
        cout<<product(A, n, k, 1);
        --t;
    }
}