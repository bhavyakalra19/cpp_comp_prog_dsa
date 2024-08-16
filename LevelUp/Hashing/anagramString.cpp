#include<bits/stdc++.h>
using namespace std;

vector<int> getHashValue(string s, int i, int j){
    vector<int> v{26,0};
    for(int k = i; k <= j; k++){
        char ch = s[k];
        v[ch - 'a']++;
    }
    return v;
}

int anagramString(string s){
    map<vector<int>, int> mp;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        for(int j = i; j < s.length(); j++){
            vector<int> h = getHashValue(s,i,j);
            mp[h]++;
        }
    }
    for(auto m : mp){
        if(m.second >= 2){
            ans += (m.second * (m.second - 1))/ 2;
        }
    }
    return ans;
}

int main(){
    cout << anagramString("aba") << endl;
    return 0;
}