#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int returnSum(vector<int> A, vector<int> B){
    int temp_sum = 0;
    for(int i = 0; i < A.size() - 1; ++i){
        temp_sum += A[i];
    }
    for(int i = 0; i < B.size(); ++i){
        temp_sum += B[i];
    }
    return temp_sum;
}

int sumIt(vector<int> A){
    int temp_sum = 0;
    for(int i = 0; i < A.size(); ++i){
        temp_sum += A[i];
    }
    return temp_sum;
}

vector<vector<int> > LIS(vector<int> A, int n){
    vector<vector<int> > L;
    vector<int> temp;
    temp.push_back(A[0]);
    L.push_back(temp);
    for(int i = 1; i < n; ++i){
        int di = A[i];
        int s = 0; // size
        int pos = -1;
        int gap = INT_MAX;
        for(int j = 0; j < i; ++j){
            int dj = L[j].back();
            int summation = sumIt(L[j]);
            if(dj < di && summation >= s){
                s = summation;
                pos = j;
                //gap = (di - dj); // this will help
            }
        }
        temp.clear();
        if(pos == -1){
            temp.push_back(di);
            L.push_back(temp);
        }else{
            temp = L[pos];
            temp.push_back(di);
            L.push_back(temp);
        }
    }
    return L;
}

int bitonic(vector<int> A, int n){
    // first find longest increasing common subsequenc from the left side and then from right side and choose the one which doesn't overlap
    vector<int> B = A; 
    vector<vector<int> > L;
    vector<vector<int> > R;

    // first form L from left
    L = LIS(A, n);
    // now create the Longest increasing subsequence from the back
    reverse(B.begin(), B.end());
    R = LIS(B, n);
    // we need to reverse every index in R
    for(int i = 0; i < R.size(); ++i){
        reverse(R[i].begin(), R[i].end());
    }

    // first we'll duplicate the array

    //let's verify
    // cout<<endl;
    // for(int i = 0; i < L.size(); ++i){
    //     for(int j = 0; j < L[i].size(); ++j){
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i = 0; i < R.size(); ++i){
    //     for(int j = 0; j < R[i].size(); ++j){
    //         cout<<R[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    vector<int> temp;
    for(int i = 0; i < L.size(); ++i){
        temp.push_back(returnSum(L[i], R[L.size() - i - 1]));
    }
    // find the maximum sum
    int max_sum = 0;
    for(int i = 0; i < temp.size(); ++i){
        if(temp[i] > max_sum){
            max_sum = temp[i];
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
        vector<int> A;
        for(int i = 0; i < n; ++i){
            int temp;
            cin>>temp;
            A.push_back(temp);
        }
        cout<<bitonic(A, n)<<endl;
        --t;
    }
}