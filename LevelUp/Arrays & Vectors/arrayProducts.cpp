#include<bits/stdc++.h>
using namespace std;

vector<int> arrayProducts(vector<int> v){
    int n = v.size();
    vector<int> prod(n,1);
    for(int i=1; i<n; i++){
        prod[i] = prod[i-1] * v[i-1];
    }

    int temp = 1;
    for(int i=n-1; i>=0; i--){
        prod[i] *= temp;
        temp *= v[i];
    }
    return prod;
}

int main(){
    vector<int> v{1,2,3,4,5};
    v = arrayProducts(v);
    for(int x:v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}