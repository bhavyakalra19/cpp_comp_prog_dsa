#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int width = 0;
        string s;
        int count = 0;
        int extraSpace;
        vector<string> ans;
        int spaceLen;
        for(int i = 0; i < n;){
            width = 0;
            count = 0;
            s = "";
            vector<int> line;
            while((width + words[i].size()) <= maxWidth){
                width += words[i].size() + 1;
                line.push_back(i);
                i++;
            }
            int ls = line.size();
            width -= ls;
            if(i == n){
                for(int j = 0; j < ls; j++){
                    s += words[line[j]];
                    s += " "; 
                }
                if(s.size() > maxWidth){
                    s.pop_back();
                }
                while(s.size() != maxWidth){
                    s += " ";
                }
            }else{
                spaceLen = maxWidth - width;
                extraSpace = (ls == 1 ? 0 : spaceLen % (ls - 1));
                for(int j = 0; j < ls; j++){
                    int space =  ls == 1 ? spaceLen : spaceLen / (ls - 1);
                    if(extraSpace > 0){
                        space += 1;
                        extraSpace -= 1;
                    }
                    s += words[line[j]];
                    while(space > 0 && (j != (ls - 1) || ls == 1)){
                        s += " ";
                        space -= 1;
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};

int main(){
    vector<string> words{"a"};
    Solution s;
    words = s.fullJustify(words,1);
    for(auto c : words){
        cout << c << endl;
    }
    return 0;
}