#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<int> cntA(N+1), cntB(N+1);
    for (int i=0; i<N; ++i) {
        int x;
        cin >> x;
        A[i] = x;
        ++cntA[x];
    }
    for (int i=0; i<N; ++i) {
        int x;
        cin >> x;
        B[i] = x;
        ++cntB[x];
    }

    for (int i=1; i<N+1; ++i) {
        if (cntA[i] + cntB[i] > N) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
    int shift = 0;
    int sumA = 0, sumB = 0;
    for (int i=1; i<N+1; ++i) {
        sumA += cntA[i];
        chmax(shift, sumA - sumB);
        sumB += cntB[i];
    }
    for (int i=0; i<N; ++i) {
        cout << B[(N+i-shift)%N];
        if (i == N-1) cout << '\n';
        else cout << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
