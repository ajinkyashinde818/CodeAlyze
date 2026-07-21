#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll a, b, c, e;
    cin >> a >> b >> c >> e;
    int n;
    cin >> n;
    vector<double> x(n+2);
    vector<double> y(n+2);
    vector<double> r(n+2);
    x[0] = a;
    y[0] = b;
    x[n+1] = c;
    y[n+1] = e;
    r[0] = r[n+1] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    vector<vector<double>> cost(n+2, vector<double>(n+2));
    vector<double> d(n+2);
    for(int i = 0; i <= n+1; i++)
    {
        d[i] = 1e15;
    }

    for(int i = 0; i <= n+1; i++)
    {
        for(int j = i+1; j <= n+1; j++)
        {
            cost[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j];
            if(cost[i][j] < 0) cost[i][j] = 0;
            cost[j][i] = cost[i][j];
        }
    }

    using P = pair<double, double>;
    priority_queue<P, vector<P>, greater<P>> que;
    d[0] = 0;
    que.push(P(0, 0));
    while(!que.empty())
    {
        P p = que.top();
        que.pop();
        double v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i <= n+1; i++)
        {
            if(d[i] > d[v] + cost[v][i])
            {
                d[i] = d[v] + cost[v][i];
                que.push(P(d[i], i));
            }
        }
    }
    printf("%.10f\n", d[n+1]);
}
