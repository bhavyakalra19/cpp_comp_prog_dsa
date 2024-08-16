#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int x;
        int y;
        int high;
        Node(int x, int y, int high){
            this->x = x;
            this->y = y;
            this->high = high;
        }
};

class Compare{
    public:
        bool operator()(Node a, Node b){
            return a.high <= b.high;
        }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> dist(m, vector<bool>(n, false));
        set<Node,Compare> s;
        s.insert(Node(0,0,grid[0][0]));
        dist[0][0] = true;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!s.empty()){
            auto it = s.begin();
            s.erase(it);
            int cx = it->x;
            int cy = it->y;
            for(int k = 0; k < 4; k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx >=0  && nx < m && ny >= 0 && ny < n && !dist[nx][ny]){
                    int nw = (it->high > grid[nx][ny]) ? it->high : grid[nx][ny];
                    if(nx == m - 1 && ny == n - 1){
                        return nw;
                    }
                    dist[nx][ny] = true;
                    s.insert(Node(nx,ny,nw));
                }
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> v{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    Solution s;
    cout << s.swimInWater(v) << endl;
    return 0;
}