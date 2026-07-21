/*
digu_J - Digvijay Janartha
NIT Hamirpur - INDIA
*/

#include <bits/stdc++.h>
using namespace std;

void test() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        while (lo <= hi and a[lo] != b[lo]) {
            ++lo;
        }
        while (lo <= hi and a[hi] != b[hi]) {
            --hi;
        }
        if (lo <= hi and b[lo] != b[hi]) {
            swap(b[lo], b[hi]);
            ++lo, --hi;
        } else {
            break;
        }
    }
    int cnt = max(0, hi - lo + 1);
    vector<int> idx;
    if (lo <= hi) {
        for (int i = 0; i < lo; ++i) {
            if (a[i] != b[lo] and b[i] != b[lo]) {
                idx.emplace_back(i);
            }
        }
        for (int i = hi + 1; i < n; ++i) {
            if (a[i] != b[lo] and b[i] != b[lo]) {
                idx.emplace_back(i);
            }
        }
    }
    if (cnt > int(idx.size())) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = lo, j = 0; i <= hi; ++i, ++j) {
            swap(b[i], b[idx[j]]);
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; ++i) {
        test();
    }
    return 0;
}
