#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int i, int j, bool uni = true){
            l[i].push_back(j);
            if(uni){
                l[j].push_back(i);
            }
        }

        void printGraph(){
            for(int i = 0; i < V; i++){
                cout << i << "->";
                for(auto x : l[i]){
                    cout << x << ",";
                }
                cout << endl;
            }
        }

        void dfs(int source){
            int dist[V]{0};
            queue<int> q;
            int visited[V]{0};
            q.push(source);
            visited[source] = 1;
            while(!q.empty()){
                source = q.front();
                q.pop();
                cout << source << " ";
                for(int x : l[source]){
                    if(visited[x] == 0){
                        dist[x] = dist[source] + 1;
                        visited[x] = 1;
                        q.push(x);
                    }
                }
            }
            cout << endl << dist[6] << endl;
        }
};

int main(){
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.dfs(1);
    return 0;
}
