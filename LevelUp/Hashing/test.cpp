#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cs = 0;
        int count = 0;
        int rem = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            cs += nums[i];
            int rem = cs % k;
            if(rem < 0){
                rem += k;
            }
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> v{4,5,0,-2,-3,1};
    cout << s.subarraysDivByK(v,5) << endl;
    return 0;
}