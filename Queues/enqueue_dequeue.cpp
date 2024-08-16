#include<bits/stdc++.h>
using namespace std;

struct QueueNode{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(QueueNode *q, int x){
    q->size = x;
    q->front = q->rear = -1;
    q->arr = new int[x];
}


void enqueue(QueueNode *q, int n){
    if(q->rear == q->size - 1){
        cout << "Queue is full so can not insert: " << n << endl;
    }else{
        q->arr[++q->rear] = n;
    }
}

void display(QueueNode *q){
     if(q->front == q->rear){
        cout << "Can not display elements queue is empty" << endl;
    }else{
        for(int i=q->front+1; i <= q->rear; i++){
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

void dequeue(QueueNode *q){
    if(q->front == q->rear){
        cout << "Can not remove element queue is empty" << endl;
    }else{
        cout << "value deleted: " << q->arr[++q->front] << endl;
    }
}

int main(){
    QueueNode *q = new QueueNode;
    create(q,7);
    enqueue(q,50);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}