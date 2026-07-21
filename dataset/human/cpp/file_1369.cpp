#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

int main() {
    int r, g, b, n;

    cin >> r >> g >> b >> n;

    set<int> s;
    for (int n_b = 0; n_b * b <= n; n_b++) {
        s.insert(n - n_b * b);
    }

    int ans = 0;
    for (int n_r = 0; n_r * r <= n; n_r++) {
        for (int n_g = 0; n_g * g <= n; n_g++) {
            if (s.find(n_r * r + n_g * g) != s.end()) ans++;
        }
    }

    cout << ans << endl;
}
