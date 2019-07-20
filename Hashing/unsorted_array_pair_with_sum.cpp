#include<iostream>
#include<unordered_set>
using namespace std;
// The time complexity is O(n) and space complexity is O(n)
/*
    We need to find whether a pair exists in an unsorted array such that it sum equals to a given value x;
    this can be easily implemented using brute force but there is a trick for solving it in O(n),
    we can use unordered_set for our rescue.
    i/p: {3, 5, 2, 8, 11, 7}, x: 16
    o/p: true {11, 5}
    idea is to maintain a set that checks is A[i] already exists otherwise inserts x - A[i] and checks whether the value already exists or not
    // for example
    US: {13, 11, 14, 8, 11 already exists}
 */
int main(){
    int n, x;
    cin>>n>>x;
    int A[n]; // the array that will contain our inputs
    for(int i = 0; i < n; ++i){
        cin>>A[i];
    }
    unordered_set<int> US;
    int temp;
    for(int i = 0; i < n; ++i){
        if(US.find(A[i]) != US.end()){
            // it means we've found it, it would be good if we can print those elements also
            temp = A[i];
            break;
        }else{
            US.insert(x - A[i]);
        }
    }

    cout<<"\nThe pair is: ("<<temp<<","<<(x - temp)<<",)";
}