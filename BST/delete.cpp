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

void inOrder(Node *p){
    if(p!=NULL){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

int treeHeight(Node *p){
    if(p==NULL){
        return 0;
    }
    return treeHeight(p->lchild) > treeHeight(p->rchild) ? treeHeight(p->lchild) + 1 : treeHeight(p->rchild) + 1;
}

Node* inOrderPre(Node* p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

Node* inOrderSuc(Node* p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}


Node* deleteTreeNode(Node *p, int key){
    Node *q;

    if(p==NULL){
        return NULL;
    }

    if(p->lchild == NULL && p->rchild == NULL){
        free(p);
        return NULL;
    }

    if(key < p->data){
        p->lchild = deleteTreeNode(p->lchild,key);
    }else if(key > p->data){
        p->rchild = deleteTreeNode(p->rchild,key);
    }else{
        if(treeHeight(p->lchild) > treeHeight(p->rchild)){
            q = inOrderPre(p->rchild);
            p->data = q->data;
            p->lchild = deleteTreeNode(p->lchild,q->data);
        }else{
            q = inOrderSuc(p->rchild);
            p->data = q->data;
            p->rchild = deleteTreeNode(p->rchild,q->data);
        }
    }
    return p;
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

    cout << "Height of tree is: " << treeHeight(root) << endl;

    root = deleteTreeNode(root,15);
    inOrder(root);
    cout << endl;
    return 0;
}