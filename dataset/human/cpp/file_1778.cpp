#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; i++) ps[i] = {1, i + 1};
    for (int i = 0; i < m; i++) {
        int e; cin >> e; e--;
        ps[e].first = -i;
    }
    sort(ps.begin(), ps.end());
    for (auto &p: ps) cout << p.second << endl;
    return 0;
}
