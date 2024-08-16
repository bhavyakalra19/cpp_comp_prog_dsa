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

        Node* firstElement(){
            return head;
        }

        void display();
        void display(Node *p);
};


void LinkedList::display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p!=head);
    cout << endl;
}

void LinkedList::display(Node *p){
    static int flag = 0;
    if(p!=head || flag == 0){
        flag = 1;
        cout << p->data << " ";
        display(p->next);
    }else{
        cout << endl;
    }
}


int main(){
    int a[] = {6,7,8,9};
    LinkedList l(a,4);
    l.display();
    Node *first = l.firstElement();
    l.display(first);
    return 0;
}