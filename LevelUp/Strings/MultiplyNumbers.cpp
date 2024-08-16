#include<bits/stdc++.h>
using namespace std;

string multiplyNumbers(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 == 0 || n2 == 0){
        return "0";
    }
    vector<int> result(n1 + n2,0);

    int x = 0;
    for(int i = n1-1; i >= 0; i--){
        int carry = 0;
        int num1  = s1[i] - '0';
        int y = 0;
        for(int j = n2 - 1; j >= 0; j--){
            int num2 = s2[j] - '0';
            int sum = (num1 * num2) + result[x + y] + carry;
            carry = sum/10;
            result[x+y] = sum % 10;
            y++;
        }
        if(carry>0){
            result[x+y] = carry;
        }
        x++;
    }

    int i = n1 + n2 - 1;
    while(i >= 0 && result[i] == 0){
        i--;
    }
    if(i==-1){
        return "0";
    }
    string s = "";
    for(int j = i; j>=0; j--){
        s += to_string(result[j]);
    }
    return s;
}

int main(){
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    cout << multiplyNumbers(str1,str2) << endl;
    return 0; 
}