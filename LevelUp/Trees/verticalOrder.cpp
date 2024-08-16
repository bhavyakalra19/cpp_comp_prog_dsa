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

class dataNode{
    public:
        TreeNode* node;
        int level;
        int pos;

        dataNode(TreeNode *n, int l, int p){
            node = n;
            level = l;
            pos = p;
        }
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<dataNode*> q;
        vector<vector<int>> v;
        map<int,map<int,multiset<int>>> mp;
        if(root == NULL){
            return v;
        }

        dataNode *t = new dataNode(root,0,0);
        q.push(t);
        while(!q.empty()){
            dataNode *t = q.front();
            q.pop();
            mp[t->pos][t->level].insert(t->node->val);
            if(t->node->left){
                dataNode *p = new dataNode(t->node->left,t->level+1,t->pos-1);
                q.push(p);
            }
            if(t->node->right){
                dataNode *p = new dataNode(t->node->right,t->level+1,t->pos+1);
                q.push(p);
            }
        }
        for(auto m : mp){
            vector<int> temp;
            for(auto x : m.second){
                for(auto y : x.second){
                    temp.push_back(y);
                }
            }
            v.push_back(temp);
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
    s.verticalTraversal(head);
    return 0;
}
