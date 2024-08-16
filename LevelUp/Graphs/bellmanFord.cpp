#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V;
        list<pair<int,int>> *l;

        Graph(int V){
            this->V = V;
            l = new list<pair<int,int>>[V];
        }

        void addEdge(int x, int y, int w){
            l[x].push_back({y,w});
        }

        void bellmanFord(){
            vector<int> dist(V,INT_MAX);
            dist[0] = 0;
            for(int i = 0; i < V - 1; i++){
                for(int j = 0; j < V; j++){
                    for(auto lp : l[j]){
                        int src = j;
                        int dest = lp.first;
                        int nw = lp.second;
                        if(dist[src] != INT_MAX && dist[src] + nw < dist[dest]){
                            dist[dest] = dist[src] + nw;
                        }
                    }
                }
            }

            for(int i = 0; i < V - 1; i++){
                for(int j = 0; j < V; j++){
                    for(auto lp : l[j]){
                        int src = j;
                        int dest = lp.first;
                        int nw = lp.second;
                        if(dist[src] != INT_MAX && dist[src] + nw < dist[dest]){
                            cout << "The Graph contains cycle" << endl;
                        }
                    }
                }
            }

            for(int i = 0; i < V; i++){
                cout << dist[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(0,2,1);
    g.addEdge(2,3,2);
    g.addEdge(1,2,-4);
    g.addEdge(3,1,4);
    g.bellmanFord();
    return 0;
}