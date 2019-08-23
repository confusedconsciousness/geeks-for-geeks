#include<iostream>
#include<vector>
using namespace std;

int count(vector<int>A, int i, vector<int> curr, int k){
    // start from the beginning
    if(i > A.size() - 1){
        return 0;
    }
    if(curr.size() == k){
        return 1;
    }
    if(curr.size() > k){
        return 0;
    }
    vector<int> t1 = curr;
    vector<int> t2 = curr;
    t1.push_back(A[i]);
    return count(A, i, t1, k) + count(A, i + 1, t2, k);

}

int count2(vector<int> A, int n, vector<int> curr, int k){
    // here we'll start from the end
    if(n <= 0){
        return 0;
    }
    if(curr.size() == k){
        return 1;
    }
    if(curr.size() > k){
        return 0;
    }
    vector<int> t1 = curr;
    vector<int> t2 = curr;
    t1.push_back(A[n - 1]);
    return count2(A, n, t1, k) + count2(A, n - 1, t2, k);
}

int nonDecNums(int n) 
{ 
    /* a[i][j] = count of all possible number 
       with i digits having leading digit as j */
    int a[n + 1][10]; 
  
    // Initialization of all 0-digit number 
    for (int i = 0; i <= 9; i++) 
        a[0][i] = 1; 
  
    /* Initialization of all i-digit 
      non-decreasing number leading with 9*/
    for (int i = 1; i <= n; i++) 
        a[i][9] = 1; 
  
    /* for all digits we should calculate 
      number of ways depending upon leading 
      digits*/
    for (int i = 1; i <= n; i++) 
        for (int j = 8; j >= 0; j--) 
            a[i][j] = a[i - 1][j] + a[i][j + 1]; 
  
    return a[n][0]; 
} 


int main(){
    int t;
    cin>>t;
    while(t){
        int n, k;
        vector<int> A;
        for(int i = 0; i < 10; ++i){
            A.push_back(i);
        }
        cin>>k;
        // vector<int> curr;
        // curr.clear();
        // cout<<count(A, 0, curr, k)<<endl;
        // cout<<count2(A, A.size(), curr, k)<<endl;
        cout<<nonDecNums(k)<<endl;
        --t;
    }
}