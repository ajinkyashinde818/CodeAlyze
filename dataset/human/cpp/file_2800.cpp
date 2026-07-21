#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    int m = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            m++;
            sum += -A[i];
        } else {
            sum += A[i];
        }
    }

    if (m % 2 == 1) {
        long long minv = 1e9 + 1;
        for (int i = 0; i < N; i++) {
            minv = min(abs(A[i]), minv);
        }
        cout << sum - 2 * minv << endl;
    } else {
        cout << sum << endl;
    }
}
