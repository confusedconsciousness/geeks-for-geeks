#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int LRS(string A, string B, int M, int N, string &curr){
    if(M <= 0 || N <= 0){
        return 0;
    }
    if(A[M - 1] == B[N - 1] && (M - 1) != (N - 1)){
        //cout<<A[M - 1]<<endl;
        curr.push_back(A[M - 1]);
        return 1 + LRS(A, B, M - 1, N - 1, curr);
    }else{
        return max(LRS(A, B, M - 1, N, curr), LRS(A, B, M, N - 1, curr));
    }
}

int LRSDP(string A, string B, int M, int N){
    int DP[M + 1][N + 1];
    // initialise it to zero
    for(int i = 0; i <= M; ++i){
        for(int j = 0; j <= N; ++j){
            DP[i][j] = 0;
        }
    }
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){
            if(A[i - 1] == B[j - 1] && i != j){
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }else{
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
    }

    // we'll traverse the DP from bottom right
    string res = "";
    int i = M, j = N;
    while(i > 0 && j > 0){
        if(DP[i][j] == DP[i - 1][j - 1] + 1){
            res += A[i - 1];
            --i;
            --j;
        }else if(DP[i][j] == DP[i - 1][j]){
            --i;
        }else{
            --j;
        }

    }
    reverse(res.begin(), res.end());
    cout<<res;
    return DP[M][N];
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        string s;
        cin.ignore();
        getline(cin, s);
        string curr;
        //int temp = LRS(s, s, n, n, curr);
        //cout<<temp<<endl;
        //cout<<LRSDP(s, s, n, n)<<endl;
        int temp = LRSDP(s, s, n, n);
        cout<<endl;
        // we got the length, now we need to print the
        --t;
        
    }
}