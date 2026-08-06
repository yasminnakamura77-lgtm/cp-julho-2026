#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

int busca(vector<vector<pair<int, int>>>& grafo, int n) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    vector<bool> visit(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (auto& [w, v] : grafo[u]) {
            if (!visit[v] && dist[v] > d+w) {
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n-1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> grafo(n+2);

    for (int i = 0; i < m; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        grafo[s].push_back({b, t});
        grafo[t].push_back({b, s});
    }

    cout << busca(grafo, n+2);

    return 0;
}