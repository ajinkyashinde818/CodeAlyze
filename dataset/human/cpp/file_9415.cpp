//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const vector<T> &v) {
    for (auto e : v) cout << e << ' ';
    cout << endl;
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    int N, M; cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    bool match = false;

    for (int i = 0; i <= N-M; i++) {
        for (int j = 0; j <= N-M; j++) {
            bool flag = true;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    if (A[i+x][j+y] != B[x][y]) flag = false;
                }
            }
            if (flag) match = true;
        }
    }

    cout << (match ? "Yes" : "No") << '\n';
    
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}
