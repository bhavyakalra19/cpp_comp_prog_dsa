#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int i = 0;
        int diff = 0;
        int sumMax = 0;
        while(j < n){
            if(nums[i] != nums[j]){
                if(diff != 0){
                    sumMax = max(min(diff, j - i),sumMax);
                    diff = 0;
                }else{
                    diff = j - i;
                }
                i = j;
            }
            j++;
        }
        if(diff != 0){
            sumMax = min(diff, j - i);
        }
        return sumMax*2;
    }
};

int main(){
    Solution s;
    vector<int> v{0,0,0,1,1,1,0,1,0};
    cout << s.findMaxLength(v) << endl;
    return 0;
}