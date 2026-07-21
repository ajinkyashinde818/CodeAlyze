#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

struct Pos {
    int i, v;
} a[200005];
int b[200005];
int ans[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].i = i;
        cin >> a[i].v;
    }
    sort(a + 1, a + n + 1, [](Pos x, Pos y) {
        return x.v < y.v;
    });
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + n + 1, [](int x, int y) { return x > y; });
    vector<int> v;
    int dup;
    for (int i = 1; i <= n; i++) {
        if (a[i].v == b[i]) {
            dup = b[i];
            v.push_back(i);
        }
    }
    int len = v.size();
    if (v.size() > 0) {
        int i = 1;
        int cur = v[0];
        while (len && b[i] != dup && a[i].v != dup) {
            swap(b[i], b[cur]);
            i++;
            cur++;
            len--;
        }
        i = n;
        while (len && b[i] != dup && a[i].v != dup) {
            swap(b[i], b[cur]);
            i--;
            cur++;
            len--;
        }
    }
    if (len == 0) {
        puts("Yes");
        for (int i = 1; i <= n; i++) {
            ans[a[i].i] = b[i];
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        puts("");
    } else {
        puts("No");
    }
}
