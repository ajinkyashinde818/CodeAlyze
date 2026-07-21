#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fastsolve(vector<int> a, vector<int> b) {
    int n = a.size();

    a.push_back(0);
    b.push_back(0);
    for (int i = 0; i < n; i++) {
        a[n] ^= a[i];
        b[n] ^= b[i];
    }

    vector<int> aa = a, bb = b;
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    if (aa != bb) {
        return -1;
    }

    /*set<int> st;
    map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            st.insert(i);
        }
        mp[b[i]].push_back(i);
    }
    for (auto &it : mp) {
        sort(it.second.begin(), it.second.end(), [&](int i, int j) {
            return (a[i] == b[n]) < (a[j] == b[n]);
        });
    }
    int ans = 0;
    while (!st.empty()) {
        bool need = a[n] == b[n];
        while (!mp[a[n]].empty()) {
            need = a[n] == b[n];
            int id = mp[a[n]].back();
            if (a[id] == b[id]) mp[a[n]].pop_back();
            else {
                need = 0;
                mp[a[n]].pop_back();
                swap(a[n], a[id]);
                st.erase(id);
                ans++;
                break;
            }
        }
        if (need) {
            int id = *st.begin();
            swap(a[n], a[id]);
            if (a[id] == b[id]) st.erase(id);
            ans++;
        }
    }*/
    map<int, int> p, cnt;
    for (int i = 0; i <= n; i++) {
        p[a[i]] = a[i], p[b[i]] = b[i];
        cnt[a[i]] = cnt[b[i]] = 1;
    }

    function<int(int)> get = [&](int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    };
    auto uni = [&](int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return;
        cnt[u] += cnt[v];
        p[v] = u;
    };

    for (int i = 0; i <= n; i++) {
        uni(a[i], b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] != b[i];
    for (int i = 0; i <= n; i++) {
        //cout << i << " " << a[i] << " " << get(a[i]) << " " << cnt[a[i]] << endl;
        if (get(a[i]) == a[i] && get(a[n]) != a[i] && get(b[n]) != a[i] && cnt[a[i]] > 1) {
            ans++;
            cnt[a[i]] = 1;
        }
        //cout << i << " " << b[i] << " " << get(b[i]) << " " << cnt[a[i]] << endl;
        if (get(b[i]) == b[i] && get(a[n]) != b[i] && get(b[n]) != b[i] && cnt[b[i]] > 1) {
            ans++;
            cnt[b[i]] = 1;
        }
    }
    return ans;
}

int slowsolve(vector<int> a, vector<int> b) {
    int n = a.size();

    map<vector<int>, int> mp;
    queue<vector<int> > q;
    q.push(a);
    mp[a] = 0;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v == b) return mp[v];
        int x = 0;
        for (int i = 0; i < n; i++) x ^= v[i];

        for (int j = 0; j < n; j++) {
            auto b = v;
            b[j] = x;
            if (!mp.count(b)) {
                mp[b] = mp[v] + 1;
                q.push(b);
            }
        }
    }
    return -1;
}

void stress() {
    const int C = 8;
    for (int it = 93;; it++) {
        srand(it);
        cout << it << endl;

        int n = rand() % 8 + 1;
        vector<int> a;
        for (int i = 0; i < n; i++) a.push_back(rand() % C);
        a.push_back(0);
        for (int i = 0; i < n; i++) a.back() ^= a[i];
        vector<int> b = a;
        random_shuffle(b.begin(), b.end());
        a.pop_back();
        b.pop_back();

        int ans1 = fastsolve(a, b);
        int ans2 = slowsolve(a, b);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << endl;
            for (int x : a) cout << x << " ";
            cout << endl;
            for (int x : b) cout << x << " ";
            cout << endl;

            fastsolve(a, b);
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    //stress();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        printf("%d\n", fastsolve(a, b));
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
