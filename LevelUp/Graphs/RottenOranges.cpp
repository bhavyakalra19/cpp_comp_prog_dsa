#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int x;
        int y;
        int w;

        Node(int x, int y, int w){
            this->x = x;
            this->y = y;
            this->w = w;
        }
};

class Solution {
public:
    int dfs(queue<Node> q, vector<vector<int>> &grid, int m, int n){
        int largest = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            Node it = q.front();
            q.pop();
            int cx = it.x;
            int cy = it.y;
            
            if(it.w > largest){
                largest = it.w;
            }
            for(int k = 0; k < 4; k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push(Node(nx,ny,it.w + 1));
                }
            }
        }
        return largest;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<Node> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push(Node(i,j,0));
                }
            }
        }
        int largest = dfs(q,grid,m,n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return largest;
    }
};

int main(){
    vector<vector<int>> v{{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout << s.orangesRotting(v) << endl;
    return 0;
}