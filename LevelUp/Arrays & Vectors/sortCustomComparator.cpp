#include<bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(vector<int>& arr) {
    // Your code here
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    vector<pair<int,int>> pq;
    // priority_queue<pair<int,int>, vector<pair<int,int>>, CompareFunc> pq;
    for(int i = 0; i < n; i++){
        pq.push_back({mp[arr[i]],arr[i]});
    }
    sort(pq.begin(),pq.end(),[](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
        return a.second < b.second;
    }
        return a.first > b.first;
    });

    for(int i = 0; i < n; i++){
        arr[i] = pq[i].second;
    }
    
    return arr;
}

int main(){
    vector<int> arr{2,2,4,5,6,1,5,2};
    arr = sortByFreq(arr);
    for(auto a : arr){
        cout << a << " ";
    }
    cout << endl;
}