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

Node* midElement(Node *head){
    Node* p = head->next;
    Node* q = head;
    while(p != NULL && p->next != NULL){
        q = q->next;
        p = p->next->next;
    }
    return q;
}

Node* mergeTwoSortedLL(Node *a, Node *b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    Node *c;
    if(a->data < b->data){
        c = new Node(a->data);
        c->next = mergeTwoSortedLL(a->next,b);
    }else{
        c = new Node(b->data);
        c->next = mergeTwoSortedLL(a,b->next);
    }
    return c;
}

Node* MergeSort(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *mid = midElement(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;
    a = MergeSort(a);
    b = MergeSort(b);
    return mergeTwoSortedLL(a,b);
}

int main(){
    Node *head = NULL;
    createLinkedList(head,6);
    createLinkedList(head,3);
    createLinkedList(head,1);
    createLinkedList(head,4);
    createLinkedList(head,2);
    createLinkedList(head,5);
    head = MergeSort(head);
    printLinkedList(head);
    return 0;
}