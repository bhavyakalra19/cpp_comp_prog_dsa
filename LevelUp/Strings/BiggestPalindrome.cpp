#include<bits/stdc++.h>
using namespace std;

string getPalindrome(string s, int i, int j){
    while(i>=0 && j < s.length() && s[i] == s[j]){
        i--;
        j++;
    }
    return s.substr(i+1,j-i-1);
}

string biggestPalindrome(string s){
    if(s.length() == 1){
        return s;
    }
    string odd,even,ans;
    for(int i=0; i < s.length(); i++){
        odd = getPalindrome(s,i,i);
        even = getPalindrome(s,i,i+1);
        ans = ans.length() < odd.length() ? odd : ans;
        ans = ans.length() < even.length() ? even : ans;
    }
    return ans;
}

int main(){
    cout << biggestPalindrome("xabbaxs") << endl;
    return 0;
}