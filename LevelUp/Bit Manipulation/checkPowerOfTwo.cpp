#include<bits/stdc++.h>
using namespace std;

bool PowerOfTwo(int n){
    return (n & (n-1)) == 0 ? 1 : 0;
}

int main(){
    if(PowerOfTwo(4)){
        cout << "It is power of 2" << endl;
    }
    if(!PowerOfTwo(5)){
        cout << "It is not a power of two" << endl;
    }
    return 0;
}
