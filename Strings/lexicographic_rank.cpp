#include<iostream>
#include<string>
using namespace std;
/*
    In this we'll be given a string we'll be asked its lexicographic rank which means when all the permutaions of that string 
    will be sorted in increasing order what will be the position of the given string out of all its permutations
    I/P: S = "acb"
    O/P: 2
    the naive solution will be to produce the next permutations and see if it matches the current string
    well this is highly computational, it can be reduced way further

 */

int PREFIX_SUM[256];

void computePrefixSum(int* COUNT){
    // initialise the PREFIX_SUM
    PREFIX_SUM[0] = COUNT[0];
    for(int i = 1; i < 256; ++i){
        PREFIX_SUM[i] = PREFIX_SUM[i - 1] + COUNT[i];
    }
}

int computeFactorial(int n){
    int a = 1;
    for(int i = n; i > 0; --i){
        a = a * i;
    }
    return a;
}

void show(int* COUNT, int* PREFIX_SUM){
    cout<<"\n---------------------\n";
    for(int i = 0; i < 256; ++i){
        cout<<COUNT[i]<<" ";
    }
    cout<<"\n";

    for(int i = 0; i < 256; ++i){
        cout<<PREFIX_SUM[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    string S;
    getline(cin, S);
    int COUNT[256];
    // initialise the COUNT to 0
    for(int i = 0; i < 256; ++i){
        COUNT[i] = 0;
    }
    for(int i = 0; i < S.size(); ++i){
        COUNT[S[i] - 'a']++;
    }
    // PREFIX_SUM will basically help us in knowing how many characters are smaller than the current character that's it
    // assuming we'll only be using lower case characters for the time being
    int rank = 0;
    for(int i = 0; i < S.size(); ++i){
        computePrefixSum(COUNT);
        //show(COUNT, PREFIX_SUM);
        if(PREFIX_SUM[S[i] - 'a'] - 1 == 0){
            // no permutation possible
            COUNT[S[i] - 'a'] = 0;
            continue;
        }
        rank += computeFactorial(PREFIX_SUM[S[i] - 'a'] - 1) * (S.size() - i - 1);
        // now fixing the ith position we need to delete the S[i]
        COUNT[S[i] - 'a'] = 0;
    }
    cout<<"Rank is: "<<rank + 1;

}