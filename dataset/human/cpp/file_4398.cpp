#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxN = 1e5 + 10;
int n;
int a[maxN];
vector < int > g[maxN];
bool used[maxN];
void go(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) go(to);
    }
}
int b[maxN];
bool have[maxN];
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int xr = 0;
    vector < int > ff, gg;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xr ^= a[i];
        ff.emplace_back(a[i]);
    }
    ff.emplace_back(xr);
    a[n] = xr;
    sort(ff.begin(), ff.end());
    int nxr = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        nxr ^= b[i];
        gg.emplace_back(b[i]);
    }
    gg.emplace_back(nxr);
    sort(gg.begin(), gg.end());
    if (ff != gg) {
        cout << -1;
        return 0;
    }
    ff.erase(unique(ff.begin(), ff.end()), ff.end());
    b[n] = nxr;
    int uniq = 0;
    /*for (int i = 0; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i <= n; i++) cout << b[i] << " ";
    cout << endl;*/
    for (int i = 0; i <= n; i++) {
        if (a[i] == b[i] && i != n) {
            uniq++;
        }
        else {
            int from = lower_bound(ff.begin(), ff.end(), a[i]) - ff.begin();
            int to = lower_bound(ff.begin(), ff.end(), b[i]) - ff.begin();
            have[from] = true;
            have[to] = true;
            g[from].emplace_back(to);
            g[to].emplace_back(from);
        }
    }
    int cnt = 0;
    for (int i = 0; i < ff.size(); i++) {
        if (!used[i] && have[i]) {
            cnt++;
            go(i);
        }
    }
    cout << (n + 1 - uniq) + cnt - 2 << " ";
    return 0;
}
