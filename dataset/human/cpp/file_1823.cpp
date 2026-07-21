#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    int n, m; cin >> n >> m;
    vector<int> e(m);
    set<int> used;
    for (int i = 0; i < m; i++) cin >> e[i];

    for (int i = m-1; i >= 0; i--) {
        auto r = used.insert(e[i]);
        if (r.second) {
            cout << e[i] << endl;
        }
    }

    for (int i = 1; i <= n; i++) {
        int r = used.count(i);
        if (r == 0) {
            cout << i << endl;
        }
    }

    return 0;
}
