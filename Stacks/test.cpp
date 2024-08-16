#include<bits/stdc++.h>
using namespace std;

struct StackNode{
    int size;
    int top;
    int *arr;
};

void push(StackNode *st, int x){
    if(st->top == st->size - 1){
        cout << "Stack Overflow" << endl;
        return;
    }
    st->arr[++st->top] = x;
}

void create(StackNode *st, int s){
    st->arr = new int[s];
    st->size = s;
    st->top = -1;
}

int pop(StackNode *st){
    if(st->top == -1){
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return st->arr[st->top--];
}

int topElement(StackNode *st){
    if(st->top == -1){
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return st->arr[st->top];
}

void isEmpty(StackNode *st){
    if(st->top == -1){
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack is not Empty" << endl;
}

void displayStack(StackNode *st){
    if(st->top == -1){
        cout << "Stack is Empty" << endl;
        return;
    }

    for(int i = st->top; i >= 0; i--){
        cout << st->arr[i] << " ";
    }
    cout << endl;
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
    displayStack(st);
    cout << "Top Element is: " << topElement(st) << endl;
    cout << "Poped element is: " << pop(st) << endl;
    displayStack(st);
    isEmpty(st);
    return 0;
}