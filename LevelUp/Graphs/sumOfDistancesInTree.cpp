#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    list<int> *l;
    int srcAns = 0;
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    int dfs(int src, vector<int> &subtree, int level, int p){
        srcAns += level;
        int ans = 1;
        for(auto x : l[src]){
            if(x != p){
                ans += dfs(x,subtree,level + 1,src);
            }
        }
        return subtree[src] = ans;
    }

    void dfs(int p, vector<int> subtree, vector<int> &count, int n, int par){
        for(auto x : l[p]){
            if(x != par){
                count[x] = count[p] - 2 * subtree[x] + n;
                dfs(x,subtree,count,n,p);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        l = new list<int>[n];
        vector<int> ansCount(n,0);
        vector<int> subtree(n,0);
        for(int i = 0; i < edges.size(); i++){
            addEdge(edges[i][0],edges[i][1]);
        }
        dfs(0,subtree,0,0);
        ansCount[0] = srcAns;
        dfs(0,subtree,ansCount,n,0);
        return ansCount;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v{{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> ans = s.sumOfDistancesInTree(6,v);
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}