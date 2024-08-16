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

Node* recursiveReverse(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *sHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return sHead;
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
    head = recursiveReverse(head);
    printLinkedList(head);
    return 0; 
}