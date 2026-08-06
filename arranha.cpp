#include <iostream>
#include <vector>
using namespace std;

vector<int> criar(vector<int>& predio, int n) {

    vector<int> tree(n, 0);

    for (int i = 1; i <= n; i++) {
        tree[i-1] += predio[i-1];
        int pai = i + (i & -i);
        if (pai <= n)
            tree[pai-1] += tree[i-1];
    }

    return tree;

}

void mudar(vector<int>& tree, int k, int p, int n, int p0) {

    int i = k;

    while (i <= n) {
        tree[i-1] += (p-p0);
        i += (i & -i);
    }
}

int soma(vector<int>& tree, int k) {

    int soma = 0;
    int i = k;

    while (i > 0) {
        soma += tree[i-1];
        i -= (i & -i);
    }

    return soma;

}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> predio(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        predio[i] = a;
    }

    vector<int> tree = criar(predio, n);

    vector<int> saida;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x) {
            int k;
            cin >> k;
            saida.push_back(soma(tree, k));
        }
        else {
            int k, p;
            cin >> k >> p;
            int p0 = predio[k-1];
            mudar(tree, k, p, n, p0);
            predio[k-1] = p;
        }
    }

    for (int s : saida) {
        cout << s << '\n';
    }

    return 0;
}