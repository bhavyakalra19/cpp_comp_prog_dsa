#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> ls;
        stack<int> rs;
        vector<int> nums1;
        int mx = 0;
        for(int i = 0; i < n; i++){
            while(!ls.empty() && heights[ls.top()] >= heights[i]){
                ls.pop();
            }
            if(ls.empty()){
                nums1.push_back(-1);
            }else{
                nums1.push_back(ls.top());
            }
            ls.push(i);
        }
        for(auto x : nums1){
            cout << x << " ";
        }
        cout << endl;
        for(int i = n - 1; i >= 0; i--){
            while(!rs.empty() && heights[rs.top()] >= heights[i]){
                rs.pop(); 
            }
            int low = (rs.empty() ? n : rs.top());
            cout << low << " ";
            mx = max((low - nums1[i] - 1)*heights[i],mx);
            rs.push(i);
        }
        return mx;
    }
};

int main(){
    vector<int> v{2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(v) << endl;
    return 0;
}

