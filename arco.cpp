#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int soma(vector<int>& tree, int idx) {
    idx++;
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void atualizar(vector<int>& tree, int idx, int val, int n) {
    idx++;
    while (idx <= n) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

long long inverter(vector<long long>& tiros) {
    vector<long long> sorted = tiros;
    sort(sorted.begin(), sorted.end());

    unordered_map<long long, long long> rank;
    int r = 0;

    for (long long val : sorted) {
        if (rank.find(val) == rank.end()) rank[val] = r++;
    }

    vector<int> tree(tiros.size()+1, 0);

    long long inv = 0;

    for (int i = 0; i < tiros.size(); i++) {
        int pos = rank[tiros[i]];

        inv += soma(tree, pos);
        
        atualizar(tree, pos, 1, r);
    }

    return inv;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<long long> tiros(n);

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        tiros[i] = x*x + y*y;
    }

    cout << inverter(tiros);

    return 0;
}