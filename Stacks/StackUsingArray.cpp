#include<bits/stdc++.h>
using namespace std;

struct StackNode{
    int size;
    int top;
    int *arr;
};

void display(StackNode *temp){
    if(temp->top == -1){
        cout << "Stack is empty" << endl;
    }
    for(int i = temp->top; i >= 0 ; i--){
        cout << temp->arr[i] << " ";
    }
    cout << endl;
}

void push(StackNode *temp, int x){
    if(temp->top == temp->size -1){
        cout << "Stack overflow" << endl;
        return;
    }
    temp->arr[++temp->top] = x;
    cout << "pushed: " << x << endl;
}

int pop(StackNode *temp){
    if(temp->top == -1){
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return temp->arr[temp->top--];
}

void create(StackNode *p,int size){
    p->size = size;
    p->arr = new int[size];
    p->top = -1;
}

int main(){
    StackNode *st = new StackNode;
    create(st,6);
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    push(st,6);
    push(st,7);
    display(st);
    cout << "Element pop is: " << pop(st) << endl;
    display(st);
    return 0;
}