#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> nums, int target, int idx){
    if(target == 0){
        return 1;
    }
    int subAns = 0;
    for(int i = idx; i < nums.size(); i++){
        if(target - nums[i] >= 0){
            subAns += coinChange(nums,target - nums[i],i);
        }
    }
    return subAns;
}

int main(){
    vector<int> v{1,3,7,10};
    cout << coinChange(v,15,0) << endl;
    return 0;
}