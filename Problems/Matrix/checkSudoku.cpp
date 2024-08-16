#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char>> &board){
        unordered_map<char, int> mRow;
        unordered_map<char, int> mCol;
        unordered_map<char, int> mMat;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                //checking row
                if (mRow[board[i][j]] && board[i][j] != '.'){
                    return false;
                }else if(board[i][j] != '.'){
                    mRow[board[i][j]] = 1;
                }
                //checking coloumn
                if (mCol[board[j][i]] && board[j][i] != '.'){
                    return false;
                }else if(board[j][i] != '.'){
                    mCol[board[j][i]] = 1;
                }
                //checking matrix
                if (board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] != '.' && mMat[board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]]){
                    return false;
                }else if(board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] != '.'){
                    mMat[board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3]] = 1;
                }
            }
            mMat.clear();
            mRow.clear();
            mCol.clear();
        }
        return true;
    }
};

int main(){
    vector<vector<char>> v = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    if(s.isValidSudoku(v)){
        cout << "hello" << endl;
    }
    return 0;
}