#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
// typedef pair<int, int> P;
// typedef pair<ll, ll> PL;
const int mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
#define PI (acos(-1))

struct Dijkstra
{
    typedef pair<double, double> P;
    typedef pair<double, double> PL;

    ll n;
    vector<vector<pair<double, double>>> Edges;
    vector<double> Dist;
    vector<double> Prev;
    vector<double> PathNum;

    Dijkstra(double n) : n(n), Edges(n), Dist(n), Prev(n), PathNum(n)
    {
        Prev.assign(n, -1);
    };

    void add_edge(double a, double b, double c, bool directed = true)
    {
        if (directed)
        {
            Edges[a].emplace_back(make_pair(b, c));
        }
        else
        {
            Edges[a].emplace_back(make_pair(b, c));
            Edges[b].emplace_back(make_pair(a, c));
        }
    }

    void build(int start)
    {
        priority_queue<P, vector<P>, greater<P>> queue;
        fill(Dist.begin(), Dist.end(), (double)1e+15);
        Dist[start] = 0.0;
        PathNum[start] = 1.0;
        queue.push(PL(0, start));

        while (!queue.empty())
        {
            PL p = queue.top();
            queue.pop();
            double v = p.second;
            if (Dist[v] < p.first)
                continue;

            for (int i = 0; i < Edges[v].size(); i++)
            {
                PL e = Edges[v][i];
                if (Dist[e.first] > Dist[v] + e.second)
                {
                    Dist[e.first] = Dist[v] + e.second;
                    queue.push(P(Dist[e.first], e.first));

                    Prev[e.first] = v;

                    PathNum[e.first] = PathNum[v];
                }
                else if (Dist[e.first] == Dist[v] + e.second)
                {
                    PathNum[e.first] += PathNum[v];
                    //PathNum[e.first] %= MOD;
                }
            }
        }
    }

    double dist(double t)
    {
        return Dist[t];
    }

    vector<double> get_path(double t)
    {
        vector<double> path;
        for (; t != -1; t = Prev[t])
        {
            path.push_back(t);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    double get_path_num(double t)
    {
        return PathNum[t];
    }

};

double x[1010],y[1010],r[1010];
int solve()
{
    double xs, ys, xt, yt;
    ll n;
    cin >> xs >> ys >> xt >> yt >> n;
    Dijkstra di(n+3);
    for(int i=0; i < n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    x[n] = xs;
    y[n] = ys;
    r[n] = 0.0;
    x[n+1] = xt;
    y[n+1] = yt;
    r[n+1] = 0.0;
    // double xd = abs(x[n] - x[n+1]);
    // double yd = abs(y[n] - y[n+1]);
    // double ans = sqrt(xd * xd + yd * yd);
    for (int i = 0; i < n + 2; i++)
    {
        for(int j=0; j < n+2; j++){
            if(i == j)
                continue;
            double xd = abs(x[i] - x[j]);
            double yd = abs(y[i] - y[j]);
            double d = sqrt(xd * xd + yd *yd) - r[i] - r[j];
            if(d < 0){
                d = 0;
            }
            di.add_edge(i, j, d,false);
        }
    }

    di.build(n);
    cout << di.dist(n + 1) << endl;

    return 0;
}

int main()
{
    cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
