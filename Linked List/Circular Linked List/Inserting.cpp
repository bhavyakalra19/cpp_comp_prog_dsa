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
            last->next = head;
        }

        void display();
        void Insert(int x,int pos);
};


void LinkedList::display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
    cout << endl;
}

void LinkedList::Insert(int x,int pos){
    Node *t = new Node;
    t->data = x;
    if(pos == 0){
        if(head == NULL){
            head = t;
            head->next =head;
        }else{
            Node *p = head;
            while(p->next!=head){
                p=p->next;
            }
            t->next = p->next;
            p->next = t;
            head = t;
        }
    }else{
        Node *p = head;
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}


int main(){
    int a[] = {6,7,8,9};
    LinkedList l(a,4);
    l.display();
    l.Insert(10,4);
    l.display();
    return 0;
}