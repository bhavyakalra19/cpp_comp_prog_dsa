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

Node* buildTree(Node *head){
    int d;
    if(head == NULL){
        cout << "Enter root element value: ";
    }else{
        cout << "Enter value for the: " << head->data << " ";
    }
    cin >> d;

    if(d == -1){
        return NULL;
    }

    Node *n = new Node(d);
    n->left = buildTree(n);
    n->right = buildTree(n);
    return n;
}

void printLevelOrder(Node *head){
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    while(!q.empty()){
        Node *p = q.front();
        q.pop();
        if(p == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
            }
        }else{
            cout << p->data << " ";
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
    }
}

int main(){
    Node *head = NULL;
    head = buildTree(head);
    printLevelOrder(head);
    cout << endl;
    return 0;
}