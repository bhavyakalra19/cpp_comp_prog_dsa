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
        void Delete(int pos);
};


void LinkedList::display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
    cout << endl;
}

void LinkedList::Delete(int pos){
    Node *p, *q;
    if(pos == 1){
        p=head;
        while(p->next!=head){
            p = p->next;
        }
        if(p == head){
            delete head;
            head = NULL;
        }
        p->next = head->next;
        delete head;
        head = p->next;
    }else{
        p = head;
        for(int i=0; i<pos-2;i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
    }
}


int main(){
    int a[] = {6,7,8,9,10};
    LinkedList l(a,5);
    l.display();
    l.Delete(5);
    l.display();
    return 0;
}