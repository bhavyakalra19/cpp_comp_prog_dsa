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

        Node* firstElement(){
            return head;
        }
};

void display(Node *p){
    if(p!=NULL){
        cout << p->data << " ";
        display(p->next);
    }else{
        cout << endl;
    }
}

Node* Merge(Node* first, Node* second){
    Node *head,*last;
    head = NULL;
    last = NULL;
    if(first == NULL && second == NULL){
        return NULL;
    }else if(first == NULL){
        head = last = second;
        second = second->next;
    }else if(second == NULL){
        head = last = first;
        first = first->next;
    }else if(first->data<second->data && first){
        head = last = first;
        first = first->next;
    }else{
        head = last = second;
        second = second->next;
    }

    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            last->next = first;
            last = first;
            first = first->next;
        }else{
            last->next = second;
            last = second;
            second = second->next;
        }
    }

    if(first!=NULL){
        last->next = first;
        while(first->next!=NULL){
            first = first->next;
        }
        last = first;
    }

    if(second!=NULL){
        last->next = second;
        while(second->next!=NULL){
            second = second->next;
        }
        last = second;
    }
    return head;
}


int main(){
    int a1[] = {1,3,4,5,9,10,11};
    int a2[] = {2,6,7,8};
    LinkedList l1(a1,7);
    LinkedList l2(a2,4);
    Node* first = l1.firstElement();
    Node* second = l2.firstElement();
    display(first);
    display(second);
    Node *n = Merge(first,second);
    display(n);
    return 0;
}