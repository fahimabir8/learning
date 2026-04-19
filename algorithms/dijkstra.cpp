#include<bits/stdc++.h>
using namespace std;
class Edge {
    public: 
        int v;
        int w;
        Edge (int v, int w) {
            this->v = v;
            this->w = w;
        }
};

void dijkstra (int src, vector<vector<Edge>> g, int n) {
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, src});
    
    while (pq.size() > 0) 
    {
        int u = pq.top().second;
        pq.pop();

        for (Edge e: g[u]) {
            if (dist[e.v] > dist[u] + e.w) {
                dist[e.v] = dist[u] + e.w;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    
    
}
int main(){
    int n,m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<Edge>> g(n);

    for (int i = 0; i < m; i++)
    {
        int u,v,k;
        cout << "Enter starting: ";
        cin >> k;
        cout << "Enter node, weight: ";
        cin >> u >> v;
        g[k].push_back(Edge(u,v));    
    }
    
    dijkstra(0, g, n);
    
}