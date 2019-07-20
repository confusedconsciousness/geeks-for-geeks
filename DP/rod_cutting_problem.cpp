#include<iostream>
using namespace std;
/*
    We are given a rod of certain length n, and three values a, b, c
    we need to cut the rod in correspondence to the a, b, c i.e we can't cut any length that we want but only of a, b, c length
    we need to cut in such a way so as to maximise the number of pieces
    i/p: n = 5, a = 1, b = 2, c = 3
    o/p: 5 "we can cut the rod in 5 pieces of length a = 1"
    i/p: n = 25, a = 11, b = 12, c = 13
    o/p: 2 "we can cut b = 12 and c = 13"
    this problem can be done in both the recursive as well as dynamic way
 */

int RCP(int n, int a, int b, int c){
    if(n < 0){
        return -1;
    }else if(n == 0){
        return 0;
    }else{
        return max(max(1 + RCP(n - a, a, b, c), 1 + RCP(n - b, a, b, c)), 1 + RCP(n - c, a, b, c));
    }
}

int main(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    cout<<"Result using Recursion: "<<RCP(n, a, b, c);
    // Now let's create a dynamic solution
    // since there is one thing that is varying thus we'll need a 1D array
    int DP[n + 1];
    DP[0] = 0; // base case
    for(int i = 1; i <= n; ++i){
        DP[i] = -1; 
        if(i - a >= 0){
            DP[i] = max(1 + DP[i - a], DP[i]);
        }
        if(i - b >= 0){
            DP[i] = max(1 + DP[i - b], DP[i]);
        }
        if(i - c >= 0){
            DP[i] = max(1 + DP[i - c], DP[i]);
        }
    }
    cout<<"\nResult using DP: "<<DP[n];
    return 0;
}