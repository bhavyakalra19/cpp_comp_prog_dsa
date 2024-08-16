#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *lChild;
        Node *rChild;
};

class Queue{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new Node*[size];
        }

        Queue(int size){
            this->size = size;
            front = rear = -1;
            Q = new Node*[this->size];
        }

        void enqueue(Node *p);
        Node* dequeue();
        int isEmpty(){
            return front == rear;
        }
};


void Queue::enqueue(Node *p){
    if(rear == size - 1){
        cout << "Queue is completely full" << endl;
    }else{
        Q[++rear] = p;
    }
}

Node* Queue::dequeue(){
    if(front == rear){
        cout << "Queue is empty" << endl;
        return NULL;
    }
    return Q[++front];
}