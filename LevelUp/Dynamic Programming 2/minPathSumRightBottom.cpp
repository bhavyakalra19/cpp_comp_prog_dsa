#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMin(vector<vector<int>> grid, vector<vector<bool>> &visited, int x, int y, int m, int n){
        if(x == m - 1 && y == n - 1){
            return grid[x][y];
        }
        visited[x][y] = true;
        int dx[] = {0,1};
        int dy[] = {1,0};
        int ans = INT_MAX;
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < m && ny < n && !visited[nx][ny]){
                int sum = grid[x][y] + getMin(grid,visited,nx,ny,m,n);
                ans = min(ans,sum);
            }
        }
        visited[x][y] = false;
        return ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return getMin(grid,visited,0,0,m,n);
    }
};

int main(){
    vector<vector<int>> v{{1,3,1},{1,5,1},{4,1,1}};
    Solution s;
    cout << s.minPathSum(v) << endl;
    return 0;
}