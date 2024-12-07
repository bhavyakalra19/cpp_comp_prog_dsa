#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;
    
bool checkPal(string str){
    if(mp.find(str) != mp.end()){
        return mp[str];
    }
    int n = str.size();
    for(int i = 0; i < n/2; i++){
        if(str[i] != str[n-i-1]){
            return mp[str] = false;
        }
    }
    return mp[str] = true;
}

int minChar(string& s) {
    // Write your code here
    int n = s.size();
    int ans = n-1;
    string lft = "";
    for(int i = 0; i < n; i++){
        lft += s[0];
        s = s.substr(1);
        if(checkPal(lft)){
            ans = min(ans,n - i + 1);
        }
        if(checkPal(s)){
            ans = min(ans,i+1);
        }
    }
    return ans;
}

int main(){
    string a = "abc";
    cout << minChar(a) << endl;
    return 0;
}