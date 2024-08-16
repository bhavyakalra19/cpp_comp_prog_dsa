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

        Node* headElement(){
            return head;
        }
};


void display(Node *p){
    if(p==NULL){
        cout << endl;
        return;
    }
    cout << p->data << " ";
    return display(p->next);
}

Node* LinearSearch(Node *p,int key){
    Node* head = p;
    Node *q;
    while(p!=NULL){
        if(p->data == key){
            if(p == head){
                return head;
            }
            q->next = p->next;
            p->next = head;
            head = p;
            return head;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int main(){
    int a[] = {1,2,3,4,5};
    LinkedList l(a,5);
    Node *first = l.headElement();
    Node *j = LinearSearch(first,1);
    display(j);
    return 0;
}