#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void changeRow(vector<vector<int>> &grid, int row, int n){
        for(int i = 0; i < n; i++){
            grid[row][i] = grid[row][i] ^ 1;
        }
    }

    void changeCol(vector<vector<int>> &grid, int col, int m){
        for(int i = 0; i < m; i++){
            grid[i][col] = grid[i][col] ^ 1;
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int bc;
        int ac;
        int ans = 0;
        int p;
        for(int i = 0; i < m ; i++){
            bc = 0;
            ac = 0;
            p = 1;
            for(int j = n - 1; j >= 0; j--){
                bc += grid[i][j] * p;
                ac += (grid[i][j] ^ 1) * p;
                p = p << 1;
            }
            if(ac > bc){
                changeRow(grid,i,n);
            }
        }

        for(int j = 0; j < n ; j++){
            bc = 0;
            ac = 0;
            for(int i = 0; i < m; i++){
                bc += grid[i][j];
                ac += (grid[i][j] ^ 1);
            }
            if(ac > bc){
                changeCol(grid,j,m);
            }
        }
        for(int i = 0; i < m; i++){
            p = 1;
            for(int j = n - 1; j >= 0; j--){
                cout << grid[i][j] << " ";
                ans += grid[i][j] * p;
                p = p << 1;
            }
            cout << endl;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid{{0,1},{1,1}};
    Solution s;
    cout << s.matrixScore(grid) << endl;
    return 0;
}