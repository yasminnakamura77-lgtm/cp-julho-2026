#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int cortando(vector<int> &pizza) {
    int total = 0;
    int currmax = 0, currmin = 0;
    int maxsum = INT_MIN, minsum = INT_MAX;

    for (int x : pizza) {

        currmax = max(x, currmax+x);
        maxsum = max(currmax, maxsum);

        currmin = min(x, currmin+x);
        minsum = min(currmin, minsum);

        total += x;

    }

    int circular = total - minsum;

    if (maxsum < 0) {
        return 0;
    }

    return max(circular, maxsum);

}

int main() {
    int n;
    cin >> n;
    vector<int> pizza(n);
    for (int i = 0; i < n; i++) {
        cin >> pizza[i];
    }

    cout << cortando(pizza);

    return 0;
}
