#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void getKmp(string s, vector<int> &check){
            int n = s.size();
            int j = 0;
            check.push_back(0);
            for(int i = 1; i < n; i++){
                while(1){
                    if(s[i] == s[j]){
                        check.push_back(++j);
                        break;
                    }else{
                        if(j == 0){
                            check.push_back(0);
                            break;
                        }
                        j = check[j-1];
                    }
                }
            }
        }

        vector<int> kmpAlgo(string s1, string s2){
            int n = s1.size();
            int m = s2.size();
            vector<int> check;
            getKmp(s2,check);
            vector<int> ans;
            int j = 0;
            for(int i = 0; i < n; i++){
                while(1){
                    if(s1[i] == s2[j]){
                        j++;
                        break;
                    }else{
                        if(j == 0){
                            break;
                        }
                        j = check[j-1];
                    }
                }
                if(j == m){
                    ans.push_back(i - j + 1);
                    j = check[m-1];
                }
            }
            return ans;
        }
};

int main(){
    Solution s;
    string s1 = "abcabcabc";
    string s2 = "abcabc";
    vector<int> ans;
    ans = s.kmpAlgo(s1,s2);
    for(auto a : ans){
        cout << a << endl;
    }
    return 0;
}