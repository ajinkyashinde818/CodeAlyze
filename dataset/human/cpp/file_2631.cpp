#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long ans = 0, counter = 0, m = 2147483647;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        ans += abs(A[i]);
    }
    for (int i = 0; i < N; ++i) {
        m = min(m, abs(A[i]));
        if (A[i] == 0) {
            cout << ans << endl;
            return 0;
        }
        if (A[i] < 0) ++counter;
    }
    if (counter % 2 == 1) ans -= m * 2;

    cout << ans << endl;
    return 0;
}
