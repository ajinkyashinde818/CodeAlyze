#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int k = 1;
    while(k * (k - 1) / 2 < n) {
        k += 1;
    }

    if(k * (k - 1) / 2 != n) {
        cout << "No" << endl;
        return 0;
    }

    const int m = n * 2 / k;
    vector<vector<int>> ans(k);
    vector<int> cnt(n);
    for(int i = 0; i < k; ++i) { // O(nsqrt(n)) ?
        for(int j = 0; j < i; ++j) {
            for(auto x : ans[j]) {
                if(cnt[x] != 2) {
                    ans[i].push_back(x);
                    cnt[x] += 1;
                    break;
                }
            }
        }

        for(int j = 0; j < n && (int)ans[i].size() != m; ++j) {
            if(cnt[j] == 0) {
                ans[i].push_back(j);
                cnt[j] += 1;
            }
        }
    }

    cout << "Yes\n" << k << endl;
    for(int i = 0; i < k; ++i) {
        cout << m << ' ';
        for(int j = 0; j < m; ++j) {
            cout << ans[i][j] + 1 << " \n"[j + 1 == m];
        }
    }
}
