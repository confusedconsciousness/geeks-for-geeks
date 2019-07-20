#include<iostream>
#include<unordered_set>
using namespace std;
// The overall Time complexity of this algorithm is O(n) and Space complexity: O(n)
/* 
    I/p: {5, 6, -4, -2, 8, 10}
    O/p: {6, -4, -2}
    how will we proceed with the problem, the idea is to use unordered_set and run a prefix sum over the array
    prefix_sum: {5, 11, 7, 5, 13, 23}, as you might have guessed, we've encountered 5 two times it is only possible when the elements in between sum to zero
    5 + (anything) = 5, then anything has to be zero
    but the above intution fails when we have i/p something like this: {5, -5, 3, 4}
    prefix_sum: {5, 0, 3, 7},  did you got any repeating unit, no!
    the simple intuition will be to push a 0 in the prefix sum no matter what
    prefix_sum: {0} // base case, now our sum: {0, 5, 0, 3, 7}
*/
int main(){
    int n;
    cin>>n;
    int A[n]; // the array that will contain our inputs
    for(int i = 0; i < n; ++i){
        cin>>A[i];
    }
    unordered_set<int> US; // this will tell us whether we've encountered the same element or not in O(1) time complexity
    US.insert(0); // base case
    int prefix_sum = 0;
    int pos_i, pos_j, temp;
    // pos_i and pos_j will carry the starting and ending index of the subarray with zero sum

    for(int i = 0; i < n; ++i){
        prefix_sum += A[i];
        if(US.find(prefix_sum) != US.end()){
            // it means the prefix sum exists
            pos_j = i;
            temp = prefix_sum;
            break;
        }else{
            US.insert(prefix_sum);
        }
    }
    //search for the element equal to temp in the original array
    for(int i = 0; i < n; ++i){
        if(A[i] == temp){
            pos_i = i + 1;
            break;
        }
    }

    // now display the subarray
    // when we get 0, pos_i = 0
    if(temp == 0){
        // to handle the base case
        pos_i = 0;
    }
    cout<<"\n{";
    for(int i = pos_i; i <= pos_j; ++i){
        cout<<A[i]<<",";
    }
    cout<<"}";
    
    return 0;
}