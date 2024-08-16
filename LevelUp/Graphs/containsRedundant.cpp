class Graph{
    int v;
    list<int> *l;
    
    public:
        Graph(int v){
            this->v = v;
            l = new list<int>[v];
        }
        
        void addEdge(int x, int y){
            l[x].push_back(y);
        }
        
        bool dfs(int src, vector<bool> &visited, vector<bool> &stack){
            visited[src] = true;
            stack[src] = true;
            for(auto x : l[src]){
                if(stack[x]){
                    return true;
                }else if(visited[x] == false){
                    bool ans = dfs(x, visited, stack);
                    if(ans){
                        return true;
                    }
                }
            }
            stack[src] = false;
            return false;
        }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int V = edges.size() + 1;
        Graph g(V);
        vector<bool> visited(V+1,false);
        vector<bool> stack(V+1,false);
        for(int i = 0; i < V - 1; i++){
            g.addEdge(edges[i][0],edges[i][1]);
            bool ans = g.dfs(i,visited,stack);
            if(ans){
                return true;
            }
        }
    }
};