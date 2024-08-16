#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> v2;
        vector<vector<int>> ans;
        if(nums.size() < 3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        if(nums[0]>0){
            return ans;
        }
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i]>0){
                break;
            }
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int h = nums.size()-1;
            while(l<h){
                int current  = nums[i] + nums[l] + nums[h];
                if(current > 0){
                    h--;
                }else if(current < 0){
                    l++;
                }else{
                    v2.insert({nums[i],nums[l],nums[h]});
                    
                    while(l < h && nums[l] == nums[l+1]){
                        l++;
                    }    
                    
                    while(l < h && nums[h] == nums[h-1]){
                        h--;
                    }
                    l++;
                    h--;
                }
            }
        }
        for(auto i : v2){
            ans.push_back(i);
        }
        return ans;
    } 
};

int main(){
    Solution sl;
    vector<int> v1 = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector<vector<int>> v2;
    v2 = sl.threeSum(v1);
    for(int i = 0; i < v2.size(); i ++){
        for(int j = 0; j<v2[i].size(); j++){
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}