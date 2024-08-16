#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

class Queue{
    public:
        int first, size, last;
        Node **Q;

        Queue(int size){
            first = last = -1;
            this->size = size;
            Q = new Node*[this->size];
        }

        void enqueue(Node *p);
        Node* dequeue();
        bool isEmpty(){
            return first == last;
        }
};

void Queue::enqueue(Node *p){
    if(last == size - 1){
        cout << "Queue is completely full" << endl;
        return;
    }
    Q[++last] = p;
}

Node* Queue::dequeue(){
    if(first == last){
        return NULL;
    }
    return Q[++first];
}


class Stack{
    public:
        int index, size;
        Node **S;

        Stack(int size){
            index = -1;
            this->size = size;
            S = new Node*[this->size];
        }

        void push(Node *p);
        void pop();
        bool isEmpty(){
            return index == -1;
        }
        Node* top();
};

void Stack::push(Node *p){
    if(index == size - 1){
        cout << "Stack is completely full" << endl;
        return;
    }
    S[++index] = p;
}

void Stack::pop(){
    if(index == -1){
        cout << "Stack is now empty" << endl;
        return;
    }
    index--;
}

Node* Stack::top(){
    if(index == -1){
        return NULL;
    }
    return S[index];
}

class Tree{
    public:
        Node *root = new Node;

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

        int Count(){
            return Count(root);
        }
        int Count(Node *p);
};

void Tree::createTree(){
    Node *p,*t;
    Queue q(100);
    int x;
    cout << "Enter root element value" << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout << "Enter left child value of: " << p->data;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child value of: " << p->data;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }       
    }
}

void Tree::preOrder(Node *p){
    Stack st(10);
    while(p || !st.isEmpty()){
        if(p){
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }else{
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
}

void Tree::inOrder(Node *p){
    Stack st(10);
    while(p || !st.isEmpty()){
        if(p){
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

void Tree::postOrder(Node *p){
    Stack st(20);
    unordered_map<Node*,int> mp;
    Node *temp;
    while(p || !st.isEmpty()){
        if(p){
            st.push(p);
            p = p->lchild;
        }else{
            p = st.top();
            st.pop();
            if(mp.find(p) == mp.end()){
                st.push(p);
                mp[p]++;
                p = ((Node*)p)->rchild;
            }else{
                cout << p->data << " ";
                p = NULL;
            }
        }
    }
}

void Tree::levelOrder(Node *p){
    Queue q(100);
    q.enqueue(p);
    cout << p->data << " ";
    while(!q.isEmpty()){
        p = q.dequeue();
        if(p->lchild){
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if(p->rchild){
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *p){
    int x,y;
    if(p == NULL){
        return -1;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

int Tree::Count(Node *p){
    if(p == NULL){
        return 0;
    }
    return Count(p->lchild) + Count(p->rchild) + 1; 
}

int main(){
    Tree t;
    t.createTree();
    t.preOrder();
    cout << endl;
    t.inOrder();
    cout << endl;
    t.postOrder();
    cout << endl;
    t.levelOrder();
    cout << endl;
    cout << "Height of tree is: " << t.Height() << endl;
    cout << "Number of nodes in Tree: " << t.Count() << endl;
    return 0;
}