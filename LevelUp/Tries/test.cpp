#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        vector<int> term;
        Node(char c){
            data = c;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(string word, int idx){
            Node *temp = root;
            int n = word.size();
            for(int i = n - 1; i >= 0; i--){
                if(temp->mp.find(word[i]) == temp->mp.end()){
                    Node *nw = new Node(word[i]);
                    temp->mp[word[i]] = nw;
                }
                temp = temp->mp[word[i]];
            }
            temp->term.push_back(idx);
        }

        bool checkPalindrome(string s){
            int n = s.size();
            for(int i = 0; i < n/2; i++){
                if(s[i] != s[n - i - 1]){
                    return false;
                }
            }
            return true;
        }

        void searchPairs(string s, vector<vector<int>> &check, int idx){
            int n = s.size();
            Node *temp = root;
            for(int i = 0; i < n; i++){
                if(temp->term.size() != 0 && checkPalindrome(s.substr(i+1))){
                    for(auto ac : temp->term){
                        if(idx != ac){
                            check.push_back({idx,ac});
                        }
                    }
                }
                if(temp->mp.find(s[i]) == temp->mp.end()){
                    break;
                }
                temp = temp->mp[s[i]];
            }
            
        }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;
        int n = words.size();
        for(int i = 0; i < n; i++){
            t.insert(words[i],i);
        }
        vector<vector<int>> check;
        for(int i = 0; i < n; i++){
            t.searchPairs(words[i],check,i);
        }
        for(auto c : check){
            cout << c[0] << " " << c[1] << endl;
        }
        return check;
    }
};

int main(){
    vector<string> words{"a","add", "a"};
    Solution s;
    s.palindromePairs(words);
    return 0;
}