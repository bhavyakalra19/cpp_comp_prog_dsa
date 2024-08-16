#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i <= 20; i++){
            int xorValue = 0;
            for(auto x : nums){
                xorValue ^= (x>>i) & 1;
            }
            int kXorvalue = (k>>i) & 1;
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