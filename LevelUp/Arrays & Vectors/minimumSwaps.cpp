#include<bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> v){
    int n = v.size();
    pair<int,int> ap[n];
    for(int i=0;i<n;i++){
        ap[i].first = v[i];
        ap[i].second = i;
    }
    sort(ap,ap+n);
    vector<bool> visited(n,false);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(visited[i] || ap[i].second == i){
            continue;
        }
        int node = i;
        int cnt = 0;
        while(!visited[node]){
            visited[node] = true;
            node = ap[node].second;
            cnt++;
        }
        ans += cnt - 1;
    }
    return ans;
}

int main(){
    vector<int> v{5,4,3,2,1};
    cout << minimumSwaps(v) << endl;
    return 0;
}