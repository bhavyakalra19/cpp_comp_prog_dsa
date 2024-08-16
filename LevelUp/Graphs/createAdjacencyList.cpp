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
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.printGraph();
    return 0;
}
