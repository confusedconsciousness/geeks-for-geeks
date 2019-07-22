#include<iostream>
#include<string>
using namespace std;
/*
    in this problem we'll be given two strings we need to check whether the two strings are rotation of each other
    I/P: S1="abcd", S2="cdab"
    O/P: true
    my approach is to first find the beginning of the S1 in S2 and after finding the head compare the rest, if you reach end first 
    in the S2 start from the first then
    The above algorithm should take O(n) time
    the drawback of the above algorithm is that it needs every element in the string to be different
    for e.g.:
    I/P: S1 = "abca", S2 = "bcaa"
    O/P: don't work
    other solution is to concatenate the S1 with itself
    I/P: S1="abcd", S2="cdab", S1'="abcdabcd", now the S2 will be present as a substring in the S1
    O/P: true
    it is robust to the redundant characters in the string
 */
bool is_rotated(string S1, string S2){
    // this solution only works when we have every element in the string distinct
    int pos = -1;
    for(int i = 0; i < S2.size(); ++i){
        if(S1[0] == S2[i]){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        return false;
    }
    for(int i = 0; i < S1.size(); ++i){
        if(S1[i] != S2[(pos + i) % S1.size()]){
            return false;
        }

    }
    return true;
}

bool is_rotated_2(string S1, string S2){
    // we can directly use the libraries to check whether S2 is present in it
    S1.append(S1);
    size_t index = S1.find(S2);
    if(index != string::npos){
        return true;
    }
    return false;
}

int main(){
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    cout<<is_rotated(S1, S2);
    cout<<"\n";
    cout<<is_rotated_2(S1, S2);
    return 0;
}