#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for(int i=0; i<n-2; i++){
        int j = i+1;
        int k = n-1;
        while(j < k){
            int current_sum = nums[i];
            current_sum += nums[j];
            current_sum += nums[k];

            if(current_sum == 0){
                result.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }else if(current_sum>0){
                k--;
            }else{
                j++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> v{-1,0,1,2,-1,4};
    vector<vector<int>> res;
    res = threeSum(v);
    for(int i=0;i<res.size()-1;i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}