#include<bits/stdc++.h>

using namespace std;

void bfs (int start, vector<vector<int>>&adj, int n) {
    vector<bool> visited(n,false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
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
    int start;
    cout << "Enter starting node: ";
    cin >> start;
    bfs(start, adj, n);   
}