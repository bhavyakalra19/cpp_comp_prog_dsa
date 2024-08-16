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
        void Insert(int pos,int x);
};

void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::Insert(int pos,int x){
    Node *p = head;
    Node *t = new Node;
    t->data = x;
    if(pos == 0){
        t->next = p;
        head = t;
    }else if(pos>0){
        for(int i =0;i<pos-1;i++){
            p = p->next;
        }
        if(p!=NULL){
            t->next = p->next;
            p->next = t;
        }else{
            t->next = NULL;
            p->next = t;
        }
    }
}

int main(){
    int a[] = {1,2,3,4,5};
    LinkedList l(a,5);
    l.display();
    l.Insert(5,6);
    l.display();
    return 0;
}