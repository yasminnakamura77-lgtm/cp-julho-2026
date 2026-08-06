#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int resp(int s, vector<vector<pair<int, int>>>& ilhas, int n) {

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    vector<bool> visit(n, false);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (auto&[v, w] : ilhas[u]) {
            if (!visit[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    dist.erase(dist.begin()+s);

    int mi = *min_element(dist.begin(), dist.end());
    int ma = *max_element(dist.begin(), dist.end());

    return ma-mi;


}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> ilhas(n);

    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        ilhas[v-1].push_back({u-1, p});
        ilhas[u-1].push_back({v-1, p});
    }

    int s;
    cin >> s;

    cout << resp(s-1, ilhas, n);

    return 0;
}