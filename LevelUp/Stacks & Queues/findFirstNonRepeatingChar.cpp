#include<bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    queue<char> q;
    unordered_map<char,int> mp;
    vector<char> ans;
    for(int i = 0; i < S.length(); i++){
        q.push(S[i]);
        mp[S[i]]++;

        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }
        }
        if(q.empty()){
            ans.push_back('0');
        }else{
            ans.push_back(q.front());
            break;
        }
    }
    return ans;
}

int main(){
    string s = "aabcbcd";
    vector<char> v;
    v = FindFirstNonRepeatingCharacter(s);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}