#include<bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    unordered_set<int> s;
    vector<int> result;
    for(int i=0; i < nums.size(); i++){
        if(s.find(target-nums[i])!=s.end()){
            result.push_back(target-nums[i]);
            result.push_back(nums[i]);
            return result;
        }
        s.insert(nums[i]);
    }
    return {};
}

int main(){
    vector<int> v{3,3};
    v = pairSum(v,6);
    for(int x:v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}