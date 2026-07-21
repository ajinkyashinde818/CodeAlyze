#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (A[i] < 0) {
            A[i] *= -1;
            A[i + 1] *= -1;
        }
    }

    ll sum = 0;
    int m = 1e9 + 10;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        m = min(m, abs(A[i]));
    }

    if (A[N - 1] >= 0) {
        cout << sum << endl;
    } else {
        cout << sum - 2 * A[N - 1] - 2 * m << endl;
    }
}
