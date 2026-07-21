#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<int> a, b;
long long co[200020] = { 0 };
long long ans[200020];
int a1, b1;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1;
        co[a1]++;
        a.emplace_back(a1);
    }
    for (int i = 0; i < n; i++) {
        cin >> b1;
        co[b1]++;
        b.emplace_back(b1);
    }
    for (int i = 0; i <= n; i++) {
        if (co[i] > n) {
            cout << "No" << endl;
            return 0;
        }
    }
    reverse(b.begin(), b.end());
    bool bo = false;
    int m, co1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            co1++;
            bo = true;
            m = a[i];
        }
    }
    if (bo) {
        int l = 1000000007, r = 1000000007;
        int l1 = 1000000007, r1 = 1000000007;
        for (int i = 0; i < n; i++) {
            if (l1 == 1000000007 && a[i] == b[i]) {
                l1 = i;
            }
            if (r1 == 1000000007 && l1 != 1000000007 && a[i] != b[i]) {
                r1 = i;
            }
        }
        if (r1 == 1000000007) {
            r1 = n;
        }
        int now = l1;
        for (int i = 0; i < n; i++) {
            if (now == r1) {
                break;
            }
            if (a[i] != b[now] && a[now] != b[i]) {
                swap(b[now], b[i]);
                now++;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
