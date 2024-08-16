#include<bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequence(vector<int> nums){
    int n = nums.size();
        int mx = 0;
        if(n == 0 || n == 1){
            return n;
        }
        vector<int> dp(n,1);
        for(int i = 1; i < n; i++){
            int ans = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && ans < dp[j]){
                    ans = dp[j];
                }
            }
            dp[i] = ans + 1;
            mx = max(mx,ans + 1); 
        }
        return mx;
}

int main(){
    vector<int> v{50,4,8,12,30,100};
    cout << LongestIncreasingSubsequence(v) << endl;
    return 0;
}