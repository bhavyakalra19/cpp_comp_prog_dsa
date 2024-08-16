#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = n - 1; i > 0; i--){
            int mn = INT_MAX;
            int smn = INT_MAX;
            int idx = -1;

            for(int j = 0; j < n; j++){
                if(grid[i][j] < mn){
                    smn = mn;
                    mn = grid[i][j];
                    idx = j; 
                }else if(grid[i][j] < smn){
                    smn = grid[i][j];
                }
            }

            for(int j = 0; j < n; j++){
                if(idx != j){
                    grid[i - 1][j] += mn;
                }else{
                    grid[i - 1][j] += smn;
                }
            }
        }
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            mn = min(mn,grid[0][i]);
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

