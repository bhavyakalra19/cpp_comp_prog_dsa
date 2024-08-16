#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   void combination(vector<int> nums, int t, int index, vector<vector<int>> &v, vector<int> s){
        if(t == 0){
            v.push_back(s);
            return;
        }
        if(t < 0){
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(nums[i] > t){
                break;
            }
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            s.push_back(nums[i]);
            combination(nums,t - nums[i], i+1, v, s);
            s.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> s;
        sort(candidates.begin(),candidates.end());
        combination(candidates,target,0,v,s);
        return v;
    }
};

int main(){
    vector<int> v{10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int>> ans;
    ans = s.combinationSum2(v,8);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}