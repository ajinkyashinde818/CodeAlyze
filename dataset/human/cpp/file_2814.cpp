#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    int num_negative = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            A[i] = -A[i];
            num_negative++;
        }
        sum += A[i];
    }

    if (num_negative % 2 == 0) {
        cout << sum << endl;
    } else {
        sort(A.begin(), A.end());
        cout << sum - 2 * A[0] << endl;
    }

    return 0;
}
