#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head, *last;
    public: 
        LinkedList(){
            head = NULL;
            last = NULL;
        }

        LinkedList(int arr[],int n){
            Node *tmp = new Node;
            tmp->data = arr[0];
            tmp->next = NULL;
            head = tmp;
            last = tmp;

            for(int i=1;i<n;i++){
                Node *tmp = new Node;
                tmp->data = arr[i];
                tmp->next = NULL;
                last->next = tmp;
                last = tmp;
            }
        }

        Node* getHead(){
            return head;
        }

        void display();
        void Reverse(Node *q,Node *p);
};

void LinkedList::Reverse(Node *q, Node *p){
    if(p==NULL){
        head = q;
    }
    if(p!=NULL){
        Reverse(p,p->next);
        p->next = q;
    }
}


void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}


int main(){
    int a[] = {5,6,7,8,9};
    LinkedList l(a,5);
    l.display();
    Node *first = l.getHead();
    l.Reverse(NULL,first);
    l.display();
    return 0;
}