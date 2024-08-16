#include<bits/stdc++.h>
using namespace std;

int minArrayJump(vector<int> nums, int idx, vector<int> &dp){
    if(idx == nums.size() - 1){
        return 0;
    }
    if(idx >= nums.size()){
        return INT_MAX;
    }
    int ans = INT_MAX;
    for(int i = 1; i <= nums[idx]; i++){
        int subAns;
        if(dp[idx + i] != -1){
            subAns = dp[idx + i];
        }else{
            subAns = minArrayJump(nums, idx + 1, dp);
        }
        ans = min(ans,subAns + 1);
    }
    return dp[idx] = ans;
}

int main(){
    vector<int> dp(13,-1);
    vector<int> v{3,4,2,1,2,3,7,1,1,1,2,5};
    cout << minArrayJump(v,0,dp) << endl;
    return 0;
}