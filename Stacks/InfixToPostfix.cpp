#include<bits/stdc++.h>
using namespace std;

struct StackNode{
    int size;
    int top;
    char *arr;
};

void push(StackNode *st, char x){
    if(st->top == st->size - 1){
        cout << "Stack Overflow" << endl;
        return;
    }
    st->arr[++st->top] = x;
}

void create(StackNode *st, int s){
    st->arr = new char[s];
    st->size = s;
    st->top = -1;
}

char pop(StackNode *st){
    return st->arr[st->top--];
}

char topElement(StackNode *st){
    if(st->top == -1){
        cout << "Stack is Empty" << endl;
        return '\0';
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

int isOperand(char x){
    if(x == '+' || x == '/' || x == '-' || x == '*'){
        return 0;
    }
    return 1;
}

int preOrder(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    return 2;
}

char *InfixToPostfix(StackNode *st, string s){
    create(st,s.length() + 1);
    int i=0,j=0;
    char *postfix = new char[s.length() + 1];
    while(s[i] != '\0'){
        if(isOperand(s[i])){
            postfix[j++] = s[i++];
        }else{
            if(st->top == -1){
                push(st,s[i++]);
            }else if(preOrder(s[i]) > preOrder(topElement(st))){
                push(st,s[i++]);
            }else{
                postfix[j++] = pop(st);
            }
        }
    }
    while(st->top != -1){
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    StackNode *st = new StackNode;
    string s = "a+b*c-d/e";
    char *p = InfixToPostfix(st,s);
    int i = 0;
    while(p[i] != '\0'){
        cout << p[i++] << " ";
    }
    cout << endl;
    return 0;
}