#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> v){
    int actualSum = 0, sum =0;
    int n = v[v.size()-1] - v[0] + 1;
    actualSum = (n*(2*v[0] + (n-1)))/2;

    for(int i = 0; i < v.size(); i++){
        sum+= v[i];
    }
    return actualSum - sum;
}

int main(){
    vector<int> v1 ={1,2,3,4,5,6,8,9};
    int a = findElement(v1);
    cout << a << endl;
    return 0;
}