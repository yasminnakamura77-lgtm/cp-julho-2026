#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& figura, int i, int j, int& cont) {
    if (i < 0 || i >= figura.size() || j < 0 || j >= figura[0].size() || figura[i][j] != 0) {
        return;
    }
    
    figura[i][j] = 1;
    cont ++;

    dfs(figura, i-1, j, cont);
    dfs(figura, i+1, j, cont);
    dfs(figura, i, j-1, cont);
    dfs(figura, i, j+1, cont);

    dfs(figura, i-1, j-1, cont);
    dfs(figura, i+1, j+1, cont);
    dfs(figura, i-1, j+1, cont);
    dfs(figura, i+1, j-1, cont);

}

int main(){
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    x = n - x;
    y -= 1;

    vector<vector<int>> figura(n, vector<int>(m, 0));

    for (int i = 0; i < k; i ++) {
        int a, b;
        cin >> a >> b;
        a = n - a;
        b -= 1;
        figura[a][b] = -1;
    }

    int cont = 0;

    dfs(figura, x, y, cont);

    cout << cont << '\n';

    return 0;

}