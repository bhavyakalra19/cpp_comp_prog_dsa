#include<bits/stdc++.h>
using namespace std;

int recursion(string s, int idx, set<string> mp){
    if(s[idx] == '\0'){
        return 0;
    }
    string curr;
    int ans = INT_MAX;
    for(int i = idx; s[i] != '\0'; i++){
        curr += s[i];
        if(mp.find(curr) != mp.end()){
            int rem = recursion(s,i+1,mp);
            if(rem != -1){
                ans = min(ans,1 + rem);
            }
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int quickBrown(string s, set<string> mp){
    return recursion(s,0,mp) - 1;
}

int main(){
    set<string> mp;
    mp.insert("the");
    mp.insert("quick");
    mp.insert("brown");
    mp.insert("quickbrown");
    mp.insert("fox");
    cout << quickBrown("thequickbrownfox",mp) << endl;
    return 0;
}