#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canHandle(vector<int> m, string word){
        for(char c : word){
            if(m[c - 'a'] == 0){
                return false;
            }
            m[c - 'a'] -= 1;
        }
        return true;
    }

    int getMax(vector<string> words, vector<int> score, int idx,vector<int> mp){
        if(idx == words.size()){
            return 0;
        }
        int notTaken = getMax(words,score,idx+1,mp);
        int taken = 0;
        if(canHandle(mp,words[idx])){
            int currScore = 0;
            for(char c : words[idx]){
                mp[c - 'a'] -= 1;
                currScore += score[c - 'a'];
            }
            taken = currScore + getMax(words,score,idx+1,mp);
            for(char c : words[idx]){
                mp[c - 'a'] += 1;
            }
        }
        return max(taken,notTaken);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26,0);
        for(auto c : letters){
            mp[c - 'a']++;
        }
        return getMax(words,score,0,mp);
    }
};


int main(){
    vector<string> words{"azb","ax","awb","ayb","bpppp"};
    vector<int> score{10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,3,2,3,3};
    vector<char> letters{'z','a','w','x','y','b','p','p','p'};
    Solution s;
    cout << s. maxScoreWords(words,letters,score) << endl;
    return 0;
}