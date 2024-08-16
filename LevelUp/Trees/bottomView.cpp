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

class NodePair{
    public:
        TreeNode *node;
        int pos;

        NodePair(TreeNode *n, int p){
            node = n;
            pos = p;
        }
};

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> v;
        if(root == NULL){
            return v;
        }
        map<int,int> mp;
        queue<NodePair*> q;
        NodePair *t = new NodePair(root, 0);
        q.push(t);
        while(!q.empty()){
            NodePair *t = q.front();
            q.pop();
            mp[t->pos] = t->node->val;
            if(t->node->left){
                NodePair *p = new NodePair(t->node->left, t->pos - 1);
                q.push(p);
            }
            if(t->node->right){
                NodePair *p = new NodePair(t->node->right, t->pos + 1);
                q.push(p);
            }
        }
        for(auto x : mp){
            v.push_back(x.second);
        }
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
    v = s.topView(head);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}