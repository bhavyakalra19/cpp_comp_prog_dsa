#include<bits/stdc++.h>
using namespace std;

void findMultipleElement(vector<int> v){
    sort(v.begin(),v.end());
    int arrSize = v[v.size()-1] - v[0] + 1;
    int *a  = new int[arrSize];
    for(int i = 0; i < v.size(); i++){
        a[v[i]-v[0]] = 1;
    }

    for(int i =0; i < arrSize;i++){
        if(a[i] != 1){
            cout << i + v[0] << " ";
        }
    }
    cout << endl;
}

void display(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v1 ={8,9,11,12,13,14,16,17,19,21,25,1,2,3,4,5,6};
    findMultipleElement(v1);
    return 0;
}