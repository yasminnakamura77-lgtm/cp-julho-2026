#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

int satoshi(vector<vector<pair<int, int>>>& cidades, int n) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    vector<int> visit(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (auto & [w, v] : cidades[u]) {
            if (!visit[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }

    }

    return dist[n-1];

}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> cidades(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cidades[a-1].push_back({c, b-1});
        cidades[b-1].push_back({c, a-1});
    }

    cout << satoshi(cidades, n);

    return 0;
}