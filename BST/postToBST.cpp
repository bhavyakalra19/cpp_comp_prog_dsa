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

Node* createBSTFromPostorder(vector<int> arr){
    if(arr.size() == 0){
        return NULL;
    }
    stack<Node*> st;
    Node *root = newNode(arr[arr.size() - 1]);
    Node *p = root;
    st.push(p);
    for(int i = arr.size()-2; i>=0;){
        if(arr[i] > p->data){
            Node *t = newNode(arr[i]);
            p->rchild = t;
            st.push(p);
            i--;
            p=t;
        }else{
            if(st.empty() || arr[i] > (st.top())->data){
                Node *t = newNode(arr[i]);
                p->lchild = t;
                i--;
                p=t;
            }else{
                p = st.top();
                st.pop();
            }
        }
    }
    return root;
}

void  inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

int main(){
    vector<int> v{35,45,40,55,65,60,50};
    Node *root = createBSTFromPostorder(v);
    inOrder(root);
    cout << endl;
    return 0;
}