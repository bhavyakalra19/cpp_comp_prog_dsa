#include<bits/stdc++.h>
using namespace std;

bool ratMaze(vector<vector<char>> c, int n, int i, int j, vector<int> &ans, queue<int> q){
    if(i == n - 1 && j == n - 1){
        q.push((i*n) + j + 1);
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return true;
    }
    if(i == n || j == n || c[i][j] == 'X'){
        return false;
    }
    q.push((i*n) + j + 1);
    bool cond1 = ratMaze(c,n,i,j+1,ans,q);
    if(cond1 == true){
        return true;
    }
    bool cond2 = ratMaze(c,n,i+1,j,ans,q);
    if(cond2 == true){
        return true;
    }
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c){
    ////Write your code below. Do not modify this function or parameters. You can use helper function if needed. 
    vector<int> ans;
    queue<int> q;
    ratMaze(c,n,0,0,ans,q);
    return ans;
}

int main(){
    vector<vector<char>> c{{'0','0','X','0'},{'0','X','0','0'},{'0','0','0','X'},{'X','X','0','0'}};
    vector<int> v;
    v = findPath(4,c);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}