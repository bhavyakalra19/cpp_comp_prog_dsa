// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int getAns(vector<int> &nums, int idx, int n, vector<int> &dp){
    //     if(idx == 0){
    //         return nums[idx];
    //     }
    //     if(idx < 0){
    //         return 0;
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }
    //     int take = nums[idx] + getAns(nums, idx - 2, n, dp);
    //     int notTake = getAns(nums, idx - 1, n, dp);
    //     return dp[idx] = max(take,notTake);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return getAns(nums, n-1, n, dp);
        int prev1 = nums[0];
        int prev2 = 0;
        int curr = nums[0];
        for(int i = 1; i < n; i++){
            curr = max(nums[i] + prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;  
    }
};

int main(){
    vector<int> arr{1,2,3,1};
    Solution s;
    cout << s.rob(arr) << endl;
    return 0;
}