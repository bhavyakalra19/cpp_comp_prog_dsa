#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};


class LinkedList{
    private:
        Node *head,*tail;
    public:
        LinkedList(){
        head = NULL;
        tail = NULL; 
        }

        void addNode(int n){
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;

            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }

        Node* first(){
            return head;
        }
};

void display(Node *p){
    if(p==NULL){
        cout << endl;
        return;
    }
    cout << p->data << " ";
    return display(p->next);
}

Node* LinearSearch(Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key == p->data){
        return p;
    }
    return LinearSearch(p->next,key);
}

int main(){
    LinkedList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addNode(5);
    Node *first = a.first();
    Node *s = LinearSearch(first,4);
    cout << s->data << endl;
    return 0;
}