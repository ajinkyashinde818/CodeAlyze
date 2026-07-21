#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <complex>
using namespace std;

typedef complex<double> pt;

pt read_pt()
{
    double x, y;
    cin >> x >> y;
    return pt(x, y);
}

int main()
{
    cin.tie(0);

    pt st = read_pt();
    pt go = read_pt();

    int n;
    cin >> n;

    vector<pair<pt, double>> bs(n);

    for (auto &b: bs) {
        b.first = read_pt();
        cin >> b.second;
    }

    bs.emplace_back(st, 0);
    bs.emplace_back(go, 0);

    vector<vector<double>> g(bs.size(), vector<double>(bs.size(), -1));

    for (int i = 0; i < bs.size(); i++) {
        for (int j = 0; j < bs.size(); j++) {
            g[i][j] = max(0.0 , abs(bs[i].first - bs[j].first) - bs[i].second - bs[j].second);
        }
    }

    set<pair<double, int>> q;
    q.insert(make_pair(0, n));

    vector<double> tbl(bs.size(), -1);

    while (q.size()) {
        double d = q.begin()->first;
        int pos = q.begin()->second;
        q.erase(q.begin());

        if (tbl[pos] >= 0)
            continue;
        tbl[pos] = d;

        if (pos == n + 1) {
            printf("%.12f\n", d);
            return 0;
        }

        for (int i = 0; i < g[pos].size(); i++) {
            double nd = d + g[pos][i];
            if (tbl[i] >= 0)
                continue;
            q.insert(make_pair(nd, i));
        }
    }

    return 0;
}
