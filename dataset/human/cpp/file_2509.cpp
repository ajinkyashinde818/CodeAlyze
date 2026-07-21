#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long N, A[100000], cnt = 0, ans = 0, min = (int)1e9;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) cnt++;
        ans += abs(A[i]);
        if (abs(A[i]) < min) min = abs(A[i]);
    }
    if (cnt % 2) ans -= min * 2;
    cout << ans << endl;
}
