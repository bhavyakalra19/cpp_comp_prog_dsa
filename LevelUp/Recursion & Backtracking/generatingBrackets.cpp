#include<bits/stdc++.h>
using namespace std;

void generateBrackets(int n, int open, int close, string output, int i, vector<string> &v){
    if(i == 2*n){
        v.push_back(output);
        return;
    }
    if(open < n){
        generateBrackets(n,open+1,close,output + "(",i+1, v);
    }
    if(close < open){
        generateBrackets(n,open,close+1,output + ")",i+1, v);
    }
}

int main(){
    vector<string> v;
    generateBrackets(10,0,0,"",0,v);
    for(auto x : v){
        cout << x << endl;
    }
    return 0;
}