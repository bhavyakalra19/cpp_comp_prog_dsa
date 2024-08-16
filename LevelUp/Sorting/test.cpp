#include<bits/stdc++.h>
using namespace std;

bool lexicographical(string s1, string s2){
    return s1 + s2 < s2 + s1;
}

string smallestString(vector<string> v){
    string s = "";
    sort(v.begin(),v.end(),lexicographical);
    for(string x : v){
        s += x;
    }
    return s;
}

int main(){
    vector<string> v{"a","ab","aba"};
    cout << smallestString(v) << endl;
    return 0;
}