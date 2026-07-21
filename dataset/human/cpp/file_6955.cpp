#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using sp = set<pii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    int cnt[n];
    fill(cnt, cnt + n, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }

    if (*max_element(cnt, cnt + n) > n) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vi posa[n], posb[n];
    for (int i = 0; i < n; i++) {
        posa[a[i]].push_back(i);
        posb[b[i]].push_back(i);
    }

    sp sa, sb;
    for (int i = 0; i < n; i++) {
        if (posa[i].size() > 0) {
            sa.emplace(posa[i].size() + posb[i].size(), i);
        }
        if (posb[i].size() > 0) {
            sb.emplace(posa[i].size() + posb[i].size(), i);
        }
    }

    int ans[n];
    while (!sa.empty()) {
        auto x = prev(sa.end());
        auto y = prev(sb.end());
        if (*x == *y) {
            if (sa.size() == 1 || sb.size() > 1 && prev(y)->first > prev(x)->first) {
                y--;
            } else {
                x--;
            }
        }

        pii pa = *x, pb = *y;

        ans[posa[pa.second].back()] = pb.second;

        posa[pa.second].pop_back();
        sa.erase(pa);
        if (sb.count(pa)) {
            sb.erase(pa);
        }
        pa.first--;
        if (posa[pa.second].size()) {
            sa.insert(pa);
        }
        if (posb[pa.second].size()) {
            sb.insert(pa);
        }

        posb[pb.second].pop_back();
        if (sa.count(pb)) {
            sa.erase(pb);
        }
        sb.erase(pb);
        pb.first--;
        if (posa[pb.second].size()) {
            sa.insert(pb);
        }
        if (posb[pb.second].size()) {
            sb.insert(pb);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i==n-1];
    }
    cout.flush();

    return 0;
}
