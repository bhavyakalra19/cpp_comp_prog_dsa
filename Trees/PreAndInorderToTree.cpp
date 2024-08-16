#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

Node* newNode(int val){
    Node *temp = new Node;
    temp->data = val;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

Node* CreateTree(vector<int> pre, vector<int> in){
    if(pre.size()==0){
        return NULL;
    }
    unordered_map<int,int> mp;
    for(int i=0; i<in.size(); i++){
        mp[in[i]] = i;
    }

    Node *root = newNode(pre[0]);
    stack<Node*> st;
    Node* p = root;
    for(int i = 1; i < pre.size();){
        if(mp[pre[i]] < mp[p->data]){
            Node *temp = newNode(pre[i]);
            p->lchild = temp;
            st.push(p);
            p = temp;
            i++;
        }else{
            if(st.empty() || (mp[pre[i]] < mp[st.top()->data])){
                Node *temp = newNode(pre[i]);
                p->rchild = temp;
                p=temp;
                i++;
            }else{
                p = st.top();
                st.pop();
            }
        }
    }
    return root;
}

void inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

int main(){
    vector<int> pre{50,40,1,2,60,3,4};
    vector<int> in{1,40,2,50,3,60,4};
    Node *root = CreateTree(pre,in);
    inOrder(root);
    cout << endl;
    return 0;
}