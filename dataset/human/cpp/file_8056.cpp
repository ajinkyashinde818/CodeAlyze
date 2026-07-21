#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long int> a(N);
    long long int y = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        y += a[i];
    }

    long long int x = 0;
    long long int min = LLONG_MAX;

    for (int i = 0; i < N - 1; i++) {
        x += a[i];
        y -= a[i];
        // cout << x << " " << y << endl;

        if (abs(x - y) < min) {
            min = abs(x - y);
        }
    }
    cout << min << endl;

    return 0;
}
