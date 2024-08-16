#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int j = 0;
        int i = 1;
        int sumMax = 0;
        while(i < n){
            if(nums[i] == prev){
                if((i - j) > sumMax){
                    sumMax = i - j;
                }
                j = i;
            }
            prev = nums[i++];
        }
        if((i - j) > sumMax){
            sumMax = i - j;
        }
        return sumMax/2;
    }
};

int main(){
    Solution s;
    vector<int> v{0,1,1,0,1,0};
    cout << s.findMaxLength(v) << endl;
    return 0;
}