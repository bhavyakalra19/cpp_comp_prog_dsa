#include<bits/stdc++.h>
using namespace std;
#define I 400

void primsAlgo(vector<vector<int>> v){
    int n = v.size();
    int mn = I;
    int t[2][n-2];
    int near[n];
    near[0] = 0;
    int k,x,y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] < mn){
                x=i;
                y=j;
                mn = v[i][j];
            }
        }
    }
    t[0][0] = x;
    t[1][0] = y;
    near[x] = 0;
    near[y] = 0;                                                                                                                                                                                                                                                                                                                                  
    for(int i = 0; i < n; i++){
        if(near[i] != 0){
            if(v[x][i] < v[y][i]){
                near[i] = x;
            }else{
                near[i] = y;
            }
        }
    }

    for(int i = 1; i < n - 2; i++){
        mn = I;
        for(int j = 1; j < n; j++){
            if(near[j] != 0 && v[j][near[j]] < mn){
                mn = v[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for(int j = 1; j < n; j++){
            if(near[j]!=0 && v[j][k] < v[j][near[k]]){
                near[j] = k;
            }
        }
    }

    for(int i = 0; i < n-2; i++){
        cout << t[0][i] << " " << t[1][i] << endl;
    }
}

int main(){
    vector<vector<int>> v{{I,I,I,I,I,I,I,I},{I,I,25,I,I,I,5,I},{I,25,I,12,I,I,I,10},{I,I,12,I,8,I,I,I},{I,I,I,8,I,16,I,14},{I,I,I,I,16,I,20,18},{I,5,I,I,I,20,I,I},{I,I,10,I,14,18,I,I}};
    primsAlgo(v);
    return 0;
}