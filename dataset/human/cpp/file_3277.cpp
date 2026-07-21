#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    vector<long long> A(N, 0);
    long long numNeg = 0;
    for (long long i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        if (a < 0) {
            ++numNeg;
        }
        A[i] = abs(a);
    }
    sort(A.begin(), A.end());
    long long ans = 0;
    if (numNeg % 2 > 0) {
        ans -= A[0];
        for (long long i = 1; i < N; ++i) {
            ans += A[i];
        }
    }
    else {
        for (long long i = 0; i < N; ++i) {
            ans += A[i];
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
