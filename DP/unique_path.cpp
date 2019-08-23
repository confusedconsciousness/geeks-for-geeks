#include<iostream>
#include<vector>
using namespace std;

int unique(vector<vector<int> > A, int m, int n){
    // we are standing at (0, 0) we need to go to m, n
    // i think we should consider going from the m, n to 0, 0 so that we can build up a dynamic solution
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }
    // now check whether there is path in top
    if((m - 1 > -1) && (A[m - 1][n] == 0) && (n - 1 > -1) && (A[m][n - 1] == 0)){
        // we can move in both the directions
        return unique(A, m - 1, n) + unique(A, m, n - 1);
    }else if((m - 1 > -1) && (A[m - 1][n] == 0)){
        // only top path is possible
        return unique(A, m - 1, n);
    }else if((n - 1 > -1) && (A[m][n - 1] == 0)){
        return unique(A, m, n - 1);
    }else{
        // no path backtrack
        return 0;
    }
}

int uniqueDP(vector<vector<int> >A, int m, int n){
    int DP[m + 1][n + 1];
    memset(DP, 0, sizeof(DP));
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            if(i == 0 && j == 0){
                DP[i][j] = 1;
            }
            else if(i - 1 > -1 && A[i - 1][j] == 0 && j - 1 > -1 && A[i][j - 1] == 0){
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }else if(i - 1 > -1 && A[i - 1][j] == 0){
                DP[i][j] = DP[i - 1][j];
            }else if(j - 1 > -1 && A[i][j - 1] == 0){
                DP[i][j] = DP[i][j - 1];
            }else{
                DP[i][j] = 0;
            }
        }
    }
    // for(int i = 0; i <= m; ++i){
    //     for(int j = 0; j <= n; ++j){
    //         cout<<DP[i][j];
    //     }
    //     cout<<endl;
    // }

    return DP[m][n];

}

int main(){
    int t;
    cin>>t;
    while(t){
        int m, n;
        cin>>m>>n;
        vector<vector<int> >A;
        for(int i = 0; i < m; ++i){
            vector<int> temp;
            for(int j = 0; j < n; ++j){
                int a;
                cin>>a;
                temp.push_back(a);
            }
            A.push_back(temp);
        }
        cout<<uniqueDP(A, m - 1, n - 1)<<endl;
        --t;
    }
}