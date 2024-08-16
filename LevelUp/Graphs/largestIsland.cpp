#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> matrix, vector<vector<bool>> &visited, int i, int j, int m, int n){
    int cs = 1;
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    visited[i][j] = true;
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && matrix[nx][ny] == 1){
            int num = dfs(matrix,visited,nx,ny,m,n);
            cs += num;
        }
    }
    return cs;
}

int largestIsland(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int largest = 0;
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    for(int i = 0; i < m; i++){
        for(int j = 0; j< n; j++){
            if(!visited[i][j] && matrix[i][j] == 1){
                int num = dfs(matrix,visited,i,j,m,n);
                if(num > largest){
                    largest = num;
                }
            }
        }
    }
    return largest;
}

int main(){
    vector<vector<int>> v{{1,0,0,0},{1,1,0,0},{0,1,0,},{0,1,1,1}};
    cout << largestIsland(v) << endl;
    return 0;
}