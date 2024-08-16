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

void preOrder(Node *head){
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

int main(){
    Node *head = NULL;
    head = buildTree(head);
    preOrder(head);
    cout << endl;
    return 0;
}