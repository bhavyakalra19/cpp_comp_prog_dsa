#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        bool isTerminal;

        Node(char data){
            this->data = data;
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
                    Node *a = new Node(word[i]);
                    temp->mp[word[i]] = a;
                }
                temp = temp->mp[word[i]];
            }
            temp->isTerminal = true;
        }
};

class Practice{
    public:
        void searchHelper(Trie t, string document, int idx, unordered_map<string,bool> &mp){
            Node *temp = t.root;
            for(int i = idx; i < document.size(); i++){
                if(temp->mp.count(document[i]) == 0){
                    return;
                }
                temp = temp->mp[document[i]];
                if(temp->isTerminal){
                    mp[document.substr(idx,i-idx+1)] = true;
                }
            }
            return;
        }

        void getAns(string document, vector<string> words){
            Trie t;
            unordered_map<string,bool> mp;
            for(auto c : words){
                t.insert(c);
                mp[c] = false;
            }

            for(int i = 0; i < document.size(); i++){
                searchHelper(t,document,i,mp);
            }

            for(auto m : mp){
                cout << m.first << " " << m.second << endl;
            }
        }
};

int main(){
    string s = "hello my name is bhavya";
    vector<string> words{"hello","bhavya","my","name","prac"};
    Practice p;
    p.getAns(s,words);
    return 0;
}