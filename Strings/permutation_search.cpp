#include<iostream>
#include<string>
using namespace std;
/*
    In this problem we'll be given a input text, we are required to search for the given string pattern and its permutation
    in the input text.
    I/P: text: "geeksforgeeks", pattern: "ofr"
    O/P: true (for and ofr are each other permutations)
    one solution is to maintain two COUNTs and see whether the pattern count is less than or equal to texts count for the corresponding
    pattern texts
 */

void re_initialise(int* A){
    for(int i = 0; i < 256; ++i){
        A[i] = 0;
    }
}
bool mySolution(string input, string pattern){
    // This solution has time complexity O(m + n) and space complexity of O(1), we are only using constant space 256
    int COUNT1[256], COUNT2[256];
    // initialised the counts
    re_initialise(COUNT1);
    re_initialise(COUNT2);
    for(int i = 0; i < input.size(); ++i){
        COUNT1[input[i]]++;
    }
    for(int i = 0; i < pattern.size(); ++i){
        COUNT2[pattern[i]]++;
    }
    // COUNT2[pattern[i]] <= COUNT1[pattern[i]] for true otherwise false
    for(int i = 0; i < pattern.size(); ++i){
        if(COUNT2[pattern[i]] > COUNT1[pattern[i]]){
            return false;
        }
    }
    return true;
}


bool compare_slides(int *A, int *B){
    for(int i = 0; i < 256; ++i){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}
bool slidingWindow(string input, string pattern){
    // we are assuming that the pattern size is always less than the input string
    int COUNT1[256], COUNT2[256];
    // we'll make COUNT2 fixed and change the COUNT1 accordingly
    // initialise both the arrays
    re_initialise(COUNT1);
    re_initialise(COUNT2);

    for(int i = 0; i < pattern.size(); ++i){
        COUNT2[pattern[i]]++;
    }
    // now we'll implement the sliding window approach
    for(int i = 0; i < input.size() - pattern.size() + 1; ++i){

        for(int j = i; j < i + pattern.size(); ++j){
            COUNT1[input[j]]++;
        }
        // now compare
        if(compare_slides(COUNT1, COUNT2)){
            return true;
        }else{
            // move to the next slide
            re_initialise(COUNT1);
        }

    }
    return false;
}

int main(){
    string input, pattern;
    getline(cin, input);
    getline(cin, pattern);
    cout<<"My solution: "<<mySolution(input, pattern);
    cout<<"\n";
    cout<<"Sliding Window solution: "<<slidingWindow(input, pattern);
    cout<<"\n";

    return 0;
}