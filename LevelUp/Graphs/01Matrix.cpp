#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(queue<pair<int,int>> &q, vector<vector<int>> &mat, int m, int n){
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cx = it.first;
            int cy = it.second;
            for(int k = 0; k < 4; k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == -1){
                    mat[nx][ny] = mat[cx][cy] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }
        dfs(q,mat,m,n);
        return mat;
    }
};

int main(){
    vector<vector<int>> v{{0,0,0},{0,1,0},{1,1,1}};
    Solution s;
    v = s.updateMatrix(v);
    for(auto a : v){
        for(auto b : a){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}