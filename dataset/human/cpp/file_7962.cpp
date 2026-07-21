#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<long long> A(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<long long> sums(N, 0);
    sums[0] = A[0];
    for (int i = 1; i < N; ++i) {
        sums[i] = A[i] + sums[i - 1];
    }
    long long ans = 100000000000001;
    for (int i = 0; i < N - 1; ++i) {
        long long x = sums[i];
        long long y = sums[N - 1] - sums[i];
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
