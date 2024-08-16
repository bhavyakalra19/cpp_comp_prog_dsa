#include<bits/stdc++.h>
using namespace std;

void dfsGraphs(vector<vector<int>> v, vector<int> &visited, int index){
    cout << index << " ";
    for(int i = 1; i < v.size(); i++){
        if(v[index][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            dfsGraphs(v,visited,i);
        }
    }
}

int main(){
    vector<vector<int>> v{{0,0,0,0,0,0,0,0},{0,0,1,1,1,0,0,0},{0,1,0,1,0,0,0,0},{0,1,1,0,1,1,0,0},{0,1,0,1,0,1,0,0},{0,0,0,1,1,0,1,1},{0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,0}};
    vector<int> visited(8,0);
    visited[1] = 1;
    dfsGraphs(v,visited,1);
    cout << endl;
    return 0;
}