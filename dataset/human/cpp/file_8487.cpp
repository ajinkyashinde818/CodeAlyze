#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

vector<int> inv, fac, finv;

inline ll binomial(int a, int b) {
    return ((ll)fac[a] * finv[b] % MOD) * finv[a - b] % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(N)), B(M, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            cin >> c;
            A[i][j] = (c == '#');
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            B[i][j] = (c == '#');
        }
    }

    for (int i = 0; i <= N - M; ++i) {
        for (int j = 0; j <= N - M; ++j) {
            bool isok = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i + k][j + l] != B[k][l]) {
                        isok = false;
                        break;
                    }
                }
                if (!isok)
                    break;
            }
            if (isok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
