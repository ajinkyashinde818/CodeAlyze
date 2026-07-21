#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count_minus = 0;
    int a[n];
    long total = 0;
    int min = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            count_minus++;
        }
        total += abs(a[i]);
        min = std::min(min, abs(a[i]));
    }

    if (count_minus % 2 == 0) {
        cout << total << endl;
        return 0;
    }

    cout << total - min * 2 << endl;

    return 0;
}
