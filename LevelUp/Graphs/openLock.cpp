#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findSet(string a, queue<string> &q){
        for(int i = 0; i < 4; i++){
            char c = a[i];
            a[i] = (((c - '0') + 1) % 10) + '0';
            q.push(a);
            a[i] = (((c - '0') + 9) % 10) + '0';
            q.push(a);
            a[i] = c;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> ends(deadends.begin(),deadends.end());
        queue<string> q;
        int level = 0;
        q.push("0000");
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cs = q.front();
                q.pop();
                if(cs == target){
                    return level;
                }
                if(visited.count(cs) || ends.count(cs)){
                    continue;
                }
                visited.insert(cs);
                findSet(cs,q);
            }
            level++;
        }
        return -1;
    }
};

int main(){
    vector<string> ends{"8887","8889","8878","8898","8788","8988","7888","9888"};
    Solution s;
    cout << s.openLock(ends,"8888") << endl;
    return 0;
}