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
        bool CheckSorted();
};



void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool LinkedList::CheckSorted(){
    Node *p = head;
    int x = 0;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }else{
            x=p->data;
            p=p->next;
        }
    }
    return true;
}


int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    LinkedList l(A,9);
    l.display();
    if(l.CheckSorted()){
        cout << "Sorted" << endl;
    }else{
        cout << "Not sorted" << endl;
    }
    return 0;
}