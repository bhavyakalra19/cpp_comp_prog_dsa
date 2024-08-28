#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> check(26,-1);
        for(int i = 0; i < N - 1; i++){
            int j = 0;
            while(j < dict[i].size() && j < dict[i+1].size()){
                if(dict[i][j] != dict[i+1][j]){
                    if(check[dict[i][j]] == -1){
                        check[dict[i][j]] = 0;
                    }
                    check[dict[i+1][j]] == 1;
                }
            }
        }
    }
};