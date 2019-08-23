#include<iostream>
#include<vector>
using namespace std;
int A[100][100];
int profit(int i, int j, int n, int m){
    if(j == m - 1){
        return A[i][j];
    }
    if(j > m - 1 || i > n - 1 || i < 0){
        // if the index is out of bound we return 0
        return 0;
    }

    return max(max(A[i][j] + profit(i - 1, j + 1, n, m), A[i][j] + profit(i, j + 1, n, m)), A[i][j] + profit(i + 1, j + 1, n, m));
}

int profitDP(int n, int m){
    int dp[n][m];
    // initialise the dp
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dp[i][j] = 0;
        }
    }
    // what is the base case here
    for(int i = 0; i < n; ++i){
        dp[i][0] = A[i][0];
    }
    // how to fill in the bottom up approach
    for(int j = 1; j < m; ++j){
        for(int i = 0; i < n; ++i){
            int a, b, c;
            a = 0;
            b = 0;
            c = 0;
            if(i - 1 > -1 && j - 1 > -1){
                a = A[i][j] + dp[i - 1][j - 1];
            }
            if(i > -1 && j - 1 > -1){
                 b = A[i][j] + dp[i][j - 1];
            }
            if(i + 1 < n && j - 1 > -1){
                c = A[i][j] + dp[i + 1][j - 1];
            }
            dp[i][j] = max(max(a, b), c);
            
        }
    }
    // find the maximum element in the last column
    int temp = INT_MIN;
    for(int i = 0; i < n; ++i){
        if(dp[i][m - 1] > temp){
            temp = dp[i][m - 1];
        }
    }
    return temp;

}
int main(){
    int n, m;
    int t;
    cin>>t;
    while(t){
        cin>>n>>m;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>A[i][j];
            }
        }
        cout<<profitDP(n, m);
        --t;
    }
    
    // vector<int> max_profit;
    
    // for(int i = 0; i < n; ++i){
    //     max_profit.push_back(profit(i, 0, n, m));
    // }
    // int temp = max_profit[0];

    // for(int i = 1; i < max_profit.size(); ++i){
    //     if(max_profit[i] > temp){
    //         temp = max_profit[i];
    //     }
    // }
    // cout<<endl<<temp;
    
    
}