#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int right, int mid, long long& cont) {

    int tam1 = mid - left + 1;
    int tam2 = right - mid;

    vector<int> L(tam1), R(tam2);
    
    for (int i = 0; i < tam1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < tam2; i++) {
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < tam1 && j < tam2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i ++;
        } else {
            arr[k] = R[j];
            j ++;
            // como R está ordenado, se R[j] é maior que L[i], logo, tudo que vem depois de R[j] em R também é
            cont += tam1 - i;
        } k ++;
    }

    while (i < tam1) {
        arr[k] = L[i];
        i ++;
        k ++;
    }

    while (j < tam2) {
        arr[k] = R[j];
        j ++;
        k ++;
    }

}

void mergeSort(vector<int>& arr, int left, int right, long long& cont) {

    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, cont);
    mergeSort(arr, mid + 1, right, cont);
    merge(arr, left, right, mid, cont);

}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long cont = 0;

    mergeSort(arr, 0, n-1, cont);

    cout << cont << '\n';

    return 0;
}