#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector <ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector <vector<ll>> DP(N, vector<ll>(2));
    DP[0][0] = A[0];
    DP[1][0] = A[0] + A[1];
    DP[1][1] = -1 * (A[0] + A[1]);
    for (int i = 2; i < N; i++) {
        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + A[i];
        DP[i][1] = max(DP[i - 1][1] + 2ll * (A[i - 1]) - A[i], DP[i - 1][0] - 2ll * A[i - 1] - A[i]);
    }
    cout << max(DP[N - 1][0], DP[N - 1][1]);
    return 0;
}
