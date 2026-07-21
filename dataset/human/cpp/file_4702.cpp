#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, R;
    cin >> N >> R;
    if (N >= 10) {
        cout << R << endl;
    } else {
        cout << R + 100 * (10 - N) << endl;
    }
}
