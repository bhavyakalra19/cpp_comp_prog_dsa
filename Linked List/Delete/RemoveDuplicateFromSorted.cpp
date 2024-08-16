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
        void deleteDuplicate();
};

void LinkedList::deleteDuplicate(){
    Node *p, *q;
    p = head->next;
    q = head;
    while(p!=NULL){
        if(p->data == q->data){
            q->next = p->next;
            delete p;
            p=q->next;
        }else{
            q=p;
            p=p->next;
        }
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
    int a[] = {1,2,2,2,3,3,4,4,4,4,5,5};
    LinkedList l(a,12);
    l.display();
    l.deleteDuplicate();
    l.display();
    return 0;
}