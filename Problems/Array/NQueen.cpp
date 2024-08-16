#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        bool checkSolution(vector<vector<int>> &v, int row, int col){
            int i,j;
            //check uppper diagonal
            for(i = row, j = col; i>=0 && j>=0; i--, j--){
                if(v[i][j] == 1){
                    return false;
                }
            }

            //check lower diagonal
            for(i=row, j=col; i>=0 && j<v.size(); i--, j++){
                if(v[i][j] == 1){
                    return false;
                }
            }
            
            //check row
            for(i = 0; i<col; i++){
                if(v[row][i] == 1){
                    return false;
                }
            }
            return true;
        }

        bool backTrack(vector<vector<int>> &v, int col){
            if(col>=v.size()){
                return true;
            }

            for(int i=0; i<v.size();i++){
                if(checkSolution(v,i,col)){
                    v[i][col] = 1;
                    if(backTrack(v,col+1)){
                        return true;
                    }
                    v[i][col] = 0;
                }
            }

            return false;
        }

        
};

int main(){
    vector<vector<int>> v = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    Solution s;
    // if(s.checkSolution(v,0,1)){
    //     cout << "Done" << endl;
    // }else{
    //     cout << "cancelled" << endl;
    // }
    if(s.backTrack(v,0)){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }else{
            cout << "No possible answer" << endl;
    }
    return 0;
}