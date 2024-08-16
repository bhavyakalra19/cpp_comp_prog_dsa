#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> housing(vector<int> nums, int k){
    vector<pair<int,int>> v;
    int i = 0;
    int j = 0;
    int sum  = 0;
    int n = nums.size();
    while(j < n){
        sum += nums[j++];
        while(sum > k && i < j){
            sum -= nums[i++];
        }
        if(sum == k){
            v.push_back(make_pair(i,j-1));
        }
    }
    return v;
}

int main(){
    vector<int> v{1,3,2,1,4,1,3,2,1,1,2};
    vector<pair<int,int>> z;
    z = housing(v,8);
    for(auto x : z){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}