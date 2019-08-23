#include<iostream>
using namespace std;

int tile(int s){
    if(s == 0){
        return 1;
    }
    if(s < 0){
        return 0;
    }
    return tile(s - 1) + tile(s - 2);
}

int tileDP(int n){
    int dp[n + 1];
    for(int i = 0; i <= n; ++i){
        if(i == 0){
            dp[i] = 1;
        }else{
            int a, b;
            if(i - 1 < 0){
                a = 0;
            }else{
                a = dp[i - 1];
            }
            if(i - 2 < 0){
                b = 0;
            }else{
                b = dp[i - 2];
            }
            
            dp[i] = a + b;
        }
    }
    return dp[n];
}

int main(){

    cout<<tileDP(5);
    return 0;
}