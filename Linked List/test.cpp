#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head, *last;
    public: 
        LinkedList(){
            head = NULL;
            last = NULL;
        }

        LinkedList(int arr[],int n){
            Node *tmp = new Node;
            tmp->data = arr[0];
            tmp->next = NULL;
            head = tmp;
            last = tmp;

            for(int i=1;i<n;i++){
                Node *tmp = new Node;
                tmp->data = arr[i];
                tmp->next = NULL;
                last->next = tmp;
                last = tmp;
            }
        }

        Node *firstElement(){
            return head;
        }

        void display();
        bool checkPalindrome(Node *q);
};


bool LinkedList::checkPalindrome(Node *q){
    static Node* p = head;
    static int x =0, y =-1;
    static bool A = true;
    if(q==NULL){
        return A;
    }
    x = x+1;
    cout << x << endl;
    checkPalindrome(q->next);
    y++;
    if(y > x/2){
        return A;
    }
    if(A == false){
        return A;
    }else if(y < x/2 && p->data != q->data){
        A = false;
    }
    p = p->next;
    return A;
}

void LinkedList::display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}


int main(){
    int a[] = {1,2,3,5,4,3,2,1};
    LinkedList l(a,8);
    l.display();
    Node *first = l.firstElement();
    // bool b = l.checkPalindrome(first);
    cout << b << endl;
    return 0;
}