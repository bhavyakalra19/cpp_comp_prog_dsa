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

        void display();
        int Max();
};

void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Max(){
    Node* p = head;
    int max = 0;
    while(p!=NULL){
        max = max > p->data ? max : p->data;
        p = p->next;
    }
    return max;
}

int main(){
    LinkedList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addNode(5);
    a.display();
    cout << "Max is: " << a.Max() << endl;
    return 0;
}