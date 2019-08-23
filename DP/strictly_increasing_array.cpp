#include<iostream>
#include<vector>
using namespace std;

int convert(vector<int> A){
    int n = A.size();
    int LIS[n];
    for(int i = 0; i < n; ++i){
        LIS[i] = 1;
    }
    int len = -1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){

            if(A[j] < A[i] && (i - j) <= (A[i] - A[j])){
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
            len = max(len, LIS[i]);
        }
    }
    return n - len;
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> A;
        for(int i = 0; i < n; ++i){
            int temp;
            cin>>temp;
            A.push_back(temp);
        }
        cout<<convert(A)<<endl;
        --t;
    }
}