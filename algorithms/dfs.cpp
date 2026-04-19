#include<bits/stdc++.h>
using namespace std;
void dfs (int node, vector<vector<int>>&adj, vector<bool>&visited) {

    visited[node] = true;
    cout << node << " ";

    for (int neighbour: adj[node]){
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}
int main() {

    int n,m;
    cout << "Enter nodes & edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        /* code */
        int u,v;
        cout << "Enter edges" << endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    int start;
    cout << "Enter starting node: ";
    cin >> start;
    dfs(start, adj, visited);   
}