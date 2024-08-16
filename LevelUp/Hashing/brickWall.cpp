#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int count  = 0;
        int high = 0;
        int secondHigh = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < wall[i].size(); j++){
                sum += wall[i][j];
                mp[sum]++;
            }
            high = sum;
        }
        for(auto m : mp){
            if(secondHigh < m.second && m.first != high){
                secondHigh = m.second; 
            }
        }
        return n - secondHigh;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v{{1},{1},{1}};
    cout << s.leastBricks(v) << endl;
    return 0;
}
