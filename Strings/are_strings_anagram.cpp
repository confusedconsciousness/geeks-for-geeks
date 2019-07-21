#include<iostream>
#include<string>
using namespace std;
/*
    In this program we'll be given two strings S1 and S2, we need to find whether the two strings are anagram to each other
    What do we mean by anagram?
    anagram is the possible word that can be formed by jumbling the words present in the original string
    or we can say it is one of its many permutations
    I/P: S1 = "gfg", S2 = "ggf"
    O/P: true
    I/p: S1 = "gfg", S2 = "ffg"
    O/P: false
    the naive solution is to first look for the length of the two strings if they are not the same then we can straightforwar reject it
    the next step is to iterate over the S1 and then find how many times it had occured in the S1 and
    then look how many times it has appears in the second String, if the frequency matches they are anagram of each other
    but this solution takes O(n^2) can we do it in O(n)?
    yes, we need take into account the fact that the there can only be 256 different characters
 */

int isAnagram(string S1, string S2){
    int flag = 0;
    if(S1.size() != S2.size()){
        return 1;
    }
    char COUNT[256]; // basically there are 256 at most different characters
    // initialise the COUNT to 0
    for(int i = 0; i < 256; ++i){
        COUNT[i] = 0;
    }
    for(int i = 0; i < S1.size(); ++i){
        // it will take care of the frequency
        COUNT[S1[i]]++;
    }
    for(int i = 0; i < S2.size(); ++i){
        // if both the frequency matches then the COUNT will be all zero because it will be nullified
        COUNT[S2[i]]--;
    }
    
    for(int i = 0; i < 256; ++i){
        if(COUNT[i] != 0){
            flag = 1;
            break;
        }
    }   
    return flag;
}

int main(){
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    int temp = isAnagram(S1, S2);
    if(temp == 1){
        cout<<"\nThe strings are not ANAGRAM\n";
    }else{
        cout<<"\nThe strings are ANAGRAM\n";
    }

}