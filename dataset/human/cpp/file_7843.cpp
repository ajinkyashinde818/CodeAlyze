#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> X(N - 1);
    X[0] = A[0];
    vector<long long> Y(N - 1);
    Y[0] = A[0] * (-1);
    for (int i = 0; i < N; i++) {
        Y[0] += A[i];
    }
    for (int i = 1; i < N - 1; i++) {
        X[i] = X[i - 1] + A[i];
        Y[i] = Y[i - 1] - A[i];
    }

    long long ans = abs(X[0] - Y[0]);
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, abs(X[i] - Y[i]));
    }

    cout << ans << endl;
}
