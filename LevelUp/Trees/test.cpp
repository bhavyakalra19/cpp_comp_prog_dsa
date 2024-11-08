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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            unordered_map<TreeNode*,int> mp;
            int totalSum = 0;
            qt.push(NULL);
            while(qt.front() != NULL){
                auto it = qt.front();
                qt.pop();
                int localSum = 0;
                if(it->left){
                    qt.push(it->left);
                    localSum += it->left->val;
                }
                if(it->right){
                    qt.push(it->right);
                    localSum += it->right->val;
                }
                totalSum += localSum;
                if(it->left){
                    mp[it->left] = localSum;
                }
                if(it->right){
                    mp[it->right] = localSum;
                }
            }
            qt.pop();
            for(auto m : mp){
                m.first->val = totalSum - mp[m.first];
            }
        }
        root->val = 0;
        return root;
    }

    void preOrder(TreeNode *t){
        if(!t){
            return;
        }
        cout << t->val << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
};

int main(){
    TreeNode *t = new TreeNode(5);
    t->left = new TreeNode(5);
    t->right = new TreeNode(5);
    t->left->left = new TreeNode(5);
    t->left->right = new TreeNode(5);
    t->right->left = new TreeNode(5);
    t->right->right = new TreeNode(5);
    Solution s;
    s.replaceValueInTree(t);
    s.preOrder(t);
    cout << endl;
    return 0;
}