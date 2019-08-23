#include<iostream>
using namespace std;

int LSC(int *A, int n){
    int max_sum = A[0];
    int running_sum = A[0];
    for(int i = 1; i < n; ++i){
        running_sum = max(running_sum + A[i], A[i]);
        if(running_sum > max_sum){
            max_sum = running_sum;
        }
    }
    return max_sum;
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
        cout<<LSC(A, n)<<endl;
        --t;
    }
}