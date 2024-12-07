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
            for(int i = 0; i < word.size(); i++){
                if(temp->mp.count(word[i]) == 0){
                    Node *n = new Node(word[i]);
                    temp->mp[word[i]] = n;
                }
                temp = temp->mp[word[i]];
            }
            temp->isTerminal = true;
        }

        bool search(string word){
            Node *temp = root;
            for(int i = 0; i < word.size(); i++){
                if(temp->mp.count(word[i]) == 0){
                    return false;
                }
                temp = temp->mp[word[i]];
            }
            if(!temp->isTerminal){
                return false;
            }
            return true;
        }
};

class Solution {
public:
    void getAns(string s, int idx, Trie t, string sum, string ans, vector<string> &v){
        if(idx == s.size()){
            if(sum == "" && ans.size() != 0){
                ans = ans.substr(0,ans.size()-1);
                v.push_back(ans);
            }
            return;
        }
        sum += s[idx];
        if(t.search(sum)){
            getAns(s,idx+1,t,"",ans + sum + " ", v);
        }
        getAns(s,idx+1,t,sum,ans,v);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        vector<string> v;
        for(auto c : wordDict){
            t.insert(c);
        }
        getAns(s,0,t,"","",v);
        return v;
    }
};

int main(){
    string str = "catsanddog";
    vector<string> dict{"cat","cats","and","sand","dog"};
    Solution s;
    vector<string> v;
    v = s.wordBreak(str,dict);
    for(auto x : v){
        cout << x << endl;
    }
    return 0;
}