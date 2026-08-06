#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long soma1(vector<long long>& sanduiche, long long d, vector<long long>& prefsum, long long so) {
    
    long long cont = 0;
    
    int l = 0;
    int r = 0;

    while (r < sanduiche.size()) {
        long long soma = (l == 0) ? prefsum[r] : (prefsum[r] - prefsum[l-1]);

        if (soma == d) {
            cont ++;
            l++;
            r++;
        }
        else if (soma < d) r ++;
        else if (soma > d) {
            l ++;
            if (l > r) r = l;
        }
    }

    return cont;

}

long long soma2(vector<long long>& sanduiche, long long d, vector<long long>& prefsum, long long so) {

    long long alvo = so - d;

    if (alvo == 0) return sanduiche.size()-1;

    long long cont = 0;

    int l = 0;
    int r = 0;

    while (r < sanduiche.size()) {

        long long soma = (l == 0) ? prefsum[r] : (prefsum[r] - prefsum[l-1]);

        if (soma == alvo) {
            if (l > 0 && r < sanduiche.size()-1)
                cont ++;
            r ++;
            l++;
        } else if (soma < alvo) r ++;
        else if (soma > alvo) { 
            l++;
            if (l > r) r = l;
        }
    }

    return cont;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> sanduiche(n);

    for (int i = 0; i < n; i++) {
        cin >> sanduiche[i];
    }

    vector<long long> prefsum;
    long long so = 0;

    for (long long s : sanduiche) {
        so += s;
        prefsum.push_back(so);
    }

    cout <<
    soma1(sanduiche, d, prefsum, so) + soma2(sanduiche, d, prefsum, so);

    return 0;
}