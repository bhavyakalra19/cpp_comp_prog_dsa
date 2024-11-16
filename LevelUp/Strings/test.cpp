#include<bits/stdc++.h>
using namespace std;

vector<int> getKmp(string s){
    int n = s.size();
    vector<int> check;
    check.push_back(0);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(1){
            if(s[i] == s[j]){
                check.push_back(++j);
                break;
            }else{
                if(j == 0){
                    break;
                }
                j = check[j-1];
            }
        }
    }
    return check;
}

int getAns(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> check;
    check = getKmp(s2);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(1){
            if(s1[i] == s2[j]){
                j++;
                break;
            }else{
                if(j == 0){
                    break;
                }
                j = check[j-1];
            }
        }
        if(j == m){
            return i - j + 1;
        }
    }
    return -1;
}

int main(){
    string s1 = "abcabcdabc";
    string s2 = "abcdabc";
    cout << getAns(s1,s2) << endl;
    return 0;
}