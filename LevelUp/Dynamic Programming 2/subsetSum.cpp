#include<bits/stdc++.h>
using namespace std;

bool subsetProblem(vector<int> nums, int wt){
    int n = nums.size();
    vector<vector<bool>> dp(wt + 1, vector<bool>(n+1, false));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= wt; j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else if(nums[i-1] == j){
                dp[i][j] = true;
            }else{
                dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[n][wt];
}

int main(){
    vector<int> nums{2,3,7,9};
    if(subsetProblem(nums,15)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}