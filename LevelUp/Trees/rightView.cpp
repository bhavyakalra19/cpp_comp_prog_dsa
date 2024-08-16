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
    void recursion(TreeNode *head, vector<int> &v, int l){
        if(head == NULL){
            return;
        }
        if(v.size() == l){
            v.push_back(head->val);
        }
        recursion(head->right, v, l+1);
        recursion(head->left, v, l+1);        
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        recursion(root,v,0);
        return v;
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
    vector<int> v;
    v = s.rightSideView(head);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}