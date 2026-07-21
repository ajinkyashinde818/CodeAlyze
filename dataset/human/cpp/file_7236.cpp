#include <iostream>

using namespace std;
using LL = long long;

int main() {

    int N;
    cin >> N;

    LL A[N + 1];
    fill(A, A + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        A[i] = A[i - 1] + a;
    }

    LL min_ = INT64_MAX;

    for (int i = 1; i < N; i++) {
        min_ = min(min_, abs(A[N] - A[i] * 2));
    }

    cout << min_ << endl;
}
