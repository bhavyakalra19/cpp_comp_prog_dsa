#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() == 0){
            return s;
        }
       string a = s;
        int n = (numRows * 2) - 2;
        int l = 0;
        int x = n;
        for(int i = 0; i < numRows; i++){
            int j = 0;
            while(j + i < s.length()){
                a[l++] =  s[i + j];
                if(x%n != 0){
                    if((i+j+x) < s.length()){
                        a[l++] =  s[i + j + x];
                    }
                }
                j += n;
            }
            x -= 2;
        }
        return a; 
    }
};

int main(){
    Solution s;
    cout << s.convert("PAYPALISHIRING",4) << endl;
    return 0;
}
