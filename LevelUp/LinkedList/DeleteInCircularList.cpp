#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int a){
            data = a;
            next = NULL;
        }
};

Node* deleteNode(Node *head, int key){
    if(head == NULL){
        return head;
    }
    Node *last = head;
    while(head->data == key){
        head = head->next;
        if(head == last){
            return NULL;
        }
    }
    last = head;
    Node *p = head->next;
    while(1){
        while(p->data == key){
            p = p->next;
        }
        if(p == last){
            head->next = last;
            break;
        }
        head->next = p;
        head = p;
        p = p->next;
    }
    Node *ch = last->next;
    return last;
}

int main(){
    Node *a = new Node(5);
    a->next = new Node(5);
    a->next->next = new Node(7);
    a->next->next->next = new Node(5);
    a->next->next->next = new Node(10);
    a->next->next->next->next = a;

    Node *b = deleteNode(a, 5);
    Node *c = b->next;
    cout << b->data << endl;
    while(b != c){
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
    return 0;
}