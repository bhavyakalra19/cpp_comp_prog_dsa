#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int s;
        int t;
        Node *left;
        Node *right;
        Node(int s, int t){
            this->s = s;
            this->t = t;
            left = NULL;
            right = NULL;
        }
};

class MyCalendarTwo {
public:
    Node *root;
    vector<pair<int,int>> check;
    
    MyCalendarTwo() {
        root = NULL;    
    }
    
    bool dfs(int s, int t, Node* &curr, bool check){
        if(!curr){
            if(check == true){
                return 1;
            }
            curr = new Node(s,t);
            return 1;
        }

        if(curr && t <= curr->s){
            return dfs(s,t,curr->left,check);
        }
        if(curr && s >= curr->t){
            return dfs(s,t,curr->right,check);
        }
        return 0;
    }

    bool book(int start, int end) {
        if(!dfs(start,end,root,1)){
            return false;
        }

        for(auto c : check){
            if(c.first < end && start < c.second){
                int overlapMin = max(c.first, start);
                int overlapMax = min(c.second, end);
                dfs(overlapMin,overlapMax,root,0);
            }
        }
        check.push_back({start,end});
        return true;
    }
};

int main(){
    MyCalendarTwo m;
    vector<pair<int,int>> check{{10,20},{50,60},{10,40},{5,10},{0,50}};
    for(auto c : check){
        cout << m.book(c.first, c.second) << endl;
    }
    return 0;
}