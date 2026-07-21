#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;cin >> N;
    vector<ll> A(N);
    int count = 0;ll absmin;ll ans = 0;
    cin >> A[0];ans += abs(A[0]);absmin = abs(A[0]);if (A[0] < 0) count++;
    for (int i = 1;i < N;i++){
        cin >> A[i];
        if (A[i] < 0) count++;
        absmin = min(absmin,abs(A[i]));
        ans += abs(A[i]);
    }
    if (count % 2 != 0) ans -= absmin * 2;
    cout << ans << endl;
}
