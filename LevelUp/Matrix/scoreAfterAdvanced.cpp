#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntZero;
        int cntOne;
        int ans = m * (1 << (n - 1));
        int p = 1;
        for(int j = n - 1; j >= 1; j--){
            cntZero = 0;
            cntOne = 0;
            for(int i = 0; i < m; i++){
                if((grid[i][j] ^ grid[i][0] ^ 1) == 0){
                    cntZero++;
                }else{
                    cntOne++;
                }
            }
            ans += max(cntZero,cntOne) * p; 
            p = p << 1;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid{{0,1},{1,1}};
    Solution s;
    cout << s.matrixScore(grid) << endl;
    return 0;
}