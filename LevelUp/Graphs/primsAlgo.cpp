#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int mnw = INT_MAX;
        int mn1;
        int mn2;
        int V;
        list<pair<int,int>> *l;
        
        Graph(int V){
            this->V = V;
            l = new list<pair<int,int>>[V];
        }

        void addEdge(int a, int b, int w){
            if(w < mnw){
                mnw = w;
                mn1 = a;
                mn2 = b;
            }
            l[a].push_back({b,w});
            l[b].push_back({a,w});
        }

        void printGraph(){
            for(int i = 0; i < V; i++){
                cout << i << ":" << endl;
                for(auto a : l[i]){
                    cout << a.first << " " << a.second << endl;
                }
                cout << endl;
            }
        }

        int find(int a, int b){
            for(auto x : l[a]){
                if(x.first == b){
                    return x.second;
                }
            }
            return 1000;
        }

        int primAlgo(){
            vector<int> temp(V);
            int k;
            int ans = mnw;
            temp[mn1] = -1;
            temp[mn2] = -1;
            for(int i = 0; i < V; i++){
                if(temp[i] == -1){
                    continue;
                }
                temp[i] = find(i,mn1) < find(i,mn2) ? mn1 : mn2;
            }
            int ch;
            for(int i = 0; i < V - 2; i++){
                int mnw = INT_MAX;
                for(int j = 0; j < V; j++){
                    if(temp[j] == -1){
                        continue;
                    }
                    ch = find(j,temp[j]);
                    if(ch < mnw){
                        mnw = ch;
                        k = j;
                    }
                }
                ans += mnw;
                temp[k] = -1;
                for(int j = 0; j < V; j++){
                    if(temp[j] == -1){
                        continue;
                    }
                    temp[j] = (find(k,j) < find(temp[j],j)) ? k : temp[j];
                }
            }
            return ans;
        }
};

int main(){
    Graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(1,2,8);
    g.addEdge(2,3,7);
    g.addEdge(3,4,9);
    g.addEdge(4,5,10);
    g.addEdge(3,5,14);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(5,6,2);
    g.addEdge(8,6,6);
    g.addEdge(6,7,1);
    g.addEdge(1,7,11);
    g.addEdge(0,7,8);
    g.addEdge(7,8,7);
    cout << g.primAlgo() << endl;
    return 0;
}
