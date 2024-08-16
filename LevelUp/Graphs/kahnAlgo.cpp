#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V;
        list<int> *l;
        int *inDegree;

        Graph(int V){
            this->V = V;
            inDegree = new int[V]{0};
            l = new list<int>[V];
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
            inDegree[y] += 1;
        }

        vector<int> kahnAlgo(){
            vector<int> ans;
            queue<int> q;
            for(int i = 0; i < V; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                ans.push_back(it);
                for(int lp : l[it]){
                    inDegree[lp]--;
                    if(inDegree[lp] == 0){
                        q.push(lp);
                    }
                }
            }
            return ans;
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(4,3);
    vector<int> v = g.kahnAlgo();
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}