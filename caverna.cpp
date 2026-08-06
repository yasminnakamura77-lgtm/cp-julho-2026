#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ult = 0;
    long long dist = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (dist != -1) {
            if (min(a, m-a) >= ult) {
                dist += min(a, m-a);
                ult = min(a, m-a);

            } else if (max(a, m-a) >= ult) {
                dist += max(a, m-a);
                ult = max(a, m-a);

            } else {
                dist = -1;
            }
        }
    }
    cout << dist;
    return 0;
}
