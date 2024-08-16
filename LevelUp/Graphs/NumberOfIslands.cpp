#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> grid, vector<vector<bool>> &visited, int i, int j, int m, int n){
        queue<pair<int,int>> q;
        q.push({i,j});
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = p.first + dx[k];
                int ny = p.second + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == '1'){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid,visited,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<char>> v{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'1','0','0','1','1'}};
    Solution s;
    cout << s.numIslands(v) << endl;
    return 0;
}
