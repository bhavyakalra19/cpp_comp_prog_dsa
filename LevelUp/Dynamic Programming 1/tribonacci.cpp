#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMin(vector<vector<int>> grid, vector<vector<int>> $dp, int x, int y, int m, iny n){
        if(x == m-1){
            return grid[x][y];
        }
        if(dp[x][y] != 0){
            return dp[x][y];
        }
        for(int i = 0; i < n; i++){
            int mn = INT_MAX;
            for(int j = 0; j < m; j++){
                if(x > 0 && y != i){
                    int ans = grid[x][y] + getMin(grid,dp,j,i,m,n);
                    mn = min(ans,mn);
                }
            }
        }
        return dp[x][y] = mn;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(dp,0));
        getMin(grid,dp,0,0,m,n);
        for(int i = 0; i < n; i++){
            cout << dp[0][i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
    s.minFallingPathSum(v);
    return 0;
}