#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data){
            val = data;
            left = right = NULL;
        }
};

class Solution {
public:
    void recursion(TreeNode *root, map<int, vector<int>> &mp, int pos){
        if(root == NULL){
            return;
        }
        mp[pos].push_back(root->val);
        recursion(root->left, mp, pos - 1);
        recursion(root->right, mp, pos);
    }

    void diagnalTraversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        map<int,vector<int>> mp;
        recursion(root,mp,0);
        for(auto m : mp){
            for(auto x : m.second){
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Solution s;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    head->left->right->right = new TreeNode(8);
    s.diagnalTraversal(head);
    return 0;
}