#include<bits/stdc++.h>
using namespace std;

void stringPermutation(vector<int> s1, int i, vector<vector<int>> &v){
    if(s1.size()==i+1){
        v.push_back(s1);
        return;
    }
    for(int j = i; j < s1.size(); j++){
        swap(s1[i],s1[j]);
        stringPermutation(s1,i+1,v);
        swap(s1[i],s1[j]);
    }
}

int main(){
    vector<vector<int>> v;
    stringPermutation({1,2,3},0,v);
    for(auto x : v){
        for(auto s : x){
            cout << s << "";
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}