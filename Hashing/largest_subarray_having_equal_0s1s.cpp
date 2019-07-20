#include<iostream>
#include<vector>
using namespace std;
// The time complexity is O(n) and space complexity is O(n)
/*
    This problem is trivial when we compare with the other solution that we have developed so far,
    it is again related to the subarray with zero sum, the only thing that we need to do is convert 0s to -1s
    and then look for the longest subarray with 0 sum.
    i/p: {0, 1, 0, 1, 1, 0}
    o/p: 4 {0, 1, 1, 0}
    i/p: {1, 1, 1}
    o/p: 0

 */
int main(){
    int n;
    cin>>n;
    int A[n]; // the array that will contain our inputs
    int var;
    for(int i = 0; i < n; ++i){
        cin>>var;
        // converting 0s -> 1s on the fly
        if(var == 0){
            A[i] = -1;
        }else{
            A[i] = 1;
        }
    }
    int prefix_sum = 0;
    vector<int> prefixes;
    prefixes.push_back(0);
    for(int i = 0; i < n; ++i){
        prefix_sum += A[i];
        prefixes.push_back(prefix_sum);
    }
    // we need to find the maximum interval
    int pos_i, pos_j;
    for(int i = 0; i < prefixes.size(); ++i){
        if(prefixes[i] == 0){
            pos_i = i;
            break;
        }
    }
    for(int i = prefixes.size() - 1; i > -1; --i){
        if(prefixes[i] == 0){
            pos_j = i;
            break;
        }
    }

    cout<<"Largest Subarray lengths is: "<<(pos_j - pos_i);

}