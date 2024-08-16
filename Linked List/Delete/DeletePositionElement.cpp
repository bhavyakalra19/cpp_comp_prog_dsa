#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head,*last;
    public:
        LinkedList(){
            head = NULL;
            last = NULL;
        }

        LinkedList(int arr[],int n){
            Node *t = new Node;
            t->data = arr[0];
            t->next = NULL;
            head = t;
            last = t;

            for(int i=1;i<n;i++){
                Node *t = new Node;
                t->data = arr[i];
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }

        void display();
        void Delete(int pos);
};

void LinkedList::Delete(int pos){
    Node *p, *q;
    p = head;
    for(int i=0;i<pos-1; i++){
        q=p;
        p=p->next;
    }
    q->next = p->next;
    delete p;
}


void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    LinkedList l(A,9);
    l.display();
    l.Delete(8);
    l.display();
    return 0;
}