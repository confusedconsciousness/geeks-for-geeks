#include<iostream>
using namespace std;

bool subset(int *A, int n, int m){
    if(m == 0){
        return true;
    }
    if(n == 0 && m != 0){
        return false;
    }
    // if last element is greater than the sum ignore it
    if(A[n - 1] > m){
        return subset(A, n - 1, m);
    }
    bool res = subset(A, n - 1, m) || subset(A, n - 1, m - A[n - 1]);
    return res;
}

bool subsetDP(int *A, int n, int m){
    // 2 state variables will be needed
    int dp[m + 1][n + 1]; // why m + 1, because when m will be zero we need to set it to 1
    // bottom up
    for(int i = 0; i <= n; ++i){
        dp[0][i] = 1;
    }
    for(int i = 0; i <= m; ++i){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            // i is m and j is n
            if(A[j - 1] > m){
                dp[i][j] = dp[i][j - 1];
            }
            bool r1, r2;
            if(j - 1 > -1){
                r1 = dp[i][j - 1];
            }
            if((i - A[j - 1]) > -1 && j - 1 > -1){
                r2 = dp[i - A[j - 1]][j - 1];
            }
            dp[i][j] = r1 || r2;
        }
    }
    return dp[m][n - 1];
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
        int s;
        cin>>s;
        cout<<subsetDP(A, n, s)<<endl;
        --t;
    }
}