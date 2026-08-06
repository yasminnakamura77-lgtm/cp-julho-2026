#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> ilhas(m+2, vector<char>(n+2, '.'));
    for (int i = 0; i < m; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < n; j++) {
            ilhas[i+1][j+1] = c[j];
        }
    }
    long long cont = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (ilhas[i][j] == '#') {
                if (ilhas[i-1][j] == '.' ||
                    ilhas[i+1][j] == '.' ||
                    ilhas[i][j-1] == '.' ||
                    ilhas[i][j+1] == '.') {
                        cont ++;
                    }
            }
        }
    }
    cout << cont;
    return 0;
}
