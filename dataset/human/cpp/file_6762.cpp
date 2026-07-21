#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];

    int idx = 0;
    queue<int> que;
    for (int i = 0; i < N; ++i) {
        while (idx < N && B[i] == B[idx])
            idx++;
        if (A[i] == B[i]) {
            if (idx < N) {
                swap(B[i], B[idx]);
            } else {
                while (!que.empty()) {
                    int t = que.front();
                    que.pop();
                    if (A[t] != B[i] && B[t] != A[i]) {
                        swap(B[t], B[i]);
                        break;
                    }
                }
                if (A[i] == B[i]) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if (A[i] != B[i])
            que.push(i);
    }

    cout << "Yes" << endl;
    for (auto i : B)
        cout << i << ' ';
    cout << endl;

    return 0;
}
