#include<bits/stdc++.h>
using namespace std;

void bfsGraphs(vector<vector<int>> v){
    int n = v.size();
    vector<int> visited(n,0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int a = q.front();
        cout << a << " ";
        q.pop();
        for(int i = 1; i < n; i++){
            if(v[a][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main(){
    vector<vector<int>> v{{0,0,0,0,0,0,0,0},{0,0,1,1,1,0,0,0},{0,1,0,1,0,0,0,0},{0,1,1,0,1,1,0,0},{0,1,0,1,0,1,0,0},{0,0,0,1,1,0,1,1},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,0}};
    bfsGraphs(v);
    return 0;
}