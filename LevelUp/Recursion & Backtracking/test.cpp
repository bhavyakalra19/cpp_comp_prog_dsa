#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAns(int n, int idx, vector<int> v, vector<vector<int>> &nums, int k){
        if(idx > n || k == 0){
            if(k == 0){
                nums.push_back(v);
            }
            return;
        }
        for(int i = idx; i <= n; i++){
            v.push_back(i);
            getAns(n,i+1,v,nums,k-1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> nums;
        vector<int> v;
        getAns(n,1,v,nums,k);
        return nums;
    }
};

int main(){
    vector<vector<int>> nums;
    Solution s;
    nums = s.combine(4,2);
    for(auto c : nums){
        for(auto x : c){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}