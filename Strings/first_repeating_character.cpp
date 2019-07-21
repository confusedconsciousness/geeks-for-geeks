#include<iostream>
#include<string>
using namespace std;
/*
    I/P: S="abcbc"
    O/P: 'b'
    I/P: S="abcbca"
    O/P: 'a'
    here we need to output the string which repeated and whose index is minimum in some sense
    because in the above examples though b appears two times but its first occuring index is not the minimum
 */
int main(){
    string S;
    getline(cin, S);
    pair<int,int> P[256]; // because we need two things to take into account the first is the count and the second is the index
    // first let's initialise the pair count = 0 and index = -1
    for(int i = 0; i < 256; ++i){
        P[i].first = 0; // count
        P[i].second = -1; // index
    }
    for(int i = 0; i < S.size(); ++i){
        P[S[i]].first++;
        if(P[S[i]].second == -1){
            P[S[i]].second = i;
        }
    }

    // now our task is to find the pair whose P[i].first > 1 and P[i].second is minimum
    char res;
    int temp = 1000;
    for(int i = 0; i < S.size(); ++i){
        if(P[S[i]].first > 1){
            if(P[S[i]].second < temp){
                temp = P[S[i]].second;
                res = S[i];
            }
        }
    }

    cout<<"Result: "<<res;

}