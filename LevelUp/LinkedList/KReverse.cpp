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

Node* KReverse(Node* head, int k){
    if(head == NULL){
        return head;
    }
    Node *p = head;
    Node *q = head;
    Node *prev  = NULL;
    int cnt = 1;
    while(q && cnt <=k){
        p = q->next;
        q->next = prev;
        prev = q;
        q = p;
        cnt++;
    }
    if(p!= NULL){
        head->next = KReverse(p,k);
    }
    return prev;
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
    head = KReverse(head,2);
    printLinkedList(head);
    return 0; 
}