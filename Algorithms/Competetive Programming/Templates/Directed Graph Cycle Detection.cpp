#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f;

class Graph{
public:
    int v;
    map<int, vector<int>> adj;

    Graph(int vertCount){
        v = vertCount;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool DFS(int src, bool visited[]){
        visited[src] = true;
        for (int i = 0; i < v; ++i){
            cout << visited[i] << ' ';
        }
        cout << endl;

        if (adj[src].empty()){
            return false;
        } else {
            for (int con : adj[src]){
                if (visited[con]){
                    return true;
                } else {
                    if (DFS(con, visited)){
                        return true;
                    } else {
                        visited[con] = false;
                    }
                }

            }
        }
        return false;
    }

    bool isCyclic(){
        for (int i = 0; i < v; ++i){
            bool visited[v];
            fill_n(visited, v, false);

            if (DFS(i, visited)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    if (graph.isCyclic()){
        cout << "There is a cycle!";
    } else {
        cout << "There are no cycles here!";
    }

    return 0;
}
