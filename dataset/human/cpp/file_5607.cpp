#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;

    if (n >= 10) {
        cout << r << '\n';
    }
    else {
        cout << r + 100 * (10 - n) << '\n';
    }
}
