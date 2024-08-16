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

        void display();
        void Reverse();
};

void LinkedList::Reverse(){
    Node *p, *q, *r;
    q=NULL;
    r=NULL;
    p = head;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;
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
    l.Reverse();
    l.display();
    return 0;
}