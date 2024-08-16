#include<bits/stdc++.h>
using namespace std;

int adjacentSum(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for(int i = 2; i < n; i++){
        int inc = nums[i] + dp[i-2];
        int exc = dp[i-1];
        dp[i] = max(inc,exc);
    }
    return dp[n-1];
}

int main(){
    vector<int> v{6,10,12,7,9,14};
    cout << adjacentSum(v) << endl;
    return 0;
}