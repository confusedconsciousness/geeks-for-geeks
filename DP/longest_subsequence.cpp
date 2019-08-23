#include<iostream>
#include<string>
using namespace std;

int LCS(string A, string B, int M, int N){
    //cout<<"S1: "<<A<<endl<<"S2: "<<B<<endl;
    if(M <= 0 || N <= 0){
        return 0;
    }
    if(A[M - 1] == B[N - 1]){
        return 1 + LCS(A, B, M - 1, N - 1);
    }else{
        return max(LCS(A, B, M - 1, N), LCS(A, B, M, N - 1));
    }
}

// let's convert it into a DP
int LCSDP(string A, string B, int M, int N){
    // to states
    int DP[M + 1][N + 1];
    // base case
    for(int i = 0; i <= M; ++i){
        DP[i][0] = 0;
    }
    for(int i = 0; i <= N; ++i){
        DP[0][i] = 0;
    }

    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){

            if(A[i - 1] == B[j - 1]){
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }else{
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }

        }
    }

    return DP[M][N];
}

int main(){
    int t;
    cin>>t;
    while(t){
        int n1, n2;
        cin>>n1>>n2;
        string s1;
        string s2;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        //cout<<s1<<endl<<s2;
        cout<<LCSDP(s1, s2, n1, n2)<<endl;
        --t;
    }
}