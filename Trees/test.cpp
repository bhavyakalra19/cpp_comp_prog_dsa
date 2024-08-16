#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* createTree(){
    queue<Node*> st;
    int x;
    cout << "Enter root element value for tree: ";
    cin >> x;
    Node *head = new Node(x);
    st.push(head);
    Node *t;
    while(!st.empty()){
        Node *p = st.front();
        st.pop();
        cout << "Enter left element for " << p->data << " ";
        cin >> x;
        if(x != -1){
            Node *t  = new Node(x);
            p->left = t;
            st.push(t);
        }

        cout << "Enter right element for " << p->data << " ";
        cin >> x;
        if(x != -1){
            Node *t  = new Node(x);
            p->right = t;
            st.push(t);
        }
    }
    return head;
}

void preOrder(Node *head){
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void preOrderIterative(Node *p){
    stack<Node*> st;
    while(p || !st.empty()){
        if(p){
            cout << p->data << " ";
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
}

void inOrderIterative(Node *p){
    stack<Node*> st;
    while(p || !st.empty()){
        if(p){
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void postOrderIterative(Node *p){
    stack<Node*> st;
    unordered_map<Node*,int> mp;
    while(p || !st.empty()){
        if(p){
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            st.pop();
            if(mp.find(p) != mp.end()){
                cout << p->data << " ";
                p = NULL;
            }else{
                st.push(p);
                mp[p] = 1;
                p = p->right;
            }
        }
    }
}

int main(){
    Node *head = createTree();
    postOrderIterative(head);
    cout << endl;
    return 0;
}