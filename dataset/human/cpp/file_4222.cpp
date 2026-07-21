#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    Int T; cin >> T;
    Int ans = 0;
    bool first = true;
    while (T) {
        if (T <= 3) {
            ans += T;
            break;
        } else if (T % 3 == 0) {
            T -= 3;
            ans += 3;
        } else if (T % 3 == 1 && first) {
            T -= 1;
            ans += 1;
        } else if (T % 3 == 1 && !first) {
            T -= 4;
            ans += 4;
        } else if (T % 3 == 2) {
            T -= 2;
            ans += 2;
        }
        first = false;
        T /= 3;
    }
    cout << ans << endl;
    return 0;
}
