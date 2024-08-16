#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums, int k){
    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k){
            return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}
int main(){
    vector<int> v{1,0,1,1};
    if(containsDuplicate(v,1)){
        cout << "The Result Is Passed" << endl;
    }
    return 0;
}