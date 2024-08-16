#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

Node* insert(Node* t, int key){
    if(t == NULL){
        Node *p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if(key < t->data){
        t->lchild = insert(t->lchild,key);
    }else{
        t->rchild = insert(t->rchild,key);
    }
    return t;
}

Node* insertIteratively(Node* x, int key){
    Node *r = NULL,*p;
    while(x!=NULL){
        r=x;
        if(key < x->data){
            x = x->lchild;
        }else{
            x = x->rchild;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(r==NULL){
     return p;   
    }
    if(key < r->data){
        r->lchild = p;
    }else{
        r->rchild = p;
    }
    return NULL;
}

void inOrder(Node *p){
    if(p!=NULL){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void inOrderIterative(Node *p){
    stack<Node*> st;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            st.push(p);
            p = p->lchild;
        }else{
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

Node* searchNode(Node *p,int key){
    if(p==NULL){
        return NULL;
    }

    if(key==p->data){
        return p;
    }else if(key<p->data){
        return searchNode(p->lchild,key);
    }else{
        return searchNode(p->rchild,key);
    }
}

Node* searchNodeIterative(Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }else if(key < p->data){
            p = p->lchild;
        }else{
            p = p->rchild;
        }
    }
    return p;
}

int treeHeight(Node *p){
    if(p==NULL){
        return 0;
    }
    return treeHeight(p->lchild) > treeHeight(p->rchild) ? treeHeight(p->lchild) + 1 : treeHeight(p->rchild) + 1;
}

int main(){
    Node *root = NULL;
    root = insert(root,20);
    insert(root,15);
    insert(root,14);
    insert(root,16);
    insert(root,25);
    insert(root,24);
    insert(root,26);

    inOrder(root);
    cout << endl;
    inOrderIterative(root);
    cout << endl;

    Node *p = searchNode(root,21);
    if(p){
        cout << p->data << endl;
    }else{
        cout << "Key not found in BST" << endl;
    }

    p = searchNodeIterative(root,24);
    if(p){
        cout << p->data << endl;
    }else{
        cout << "Key not found in BST" << endl;
    }

    cout << "Height of tree is: " << treeHeight(root) << endl;
    return 0;
}