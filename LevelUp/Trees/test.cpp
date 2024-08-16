#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        stack<TreeNode*> st;
        TreeNode *root = new TreeNode(postorder[n-1]);
        TreeNode *curr = root;
        for(int i = n - 2; i >= 0; i--){
            TreeNode *temp = new TreeNode(postorder[i]);
            if(mp[postorder[i]] > mp[curr->val]){
                curr->right = temp;
                st.push(curr);
                curr = temp;
            }else{
                while(!st.empty() || mp[postorder[i]] > mp[st.top()->val]){
                    curr = st.top();
                    st.pop();
                }
                curr->left = temp;
                curr = temp;
            }
        }
        return root;      
    }
};
