#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,bool> dp;

    bool isPal(string s){
        auto idx = dp.find(s);
        if(idx != dp.end()){
            return dp[s];
        }
        int n = s.size();
        for(int i = 0; i < n / 2; i++){
            if(s[i] != s[n - 1 - i]){
                dp[s] = false;
                return false;
            }
        }
        dp[s] = true;
        return true;
    }

    void getAns(string s, vector<string> op, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(op);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(isPal(s.substr(0,i+1))){
                op.push_back(s.substr(0,i+1));
                getAns(s.substr(i+1), op, ans);
                op.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> op;
        getAns(s,op,ans);
        return ans;
    }
};

int main(){
    vector<vector<string>> ans;
    Solution s;
    ans = s.partition("aab");
    for(auto list : ans){
        for(auto s : list){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}