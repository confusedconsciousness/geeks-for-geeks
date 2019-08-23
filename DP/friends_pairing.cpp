#include<iostream>
using namespace std;

int friends(int n){
    // if only one person is left
    // if(n == 1){
    //     return 1;
    // }
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    return friends(n - 1) + (n - 1) * friends(n - 2);
}

int friendDP(int n){
    int dp[n + 1];
    // for base case 
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        int a = 0, b = 0;
        if(i - 1 > -1){
            a = dp[i - 1];
        }
        if(i - 2 > -1){
            b = dp[i - 2];
        }
        dp[i] = a + (i - 1) * b;
    }
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        cout<<friendDP(n)<<endl;
        t--;
    }
}