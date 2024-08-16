#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void createLinkedList(Node* &head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *c = new Node(data);
    temp->next = c;
}

void printLinkedList(Node *head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void IterativelyReverse(Node* &head){
    Node *p = head;
    Node *q = head;
    Node *prev  = NULL;
    while(q){
        p = q->next;
        q->next = prev;
        prev = q;
        q = p;
    }
    head = prev;
}

int main(){
    Node *head = NULL;
    createLinkedList(head,4);
    createLinkedList(head,5);
    createLinkedList(head,6);
    createLinkedList(head,7);
    createLinkedList(head,8);
    createLinkedList(head,9);
    printLinkedList(head);
    IterativelyReverse(head);
    printLinkedList(head);
    return 0; 
}