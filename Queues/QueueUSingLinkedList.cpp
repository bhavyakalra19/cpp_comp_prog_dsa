#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    public:
        Node *front, *rear;
        Queue(){
            Node *front = NULL, *rear = NULL;
        }

        void enqueue(int x);
        int dequeue();
        void display();
};


void Queue::enqueue(int x){
    Node *t = new Node;
    if(t==NULL){
        cout << "Queue is completely full" << endl;
    }else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front=rear=t;
        }
    }
}

int Queue::dequeue(){
    if(front == NULL){
        cout << "Queue is empty" << endl;
        return -1;
    }else{
        Node *p = front;
        front = front->next;
        return p->data;
        delete p;
        cout << "Hello" << endl;
    }
}

void Queue::display(){
    if(front == NULL){
        cout << "Queue is  compeletly empty" << endl;
        return;
    }
    Node *p = front;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



int main(){
    Queue q;
    q.enqueue(1);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}