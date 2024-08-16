#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int height;
        Node *left;
        Node *right;

        Node(int data){
            height = 1;
            this->data = data;
            left = right = NULL;
        }        
};

int heightAnalysis(Node *p){
    int hl = p && p->left ? p->left->height : 0;
    int hr = p && p->right ? p->right->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balancedHeight(Node *p){
    int hl = p && p->left ? p->left->height : 0;
    int hr = p && p->right ? p->right->height : 0;
    return hl - hr;
}

Node* LLRotation(Node *p){
    Node* pl = p->left;
    p->left = pl->right;
    pl->right = p;
    p->height = heightAnalysis(p);
    pl->height = heightAnalysis(pl);
    return pl;
}

Node* LRRotation(Node *p){
    Node* pl = p->left;
    Node *plr = pl->right;
    p->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = p;
    pl->height = heightAnalysis(pl);
    p->height = heightAnalysis(p);
    plr->height = heightAnalysis(plr);
    return plr;
}

Node* RRRotation(Node *p){
    Node* pr = p->right;
    p->right = pr->left;
    pr->left = p;
    p->height = heightAnalysis(p);
    pr->height = heightAnalysis(pr);
    return pr;
}

Node* RLRotation(Node *p){
    Node *pr = p->right;
    Node *prl = pr->left;
    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;
    pr->height = heightAnalysis(pr);
    p->height = heightAnalysis(p);
    prl->height = heightAnalysis(prl);
    return plr;
}

Node* createTree(Node *p,int key){
    if(p == NULL){
        Node *t = new Node(key);
        return t;
    }

    if(key < p->data){
        p->left = createTree(p->left,key);
    }else{
        p->right = createTree(p->right,key);
    }
    p->height = heightAnalysis(p);
    int bh = balancedHeight(p);
    if(bh == 2){
        if(balancedHeight(p->left) == 1){
            return LLRotation(p);
        }else{
            return LRRotation(p);
        }
    }else if(bh == -2){
        if(balancedHeight(p->right) == -1){
            return RRRotation(p);
        }else{
            return RLRotation(p);
        }
    }
    return p;
}

void preOrder(Node *head){
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

int main(){
    Node *head = NULL;
    head = createTree(head,9);
    head = createTree(head,7);
    head = createTree(head,8);
    preOrder(head);
    cout << endl;
    return 0;
}
