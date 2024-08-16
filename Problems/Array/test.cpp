#include<bits/stdc++.h>
using namespace std;

void display(vector<int> v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

void checkMissing(vector<int> &v){
    sort(v.begin(),v.end());
    int arrSize = v[v.size()-1]-v[0]+1;
    int *arr = new int[arrSize];
    for(int i=0;i<v.size();i++){
        arr[v[i]-v[0]] = 1;
    }
    for(int i=0; i<arrSize; i++){
        if(arr[i]!=1){
            cout << i+v[0] << " ";
        }
    }
    cout << endl;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,8,9,10,15};
    checkMissing(v);
    return 0;
}

