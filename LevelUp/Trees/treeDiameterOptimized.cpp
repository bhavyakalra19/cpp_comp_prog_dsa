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

pair<int,int> diameterCal(Node *head){
    pair<int,int> left,right;
    if(head == NULL){
        return make_pair(0,0);
    }
    left = diameterCal(head->left);
    right = diameterCal(head->right);
    return make_pair(max(left.first,right.first) + 1, max((left.first + right.first),max(left.second,right.second)));
}

int main(){
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->right->left = new Node(4);
    // head->right->left->left = new Node(5);
    // head->right->left->left->left = new Node(6);
    // head->right->left->left->left->left = new Node(7);
    head->right->right = new Node(8);
    head->right->right->right = new Node(9);
    // head->right->right->right->right = new Node(10);
    // head->right->right->right->right->right = new Node(11);
    pair<int,int> p = diameterCal(head);
    cout << p.second << endl;
    return 0;
}