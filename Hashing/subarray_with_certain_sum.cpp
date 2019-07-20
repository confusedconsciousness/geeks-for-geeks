#include<iostream>
#include<unordered_set>
/*
    This is another variant of the problem defined in subarray with zero sum
    Here we need to find a subarray that will sum upto a certain specified given value
    i/p: {5, 3, 8, -2, 8, 10}, x: 11
    o/p: true, {3, 8}
    here we'll again maintain a prefix_sum and an unordered_set, but the catch is before inserting the prefix sum to US
    we'll check if prefix_sum - x already exists or not
    prefix_sum : {5, 8, 16, 14, 22, 32}
    // now the catch is if we subtract 11
    {5, 8, 5, 3, 11, 21} // so again it reduces to the previous problem only
 */

using namespace std;
int main(){
    int n, x;
    cin>>n>>x;
    int A[n]; // the array that will contain our inputs
    for(int i = 0; i < n; ++i){
        cin>>A[i];
    }
    unordered_set<int> US; // this will tell us whether we've encountered the same element or not in O(1) time complexity
    US.insert(0);
    int prefix_sum = 0;
    int pos_i, pos_j, temp;
    // pos_i and pos_j will carry the starting and ending index of the subarray with zero sum

    for(int i = 0; i < n; ++i){
        prefix_sum += A[i];
        if(US.find(prefix_sum - x) != US.end()){
            // it means the prefix sum exists
            pos_j = i;
            temp = prefix_sum - x;
            break;
        }else{
            // we don't need to insert the prefix_sum - x, it is just for checking only
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
    
    // when we get 0, pos_i = 0
    if(temp == 0){
        // to handle the base case
        pos_i = 0;
    }

    // now display the subarray
    cout<<"\n{";
    for(int i = pos_i; i <= pos_j; ++i){
        cout<<A[i]<<",";
    }
    cout<<"}";
}