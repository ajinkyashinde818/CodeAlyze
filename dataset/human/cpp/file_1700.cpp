#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

void printvec(vi& x, int size = 0) {
    cout << x.front();
    for (int i = 1; i < (size == 0 ? x.size() : size); i++) {
        cout << " " << x[i];
    }
    cout << endl;
}

int main() {
    i64 n;
    cin >> n;
    int ok = 0, k;
    for (i64 i = 1; i <= n; i++) {
        if (i * (i + 1) / 2 == n) {
            ok = 1;
            k = i + 1;
        }
    }
    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    vvi ans(k);
    int crt = 1;
    int hoge = 1;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            ans[i].push_back(hoge);
            ans[j].push_back(hoge++);
        }
    }

    cout << "Yes" << endl;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << ans[i].size() << " ";
        printvec(ans[i]);
    }
}
