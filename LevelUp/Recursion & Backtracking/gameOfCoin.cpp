#include <bits/stdc++.h>
using namespace std;

int maxResult(int i, int j, vector<int> v, bool a, int sum){
    if(i > j){
        return sum;
    }
    if(a){
        if(v[i] > v[j]){
            i++;
        }else{
            j--;
        }
        return maxResult(i,j,v,false,sum);
    }
    return max(maxResult(i+1,j,v,true,v[i]+sum),maxResult(i,j-1,v,true,v[j]+sum));
}

int MaxValue(int n, vector<int> v){
//Write your code here. Do not modify the function or parameters. You can use a helper function if needed.
    if(n < 1){
        return 0;
    }
    return maxResult(0,n-1,v,false,0);
}

int main(){
    vector<int> v{8,15,3,7};
    cout << MaxValue(4,v) << endl;
    return 0;
}