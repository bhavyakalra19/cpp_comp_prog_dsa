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

int KthLast(Node* head, int k){
    Node *p = head;
    Node *q = head;
    while(q && k>0){
        q = q->next;
        k--;
    }
    while(q){
        q = q->next;
        p = p->next;
    }
    return p->data;
}

int main(){
    Node *head = NULL;
    createLinkedList(head,1);
    createLinkedList(head,2);
    createLinkedList(head,3);
    createLinkedList(head,4);
    createLinkedList(head,5);
    createLinkedList(head,6);
    printLinkedList(head);
    cout << KthLast(head,3) << endl;
    return 0;
}