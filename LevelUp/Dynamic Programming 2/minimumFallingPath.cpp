#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMin(vector<vector<int>> grid, vector<vector<int>> &dp, int x, int y, int n){
        if(x == n){
            return 0;
        }
        if(dp[x][y] != 0){
            return dp[x][y];
        }
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i != y){
                int ans = grid[x][i] + getMin(grid,dp,x+1,i,n);
                 mn = min(mn,ans);
            }
           
        }
        return dp[x][y] = mn;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[0][i] = grid[0][i] + getMin(grid,dp,1,i,n);
        }
        for(int i = 0; i < n; i++){
            mn = min(mn,dp[0][i]);
        }
        return mn;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9}};
    cout << s.minFallingPathSum(grid) << endl;
    return 0;
}