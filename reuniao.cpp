#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

int distancia(vector<vector<pair<int, int>>>& cidades, int n, int s, int a) {
    
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    vector<bool> visit(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (auto & [w, v] : cidades[u]) {
            if (!visit[v] && d+w < dist[v]) {
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[a];

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> cidades(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cidades[u].push_back({w, v});
        cidades[v].push_back({w, u});
    }

    int s = INT_MAX;

    for (int i = 0; i < n; i++) {
        int maxi = 0;
        for (int j = 0; j < n; j++) {
            int d = (distancia(cidades, n, j, i));
            maxi = max(d, maxi);
        }
        s = min(maxi, s);
    }

    cout << s;

    return 0;
}