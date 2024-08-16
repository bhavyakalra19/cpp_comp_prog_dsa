#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        bool isTerminal;

        Node(char c){
            data = c;
            isTerminal = false;
        }
};


class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(string word){
            Node *temp = root;
            for(auto c : word){
                if(temp->mp.count(c) == 0){
                    Node *a = new Node(c);
                    temp->mp[c] = a;
                }
                temp = temp->mp[c];
            }
            temp->isTerminal = true;
        }

        bool search(string word){
            Node *temp = root;
            for(auto c : word){
                if(temp->mp.count(c) == 0){
                    return false;
                }
                temp = temp->mp[c];
            }
            return temp->isTerminal;
        }
};

class Solution {
public:
    bool checkAns(string s, Trie t, unordered_map<string,bool> &dp){
        if(dp.count(s) != 0){
            return dp[s];
        }
        if(t.search(s) == true){
            return true;
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            ans += s[i];
            if(t.search(ans) && checkAns(s.substr(i+1),t,dp)){
                return dp[s] = true;
            }
        }
        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(auto c : wordDict){
            t.insert(c);
        }
        unordered_map<string,bool> dp;
        return checkAns(s,t,dp);
    }
};

int main(){
    string s = "leetcode";
    vector<string> dict{"leet","code"};
    Solution sl;
    if(sl.wordBreak(s,dict)){
        cout << "Done" << endl;
    }
    return 0;
}