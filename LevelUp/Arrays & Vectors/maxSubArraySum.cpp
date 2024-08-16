#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> nums){
    int largest = INT_MIN;
    int sum = INT_MIN;
    for(int i=0; i<nums.size();i++){
        sum = (sum + nums[i]) > nums[i] ? (sum + nums[i]) : nums[i];
        largest = max(sum,largest); 
    }
    return largest;
}

int main(){
    vector<int> v{-1,2,3,4,-2,6,-8,3};
    cout << maxSubArraySum(v) << endl;
    return 0;
}