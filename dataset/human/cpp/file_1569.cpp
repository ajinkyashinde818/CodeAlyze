#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n;
    cin >> n;
    int k = -1;
    for (int i = 0; i <= n; ++i) {
        if (i * (i + 1) == 2 * n) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        cout << "No"
             << "\n";
        return 0;
    }
    vvi s(k + 1, vi(k, 0));
    int col = 0;
    int row = 0;
    for (int i = 1; i <= n; ++i) {
        s[row][col] = i;
        col++;
        if (col == k) {
            row++;
            col = row;
        }
    }
    col = 0;
    row = 1;
    for (int i = 1; i <= n; ++i) {
        s[row][col] = i;
        row++;
        if (row == k + 1) {
            col++;
            row = col + 1;
        }
    }
    cout << "Yes"
         << "\n";
    cout << k + 1 << "\n";
    for (int i = 0; i < k + 1; ++i) {
        cout << k << " ";
        print(s[i]);
    }
    return 0;
}
