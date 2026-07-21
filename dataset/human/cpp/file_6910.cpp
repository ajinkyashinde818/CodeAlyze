#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &it : a) cin >> it;
    for (int &it : b) cin >> it;
    reverse(b.begin(), b.end());
    int target = -1;
    vector<int> to_swap, cand;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            target = a[i];
            to_swap.push_back(i);
        }
    }
    if (target != -1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != target && b[i] != target) {
                cand.push_back(i);
            }
        }
        if (cand.size() < to_swap.size()) {
            cout << "No\n";
            return 0;
        }
        for (int i = 0; i < (int)to_swap.size(); i++) {
            swap(b[to_swap[i]], b[cand[i]]);
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
    return 0;
}
