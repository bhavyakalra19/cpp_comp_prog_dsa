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

Node* createTree(vector<int> post, vector<int> in){
    if(post.size() == 0){
        return NULL;
    }
    unordered_map<int,int> mp;
    for(int i = 0; i < post.size(); i++){
        mp[in[i]] = i;
    }

    stack<Node*> st;
    Node *root = newNode(post[post.size()-1]);
    Node *p = root;
    for(int i = post.size()-2; i >= 0;){
        if(mp[post[i]] > mp[p->data]){
            Node *t = newNode(post[i]);
            p->rchild = t;
            st.push(p);
            p=t;
            i--;
        }else{
            if(st.empty() || mp[post[i]] > mp[st.top()->data]){
                Node *t = newNode(post[i]);
                p->lchild = t;
                p=t;
                i--;
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
    vector<int> post{1,2,40,3,4,60,50};
    vector<int> in{1,40,2,50,3,60,4};
    Node *root = createTree(post,in);
    inOrder(root);
    cout << endl;
    return 0;
}