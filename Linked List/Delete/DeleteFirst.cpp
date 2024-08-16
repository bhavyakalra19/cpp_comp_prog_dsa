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
        void deleteFirst();
};

void LinkedList::deleteFirst(){
    Node *p = head;
    head = p->next;
    delete p;
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
    int a[] = {1,2,3,4,5};
    LinkedList l(a,5);
    l.display();
    l.deleteFirst();
    l.display();
    return 0;
}