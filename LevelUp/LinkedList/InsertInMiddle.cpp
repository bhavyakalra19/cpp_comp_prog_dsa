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

void insertInMiddle(Node* &head, int data, int pos){
    if(pos == 0){
        Node *t = new Node(data);
        t->next = head;
        head = t;
        return;
    }
    Node *p = head;
    while(pos > 2){
        p = p->next;
        pos--;
    }
    Node *t = new Node(data);
    t->next = p->next;
    p->next = t;
}


int main(){
    Node *head = NULL;
    createLinkedList(head,4);
    createLinkedList(head,5);
    createLinkedList(head,7);
    createLinkedList(head,8);
    insertInMiddle(head,6,3);
    printLinkedList(head);
    return 0; 
}