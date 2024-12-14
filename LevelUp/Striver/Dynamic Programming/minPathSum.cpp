// https://leetcode.com/problems/minimum-path-sum/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getAns(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0){
            return grid[m][n];
        }
        if(m < 0 || n < 0){
            return INT_MAX;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int a = getAns(grid,m-1,n,dp);
        int b = getAns(grid,m,n-1,dp);
        return dp[m][n] = grid[m][n] + min(a,b);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return getAns(grid,m-1,n-1,dp);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // we only need prev array line and curr line so why use extra space
        vector<int> prev(n,0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else{
                    int a = i > 0 ? prev[j] : INT_MAX;
                    int b = j > 0 ? curr[j-1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(a,b);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};