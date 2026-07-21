#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int num_minus = 0;
    long long sum_abs = 0;
    long long min_abs = 1LL<<60;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) ++num_minus;
        sum_abs += abs(A[i]);
        min_abs = min(min_abs, abs(A[i]));
    }
    if (num_minus % 2 == 0) cout << sum_abs << endl;
    else cout << sum_abs - min_abs * 2 << endl;
}
