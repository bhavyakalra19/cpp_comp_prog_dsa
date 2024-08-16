#include<bits/stdc++.h>
using namespace std;

bool checkRow(vector<vector<char>> v, char ch, int row){
    for(int i=0; i < 9; i++){
        if(v[row][i] == ch){
            return false;
        }
    }
    return true;
}

bool checkColoumn(vector<vector<char>> v, char ch, int col){
    for(int i=0; i < 9; i++){
        if(v[i][col] == ch){
            return false;
        }
    }
    return true;
}

bool checkMatrix(vector<vector<char>> v, char ch, int row, int col){
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i < startRow+3; i++){
        for(int j = startCol; j< startCol+3; j++){
            if(v[i][j] == ch){
                return false;
            }
        }
    }
    return true;
}

bool checkSolution(vector<vector<char>> &v){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(v[i][j] == '.'){
                return false;
            }
        }
    }
    return true;
}

void solution(vector<vector<char>> &v){
    vector<int> check;
    for(int i = 0; i < 9; i++){
        for(int j =0; j< 9; j++){
            if(v[i][j] == '.'){
                for(int k = 49; k<58; k++){
                    if(checkMatrix(v,char(k),i,j) && checkRow(v,char(k),i) && checkColoumn(v,char(k),j)){
                        check.push_back(k);
                    }
                }
                if(check.size() == 1){
                    v[i][j] = char(check[0]);
                }
                check.clear();
            }
        }
    }
    if(!checkSolution(v)){
        solution(v);
    }else{
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << v[i][j] << "|";
            }
            cout << endl;
        }
    }
}

int main(){
    vector<vector<char>> v = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solution(v);
    return 0;
}