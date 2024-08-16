#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

int main(){
    Solution s;
    vector<string> v{"flow", "flew", "flight","float"};
    cout << s.longestCommonPrefix(v) << endl;
    return 0;
}