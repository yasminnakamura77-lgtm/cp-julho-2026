#include <iostream>
#include <vector>
using namespace std;

int pos(int x) {

    if (x%2 == 0) return x/2;
    else return (x-1)/2;

}

string encontro(int k, int l) {

    vector<string> e = {"oitavas", "quartas", "semifinal", "final"};
    
    for (string x : e) {
        k = pos(k);
        l = pos(l);
        if (k == l) return x;
    }
}

int main() {
    int k;
    int l;

    for (int i = 0; i < 16; i++) {
        int a;
        cin >> a;
        if (a == 1) k = i;
        if (a == 9) l = i;
    }

    cout << encontro(k, l);

    return 0;
}