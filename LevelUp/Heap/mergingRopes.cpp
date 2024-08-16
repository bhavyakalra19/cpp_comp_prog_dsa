#include<bits/stdc++.h>
using namespace std;

int mergingRopes(vector<int> nums){
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + nums.size());
    while(!minHeap.empty()){
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        cost += a+b;
        if(!minHeap.empty()){
            minHeap.push(a+b);
        }
    }
    return cost;
}

int main(){
    vector<int> v{4,3,2,6};
    cout << mergingRopes(v) << endl;
    return 0;
}