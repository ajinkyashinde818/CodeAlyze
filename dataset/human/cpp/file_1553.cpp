#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "Yes\n2\n1 1\n1 1" << endl;
        return 0;
    }
    for (int k = 1; k <= n && k <= 500; ++k) {
        vector<vector<int>> s(k);
        int now = 0;

        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                s[i].push_back(now);
                s[j].push_back(now);
                ++now;
            }
        }

        if (now == n) {
            cout << "Yes\n";
            cout << k << endl;
            for (auto x : s) {
                cout << x.size() << ' ';
                for (auto y : x)
                    cout << y + 1 << " ";
                cout << '\n';
            }
            return 0;
        }

    }

    cout << "No\n";
}
