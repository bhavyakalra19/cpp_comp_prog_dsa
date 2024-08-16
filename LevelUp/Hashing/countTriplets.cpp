#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> nums, int r){
    int n = nums.size();
    unordered_map<int,int> left,right;
    int ans = 0;
    for(int i = 0; i < n; i++){
        right[nums[i]]++;
        left[nums[i]] = 0;
    }

    for(int i = 0; i < n; i++){
        right[nums[i]]--;
        if((nums[i] % r) == 0){
            int a = left[nums[i]/r];
            int b = right[nums[i]*r];
            ans += (a*b);
        }
        left[nums[i]]++;
    }
    return ans;
}

int main(){
    vector<int> v{4,3,4,8,16,15,16};
    cout << countTriplets(v,2) << endl;
    return 0;
}