#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }

    int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    int q = 0;
    int m;
    while(dvd >= dvs){
        long temp = dvs;
        m = 1;
        while(temp << 1 <= dvd){
            temp = temp << 1;
            m = m << 1;
        }
        dvd -= temp;
        q += m;
    }
    return q*sign;
}

int main(){
    cout << divide(9,2) << endl;
    return 0;
}