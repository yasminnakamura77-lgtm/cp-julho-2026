#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 1;
int l;

vector<vector<int>> adj;
vector<long long> tam;

int timer;
vector<int> tin;
vector<int> tout;
vector<vector<int>> up;

vector<long long> depth;

void dfs(int v, int p) {

    tin[v] = ++timer;
    up[v][0] = p;

    depth[v] = depth[p] + tam[v];

    for (int i = 1; i < l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int f : adj[v]) {
        if (f != p) {
            dfs(f, v);
        }
    }

    tout[v] = ++timer;
}

bool ehpai(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    
    if (ehpai(u, v)) {
        return u;
    }

    if (ehpai(v, u)) {
        return v;
    }

    for (int i = l; i >= 0; i--) {
        if (!ehpai(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];

}

void pre(int raiz) {

    l = ceil(log2(n));
    
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vector<int>(l+1));

    depth.resize(n);

    depth[raiz] = 0;

    dfs(raiz, raiz);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cont = 0;

    vector<vector<long long>> r;

    while (n != 0) {
    cin >> n;

    if (n != 0) {

    adj.assign(n, vector<int>());
    tam.resize(n);

    for (int i = 1; i < n; i++) {
        int a, l;
        cin >> a >> l;
        adj[i].push_back(a);
        adj[a].push_back(i);
        tam[i] = l;
    }
    
    pre(0);

    int q;
    cin >> q;

    vector<long long> vazio;
    r.push_back(vazio);

    for (int i = 0; i < q; i++) {
        long long a, b;
        cin >> a >> b;
        long long c = lca(a, b);
        long long dist = depth[a] + depth[b] - 2*depth[c];

        r[cont].push_back(dist);
    }
    cont ++;
}}

    for (auto re : r) {
        for (long long res : re) {
            cout << res << ' ';
        } cout << '\n';
    }

    return 0;
}
