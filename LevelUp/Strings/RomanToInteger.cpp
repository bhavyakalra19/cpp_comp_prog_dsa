#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCharPre(char c){
        if(c == 'I'){
            return 1;
        }

        if(c == 'V'){
            return 5;
        }

        if(c == 'X'){
            return 10;
        }

        if(c == 'L'){
            return 50;
        }

        if(c == 'C'){
            return 100;
        }

        if(c == 'D'){
            return 500;
        }

        return 1000;
    }

    int romanToInt(string s) {
        if(s.length() == 0){
            return 0;
        }
        int i = s.length()-1;
        int sum = 0;
        while(i>=0){
            if(i!=0 && getCharPre(s[i]) > getCharPre(s[i-1])){
                sum += getCharPre(s[i]) - getCharPre(s[i-1]);
                i = i - 2;
            }else{
                sum += getCharPre(s[i]);
                i--;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}

