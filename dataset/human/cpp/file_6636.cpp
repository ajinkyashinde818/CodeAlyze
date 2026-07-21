#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const Int MOD = 1000000007;
int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> A(2*N);
    for (int i = 0; i < 2*N; i++) A[i] = S[i] == 'B';
    for (int i = 0; i < 2*N; i++) A[i] ^= (i % 2);
    Int ans = 1, cnt = 0;
    for (int i = 0; i < 2*N; i++) {
        if (A[i]) {
            cnt++;
        } else {
            ans = ans * cnt % MOD;
            cnt--;
        }
    }
    if (cnt != 0) ans = 0;
    for (int i = 1; i <= N; i++) ans = ans * i % MOD;
    cout << ans << '\n';
    return 0;
}
