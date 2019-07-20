#include<iostream>
#include<string>
using namespace std;
/*
    in this problem we are given two string, S1 and S2, one is called target and other is input
    we need to find the minimum number of changes that we need to do in the input in order to make it equal to target
    the operation that we can perform are: insert, delete, replace
    i/p: T -> "geek", I -> "geeks"
    o/p: 1 (delete s)
    i/p: T -> "sunday", I -> "saturday"
    o/p: 3 (replace r->n, delete a, t)
    we will first formulate a recursion solution then move to a dynamic programming
    this problem is similar to the longest subsequence problem
 */

int ED(string target, string input, int m, int n){
    //base case
    if(m == 0){
        // we need to perform the delete operation on remaining n left words
        return n;
    }
    if(n == 0){
        // we need to insert m words
        return m;
    }
    if(target[m - 1] == input[n - 1]){
        return ED(target, input, m - 1, n - 1); // that is we won't need to perform any of the given operation
    }else{
        // if they are not same we are left with three option
        // but we don't know which operation will give us the required result so we'll perform all the three
        // in case of replace we will decrement the both index i.e m -> m - 1, n -> n - 1
        // in case of insert we only need to decrement the counter of target m -> m-1 (take example of I: CAP, T: CATP)
        // in case of delete we only need to decrement the counter of input n -> n - 1 (take example of I: CAPT, T: CAT)
        return 1 + min(min(ED(target, input, m, n - 1), ED(target, input, m - 1, n)), ED(target, input, m - 1, n - 1));
    }

}

int main(){
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    cout<<"Minimum Changes you need to do using Recursion is: "<<ED(S1, S2, S1.size(), S2.size());
    // Now let's build a dynamic solution
    // since there are two variables we need a 2D matrix
    int m, n;
    m = S1.size();
    n = S2.size();
    int DP[m + 1][n + 1];
    // first let's initialise the base case
    // base case
    for(int i = 0; i <= m; ++i){
        DP[i][0] = i;
    }
    for(int i = 0; i <= n; ++i){
        DP[0][i] = i;
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <=n; ++j){
            DP[i][j] = 100;
            if(S1[i - 1] == S2[j - 1]){
                DP[i][j] = DP[i - 1][j - 1];
            }else{
                DP[i][j] = 1 + min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]);
            }
        }
    }
    cout<<"\nMinimum Changes you need to do using DP is: "<<DP[m][n];
    return 0;
}