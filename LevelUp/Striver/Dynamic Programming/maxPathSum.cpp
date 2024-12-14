// https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
using namespace std;

// int getAns(vector<vector<int>> &matrix, int i, int j, int &n, int &m, vector<vector<int>> &dp){
//     if(j < 0 || j >= m){
//         return INT_MIN;
//     }
//     if(i == n - 1){
//         return matrix[i][j];
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int a = getAns(matrix,i+1,j-1,n,m,dp);
//     int b = getAns(matrix,i+1,j,n,m,dp);
//     int c = getAns(matrix,i+1,j+1,n,m,dp);
//     return dp[i][j] = matrix[i][j] + max(a,max(b,c));
// }

int getMaxPathSum(vector<vector<int>> &matrix){
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // int mx = INT_MIN;
    // for(int i = 0; i < m; i++){
    //     mx = max(mx, getAns(matrix,0,i,n,m,dp));
    // }
    // return mx;

    vector<int> prev = matrix[0];
    for(int i = 1; i < n; i++){
        vector<int> curr(m,0)
        for(int j = 0; j < m; j++){
            int a = j > 0 ? prev[j-1] : INT_MIN;
            int b = prev[j];
            int c = j < m - 1 ? prev[j+1] : INT_MIN;
            curr[j] = matrix[i][j] + max(a,max(b,c));
        }
        prev = curr;
    }
    return *max_element(prev.begin(), prev.end());
}