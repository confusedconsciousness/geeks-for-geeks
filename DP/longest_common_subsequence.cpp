#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
// The time complexity using DP is O(n^2), whereas using recursion it is O(exp)
/*
    given two strings S1 and S2, we need to find the longest common subsequence present in it
    I/P: S1="AABBAPCD", S2="ABTEJAPD"
    O/P: 5, "ABAPD"
    the longest subsequence need not to be consequetive but it should be in succession
    We can use either recursion or Dynamic programming for this task
    It is always better to formulate a recursion algorithm because then converting it into a DP problem is easy and straightforward
    We will first write a pseudo code for recursion and then convert it into a DP
 */

int LCS(string S1, string S2, int m, int n){
    // m and n are the length of the strings
    if(m == 0 || n == 0){
        return 0;
    }else if(S1[m - 1] == S2[n - 1]){
        return 1 + LCS(S1, S2, m - 1, n - 1);
    }else{
        // there can be two cases involved
        // either we fix the S1 and look at the previous index of S2 or vice versa
        return max(LCS(S1, S2, m - 1, n), LCS(S1, S2, m, n - 1));
    }
}


int main(){
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    // unfortunately the recursion method is computationally expensive
    // its time complexity is O(exponential), we can do way better than that using DP
    cout<<"Longest Common Subsequence Length using Recursion is: "<<LCS(S1, S2, S1.size(), S2.size());
    // Using Dynamic Programming approach
    // as you can see here two things are varying "m" and "n", thus we need to have a 2D array for look up (bottom down approach)
    int DP[S1.size() + 1][S2.size() + 1];
    for(int i = 0; i <= S1.size(); ++i){
        for(int j = 0; j <= S2.size(); ++j){
            if(i == 0 || j == 0){
                DP[i][j] = 0;
            }else{
                if(S1[i - 1] == S2[j - 1]){
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                }else{
                    DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
                }
            }
            
        }
    }
    cout<<"\nLongest Common Subsequence Length using DP is : "<<DP[S1.size()][S2.size()];
    cout<<"\n";
    return 0;
}