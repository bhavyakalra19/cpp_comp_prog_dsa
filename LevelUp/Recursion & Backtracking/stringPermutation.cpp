#include<bits/stdc++.h>
using namespace std;

void stringPermutation(string s1, int i, vector<string> &v){
    if(s1.length()==i+1){
        v.push_back(s1);
        return;
    }
    for(int j = i; j < s1.length(); j++){
        swap(s1[i],s1[j]);
        stringPermutation(s1,i+1,v);
        swap(s1[i],s1[j]);
    }
}

int main(){
    vector<string> v;
    stringPermutation("abc",0,v);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}