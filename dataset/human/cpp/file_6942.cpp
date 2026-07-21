#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

struct P {
    bool operator<(const P &p) const {
        return a < p.a;
    }
    int a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    reverse(b.begin(), b.end());

    vector<int> c(n + 1, 0);
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
        c[b[i]]++;
    }
    for (int cc : c) {
        if (cc > n) {
            cout << "No" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            int t = a[i];
            int i0 = i, i1 = i;
            for (int j = i; j < n; j++) {
                if (a[j] != b[j]) break;
                i1 = j;
            }
            i1++;
            for (int j = 0; j < n; j++) {
                if (a[j] == t || b[j] == t || i0 >= i1) break;
                swap(b[j], b[--i1]);
            }
            for (int j = n - 1; j >= 0; j--) {
                if (i0 >= i1) break;
                swap(a[j], a[i0++]);
            }
            break;
        }
    }

    int r = 1;
    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = { a[i], b[i] };
        if (a[i] == b[i]) r = 0;
    }
    sort(p.begin(), p.end());

    if (r == 0) throw;
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i].b << " \n"[i == n - 1];
    }

    //個数のみが重要 片方にしかない数はどうでもいい
    //足してN個を超える数があったらNo そうでない場合は？
    //

    return 0;
}
