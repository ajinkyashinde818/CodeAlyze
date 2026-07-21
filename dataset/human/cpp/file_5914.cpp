#include <bits/stdc++.h>

using namespace std;

long long Calories(const vector<pair<long long, int>> &v, long long C) {
    int n = v.size();

    vector<long long> pref_sum(n);
    pref_sum[0] = v[0].second;
    for (int i = 1; i < n; ++i) {
        pref_sum[i] = pref_sum[i-1] + v[i].second;
    }
    
    vector<int> best_pref[2];
    //best_pref[0].resize(n);
    //best_pref[1].resize(n);

    long long best[2] = {0, 0};

    for (int i = 0; i < n; ++i) {
        long long s[2] = {0, 0};
        s[0] = pref_sum[i] - v[i].first;
        s[1] = pref_sum[i] - 2 * v[i].first;
        //cerr << s[0] << " " << s[1] << "\n";
        //cerr << best[0] << " " << best[1] << "\n";
        for (int j = 0; j < 2; ++j) {
            if (s[j] > best[j]) {
                //cerr << "WTF\n";
                best_pref[j].push_back(i);
                best[j] = s[j];
            }
        }
    }

    long long best_res = 0;
    if (best_pref[0].size() > 0) {
        best_res = pref_sum[best_pref[0].back()] - v[best_pref[0].back()].first;
    }

    //cerr << best_res << "\n";

    long long suf_res[2] = {0, 0};

    for (int i = n-1; i >= 0; --i) {

        suf_res[0] += v[i].second + v[i].first - ((i == n-1) ? C : v[i+1].first);
        suf_res[1] += v[i].second + 2 * (v[i].first - ((i == n-1) ? C : v[i+1].first));
        //cerr << suf_res[0] << " " << suf_res[1] << "\n";
        //cerr << v[i].second << " " << v[i].first << "\n";
        for (int j = 0; j < 2; ++j) {
            int k = 1 - j;
            long long res = suf_res[j];

            auto it = lower_bound(begin(best_pref[k]), end(best_pref[k]), i);
            if (it != begin(best_pref[k])) {
                --it;
                res += pref_sum[*it] - v[*it].first;
                if (k == 1) res -= v[*it].first;
            }
            best_res = max(best_res, res);
        }
    }
    
    return best_res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long c;

    
    cin >> n >> c;

    vector<pair<long long, int>> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    cout << Calories(v, c) << "\n";

    return 0;
}
