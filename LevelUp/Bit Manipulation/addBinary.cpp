#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length() - 1;
        int n2 = b.length() - 1;
        int carry = 0;
        string ans;
        while(n1 >= 0 || n2 >= 0 || carry == 1){
            if(n1 >= 0){
                carry += (a[n1--] - '0');
            }
            if(n2 >= 0){
                carry += (b[n2--] - '0');
            }
            ans += (carry % 2) + '0';
            carry = carry/2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};


int main(){
    Solution s;
    cout << s.addBinary("11","1") << endl;
    return 0;
}