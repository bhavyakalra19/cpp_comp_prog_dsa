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

Node* preToBst(vector<int> v){
    stack<Node*> st;
    Node *head = new Node(v[0]);
    Node *p = head;
    st.push(p);
    for(int i = 1; i < v.size(); i++){
        if(v[i] < v[i-1]){
            Node *t = new Node(v[i]);
            p->left = t;
            p = t;
            st.push(p);
        }else{
            while(!st.empty() && v[i] > (st.top())->data){
                p = st.top();
                st.pop();
            }
            Node *t = new Node(v[i]);
            p->right = t;
            p = t;
            st.push(p);
        }
    }
    return head;
}

void inOrder(Node *head){
    if(head == NULL){
        return;
    }
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

int main(){
    vector<int> v{50,40,35,45,42,41,44,60,55,65};
    Node *head = preToBst(v);
    inOrder(head);
    cout << endl;
    return 0;
}