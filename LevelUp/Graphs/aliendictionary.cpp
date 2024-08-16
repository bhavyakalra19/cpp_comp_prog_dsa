#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<char,vector<char>> mp;
        vector<int> inDegree;

        void addEdge(char x, char y){
            mp[x].push_back(y);
            inDegree[y - 'a'] += 1;
        }

        void alienDictionary(vector<string> v){
            inDegree.resize(26,0);
            queue<char> q;
            for(int i = 0; i < v.size() - 1; i++){
                int mx = min(v[i].size(),v[i+1].size());
                for(int j = 0; j < mx; j++){
                    if(v[i][j] != v[i+1][j]){
                        addEdge(v[i][j],v[i+1][j]);
                        break;
                    }
                }
            }

            for(auto mpPair : mp){
                if(inDegree[mpPair.first - 'a'] == 0){
                    q.push(mpPair.first);
                }
            }
            while(!q.empty()){
                char idx = q.front();
                q.pop();
                cout << idx << " ";
                for(auto dir : mp[idx]){
                    inDegree[dir - 'a'] -= 1;
                    if(inDegree[dir - 'a'] == 0){
                        q.push(dir);
                    }
                }
            }
            cout << endl;
        }
};

int main(){
    vector<string> v{"caa","aaa","aab"};
    Graph g;
    g.alienDictionary(v);
    return 0;
}