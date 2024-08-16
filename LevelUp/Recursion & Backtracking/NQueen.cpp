#include<bits/stdc++.h>
using namespace std;

void printSolution(int board[][20], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkPosition(int board[][20], int n, int x, int y){
    for(int k = 0; k < x; k++){
        if(board[k][y] == 1){
            return false;
        }
    }

    int i = x;
    int j = y;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    i = x;
    j = y;
    while(i >= 0 && j < n){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void solveNQueen(int board[][20], int n, int i){
    if(i == n){
        printSolution(board,n);
        cout << endl;
        return;
    }
    
    for(int j = 0; j < n; j++){
        if(checkPosition(board,n,i,j)){
            board[i][j] = 1;
            solveNQueen(board,n,i+1);
            // if(cond){
            //     return true;
            // }
            board[i][j] = 0;
        }
    }
}

int main(){
    int board[20][20] = {0};
    solveNQueen(board,5,0);
    return 0;
}