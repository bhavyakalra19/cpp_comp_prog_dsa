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
        int count();
        int sum();
};

void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::count(){
    Node *p = head;
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int LinkedList::sum(){
    Node* p = head;
    int sum = 0;
    while(p!=NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}


int main(){
    LinkedList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addNode(5);
    a.display();
    cout << "Count is: " << a.count() << endl;
    cout << "Sum is: " << a.sum() << endl;
    return 0;
}