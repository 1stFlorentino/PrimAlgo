#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int prim(int n, vector<vector<Edge>> &adj) {
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    pq.push({0, 1});

    int total_weight = 0;
    int edges_used = 0;

    while (!pq.empty() && edges_used < n) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        total_weight += weight;
        edges_used++;

        for (const auto &edge : adj[u]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
            }
        }
    }

    return total_weight;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    cout << prim(n, adj) << endl;
    return 0;
}
