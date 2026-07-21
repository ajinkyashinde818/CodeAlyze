#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    for ( int i = 0; i < M; i++ ) {
        cin >> B[i];
    }

    for ( int i1 = 0; i1 + M - 1 < N; i1++ ) {
        for ( int i2 = 0; i2 + M - 1 < N; i2++ ) {
            bool ng = false;
            for ( int j1 = 0; j1 < M; j1++ ) {
                if ( A[i1+j1].substr(i2, M) != B[j1] ) {
                    ng = true;
                    break;
                }
            }
            if ( !ng ) return true;
        }
    }
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}
