#include<bits/stdc++.h>
#include "treeNodeQueue.cpp"
using namespace std;

class Tree{
    public:
        Node *root = new Node;

        // Tree(){
        //     root = NULL;
        // }

        void createTree();
        void preOrder(){
            preOrder(root);
        }
        void preOrder(Node *p);

        void inOrder(){
            inOrder(root);
        }
        void inOrder(Node *p);

        void postOrder(){
            postOrder(root);
        }
        void postOrder(Node *p);

        void levelOrder(){
            levelOrder(root);
        }
        void levelOrder(Node *p);

        int Height(){
            return Height(root);
        }
        int Height(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root element value: ";
    cin >> x;
    cout << endl;
    root->data = x;
    root->lChild = root->rChild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();

        //Data entry for Left Child
        cout << "Enter left child value for " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            q.enqueue(t);
        }

        //Data entry for Right Child
        cout << "Enter right child value for " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout << p->data << " ";
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->lChild);
        cout << p->data << " ";
        inOrder(p->rChild);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->lChild);
        postOrder(p->rChild);
        cout << p->data << " ";
    }
}

void Tree::levelOrder(Node *p){
    Queue q(100);
    cout << p->data << " ";
    q.enqueue(p);
    while(!q.isEmpty()){
        p = q.dequeue();
        if(p->lChild){
            cout << p->lChild->data << " ";
            q.enqueue(p->lChild);
        }
        if(p->rChild){
            cout << p->rChild->data << " ";
            q.enqueue(p->rChild);
        }
    }
}

int Tree::Height(Node *p){
    int x = 0, y = 0;
    if(p == NULL){
        return -1;
    }
    x = Height(p->lChild);
    y = Height(p->rChild);
    return x > y ? x+1 : y+1;
}

int main(){
    Tree t;
    t.createTree();
    cout << "Pre: ";
    t.preOrder();
    cout << endl;
    cout << "In: ";
    t.inOrder();
    cout << endl;
    cout << "Post: ";
    t.postOrder();
    cout << endl;
    cout << "Level: ";
    t.levelOrder();
    cout << endl << "Height of tree: " << t.Height() << endl;
    return 0;
}