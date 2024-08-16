#include<bits/stdc++.h>
using namespace std;

void createMaxHeap(){
    vector<int> v{4,2,1,3,5};
    priority_queue<int> pq(v.begin(), v.begin() + v.size());
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}


void createMinHeap(){
    vector<int> v{4,2,1,3,5};
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.begin() + v.size());
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    createMaxHeap();
    createMinHeap();
    return 0;
}
