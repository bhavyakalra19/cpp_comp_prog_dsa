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

int main(){
    Trie t;
    t.insert("hello");
    if(t.search("hello")){
        cout << "Found" << endl;
    }
    if(t.search("wxyz")){
        cout << "Found too" << endl; 
    }
    return 0;
}
