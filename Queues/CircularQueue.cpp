#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(Queue *q, int s){
    q->front  = q->rear = 0;
    q->size = s+1;
    q->arr = new int[s+1];
}

void enqueue(Queue *q, int x){
    if((q->rear+1)%q->size == q->front){
        cout << "Queue is full can not insert: " << x << endl;
    }else{
        q->rear = (q->rear + 1)%q->size;
        q->arr[q->rear] = x;
        cout << "Value inserted in queue is: " << x << endl;
    }
}

int dequeue(Queue *q){
    if(q->front == q->rear){
        cout << "Can not pop out element as queue is empty ";
        return -1;
    }else{
        q->front = (q->front + 1)%q->size;
        return q->arr[q->front];
    }
}

void display(Queue *q){
    if(q->front == q->rear){
        cout << "Can not display queue is empty" << endl;
        return;
    }
    int x = q->front;
    while(x != q->rear){
        x = (x+1)%q->size;
        cout << q->arr[x] << " ";
    }   
    cout << endl;
}

int main(){
    Queue *q = new Queue;
    create(q,6);
    for(int i=1; i<=6; i++){
        enqueue(q,i);
    }
    enqueue(q,50);
    display(q);
    for(int i=0; i<=7; i++){
        cout << "dequeue: " << dequeue(q) << endl;
    }
    display(q);
    for(int i=1; i<=6; i++){
        enqueue(q,i);
    }
    display(q);
    return 0;
}