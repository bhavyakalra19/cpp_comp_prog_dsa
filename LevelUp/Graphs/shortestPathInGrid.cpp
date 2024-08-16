#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int x;
        int y;
        int d;

        Node(int x, int y, int d){
            this->x = x;
            this->y = y;
            this->d = d;
        }
};

class Compare{
    public:
        bool operator()(Node a, Node b){
            return a.d <= b.d;
        }
};

int shortestGridPath(vector<vector<int>> nums){
    int m = nums.size();
    int n = nums[0].size();

    vector<vector<int>> dist(m+1, vector<int>(n+1,INT_MAX));
    set<Node,Compare> s;
    s.insert(Node(0,0,nums[0][0]));
    dist[0][0] = nums[0][0];

    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    while(!s.empty()){
        auto it = s.begin();
        s.erase(it);
        int cx = it->x;
        int cy = it->y;
        int cd = it->d;

        for(int k = 0; k < 4; k++){
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && cd + nums[nx][ny] < dist[nx][ny]){
                auto fn = s.find(Node(nx,ny,dist[nx][ny]));
                if(fn != s.end()){
                    s.erase(fn);
                }
                s.insert(Node(nx,ny,cd + nums[nx][ny]));
                dist[nx][ny] = cd + nums[nx][ny];
            }
        }
    }
    return dist[m-1][n-1];
}

int main(){
    vector<vector<int>> v{{31,100,65,12,18},{10,13,47,157,6},{100,113,174,11,33},{88,124,41,20,140},{99,32,111,41,20}};
    cout << shortestGridPath(v) << endl;
    return 0;
}