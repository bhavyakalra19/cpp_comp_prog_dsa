#include<bits/stdc++.h>
using namespace std;

class compare{
    public:
        bool operator()(int a, int b){
            return a > b;
        }

};

void createMinHeap(){
    vector<int> v{4,2,1,3,5};
    priority_queue<int, vector<int>, compare> pq(v.begin(), v.begin() + v.size());
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    createMinHeap();
    return 0;
}
