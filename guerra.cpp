#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<int> secoes(n);
    for (int i = 0; i < n; i++) {
        cin >> secoes[i];
    }

    auto secoes1 = secoes;
    reverse(secoes1.begin(), secoes1.end());

    vector<int> prefsum(n);
    prefsum[0] = secoes[0];

    vector<int> prefsum1(n);
    prefsum1[0] = secoes1[0];
    

    for (long long i = 1; i < n; i++) {
        prefsum[i] = prefsum[i-1] + secoes[i];
        prefsum1[i] = prefsum1[i-1] + secoes1[i];
    }
    
    reverse(prefsum1.begin(), prefsum1.end());

    for (long long i = 0; i < n; i++) {
        if (i == 0) {
            if (prefsum[0] == prefsum1[1]) {
                cout << 1;
            }
        }
        else if (prefsum[i-1] == prefsum1[i]) {
            cout << i;
        }
    }

}
