#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> left;
        vector<int> right;
        int t = 0;
        int rt = 0;
        for(int i = 0; i < n; i++){
            left.push_back(t);
            right.push_back(rt);
            t ^= arr[i];
            rt ^= arr[n - i - 1];
        }
        reverse(right.begin(),right.end());
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(t ^ left[queries[i][0]] ^ right[queries[i][1]]);
        }
        return ans;
    }
};

int main(){
    vector<int> arr{1,3,4,8};
    vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
    Solution s;
    vector<int> ans = s.xorQueries(arr,queries);
    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}