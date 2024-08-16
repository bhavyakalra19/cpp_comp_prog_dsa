#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
} *first=NULL;

void create(int arr[],int n){
    struct Node *t, *last;
    Node* first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p){
    while(p != NULL){
        cout << "hello" << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    display(first);
    return 0;
}