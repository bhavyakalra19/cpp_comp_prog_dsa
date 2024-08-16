#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

Node* newNode(int d){
    Node *temp = new Node;
    temp->data = d;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

Node* createBSTFromPreorder(vector<int> arr){
    if(arr.size()==0){
        return NULL;
    }

    Node *root = newNode(arr[0]);
    Node *p = root;
    stack<Node*> st;
    st.push(p);
    for(int i = 1; i < arr.size();){
        if(arr[i] < p->data){
            Node *t = newNode(arr[i]);
            p->lchild = t;
            st.push(t);
            p=t;
            i++;
        }else{
            if(st.empty() || arr[i] < (st.top())->data){
                Node *t = newNode(arr[i]);
                p->rchild = t;
                p=t;
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
    vector<int> v{50,40,35,45,60,55,65};
    Node *root = createBSTFromPreorder(v);
    inOrder(root);
    cout << endl;
    return 0;
}