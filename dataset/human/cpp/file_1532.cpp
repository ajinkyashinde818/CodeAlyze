#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int> > ans;
    vector<int> one;
    one.push_back(1);
    ans.emplace_back(one);
    ans.emplace_back(one);
    int l = 2;
    while (l <= n) {
        int need = ans.size();
        if (need + l - 1 > n) {
            cout << "No\n";
            return 0;
            break;
        }
        ans.emplace_back(vector<int>());
        for (int j = 0; j < need; j++) {
            ans.back().push_back(l);
            ans[j].push_back(l);
            l++;
        }
        if (l > n) break;
    }
    cout << "Yes\n";
    cout << ans.size() << "\n";
    for (auto it: ans) {
        cout << it.size();
        for (auto jt: it) cout << " " << jt;
        cout << "\n";
    }
    return 0;
}
