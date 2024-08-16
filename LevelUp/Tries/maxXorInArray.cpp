#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *left;
        Node *right;
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node *temp = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(bit == 0){
                    if(temp->left == NULL){
                        temp->left = new Node();
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == NULL){
                        temp->right = new Node();
                    }
                    temp = temp->right;
                }
            }
        }

        int max_xor_helper(int value){
            int current_ans = 0;
            Node *temp = root;

            for(int j = 31; j >= 0; j--){
                int bit = (value >> j) & 1;
                if(bit == 0){
                    if(temp->right){
                        temp = temp->right;
                        current_ans += 1<<j;
                    }else{
                        temp = temp->left;
                    }
                }else{
                    if(temp->left){
                        temp = temp->left;
                        current_ans += 1<<j;
                    }else{
                        temp = temp->right;
                    }
                }
            }
            return current_ans;
        }

        int max_xor(vector<int> nums){
            int cs = 0;

            for(auto x : nums){
                insert(x);
            }

            for(auto x : nums){
                cs = max(cs,max_xor_helper(x));
            }
            return cs;
        }
};

int main(){
    vector<int> v{3,5,10,25,2};
    Trie t;
    cout << t.max_xor(v) << endl;
    return 0;
}

