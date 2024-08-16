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
    int data;

    Solution(){
        data = 0;
    }

    int recursion(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int a = recursion(root->left);
        int b = recursion(root->right);
        if(a == -1 || b == -1){
            data += 1;
            return 1;
        }
        if(a == 0 && b == 0){
            return -1;
        }
        if(a == 1 || b == 1){
            return 0;
        }
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        int a = recursion(root);
        if(a == -1){
            data += 1;
        }
        return data;
    }
};

int main(){
    Solution s;
    TreeNode *head = new TreeNode(0);
    head->right = new TreeNode(0);
    head->right->right = new TreeNode(0);
    head->right->right->left = new TreeNode(0);
    head->right->right->right = new TreeNode(0);
    cout << s.minCameraCover(head) << endl;
    return 0;
}