#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++)
        A[i] += A[i - 1];

    long long sum = A[N - 1];
    long long res = 1LL << 60;
    for (int i = 0; i < N - 1; i++) {
        long long diff = abs(sum - 2 * A[i]);
        res = min(res, diff);
    }
    cout << res << endl;
    return 0;
}
