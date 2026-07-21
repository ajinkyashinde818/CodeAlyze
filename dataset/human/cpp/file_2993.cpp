#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int count = 0;
    ll ans = 0, minA = 1LL << 30;
    for (int i = 0; i < N; i++) {
        ll A; cin >> A;
        minA = min(minA, abs(A));
        if (A < 0) count++;
        ans += abs(A);
    }
    cout << (count % 2 ? ans - minA * 2 : ans) << "\n";
}
