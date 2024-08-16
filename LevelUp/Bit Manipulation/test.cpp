#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i <= 20; i++){
            int xorValue = 0;
            for(auto x : nums){
                xorValue ^= (1<<i) & x;
            }
            int kXorvalue = (1<<i) & k;
            if(kXorvalue != xorValue){
                ans += 1;
            }
        }
        return ans;      
    }
};

int main(){
    Solution s;
    vector<int> v{2,1,3,4};
    cout << s.minOperations(v,1) << endl;
    return 0;
}