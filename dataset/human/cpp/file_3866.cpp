#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,pair<double,double>>> p;
    vector<double> rad;
    int xs, ys, xf, yf, n;
    cin >> xs >> ys >> xf >> yf >> n;
    p.push_back({0, {xs, ys}});
    p.push_back({n+1, {xf, yf}});
    rad.push_back(0);
    rad.push_back(0);
    for (int q = 1; q <= n; q++) {
        int x, y, r;
        cin >> x >> y >> r;
        p.push_back({q, {x, y}});
        rad.push_back(r);
        int number_of_chunks = 10;
        double degrees = 0;
        double radius = r;

        for (int i = 0; i < number_of_chunks; i++)
        {
            degrees = i * (360 / number_of_chunks);
            float radian = (degrees * (M_PI / 180));
            double xi = radius * cos(radian);
            double yi = radius * sin(radian);

            p.push_back({q, {xi, yi}});
            rad.push_back(0);
        }
    }
    int maxn = rad.size();
    double dist[maxn];
    for (int i = 0; i < maxn; i++) {
        dist[i] = 1e18;
    }
    dist[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.emplace(make_pair(0, 0));
    while (!pq.empty()) {
        pair<double, int> node = pq.top();
        pq.pop();
        double d = -node.first;
        int i = node.second;
        //cout << "node: " << i << " dist= " << d << '\n';
        if (d > dist[i]) continue;
        for (int j = 0; j <= rad.size(); j++) {
            double c = sqrt((p[i].second.first-p[j].second.first)*(p[i].second.first-p[j].second.first)
                            + (p[i].second.second-p[j].second.second)*(p[i].second.second-p[j].second.second));
            c -= rad[i] + rad[j];
            c = max(c, (double)0);
            //cout << " attempt edge " << j << " with cost " << c << '\n';
            if (d+c > dist[j]) continue;

            if (d+c < dist[j]) {
                dist[j] = d+c;
                pq.emplace(make_pair(-dist[j], j));
            }
        }
    }
    cout << fixed << setprecision(9) << dist[1] << '\n';
}
