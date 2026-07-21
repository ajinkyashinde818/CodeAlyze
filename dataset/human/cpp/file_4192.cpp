#include <cmath>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>

using namespace std;

#define ll long long int
#define pll pair<double,ll>

string s;
ll xs, ys, xt, yt;
int N;
priority_queue<pll, vector<pll>, std::greater<pll>> q;
vector<pll> g[2000];
ll x[2000];
ll y[2000];
ll r[2000];
bool visit[2000];

int main()
{
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> x[i];
        cin >> y[i];
        cin >> r[i];
    }
    fill(visit, visit + 2000, false);
    x[0] = xs;
    y[0] = ys;
    r[0] = 0;
    x[N+1] = xt;
    y[N+1] = yt;
    r[N+1] = 0;
    for(int i = 0;i <= N;i++)
    {
        for(int j = i + 1;j <= N+1;j++)
        {
            if(i == j)
            {
                continue;
            }
            auto dx = x[j] - x[i];
            auto dy = y[j] - y[i];
            auto d = dx * dx + dy * dy;
            auto rSum = r[j] + r[i];
            auto diff = sqrt(d) - rSum;
            auto dist = max(diff, 0.0);
            g[i].push_back(make_pair(dist, j));
            g[j].push_back(make_pair(dist, i));
        }
    }
    for(int i = 0;i <= N+1;i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        auto t = q.top();
        q.pop();
        if(visit[t.second])
        {
            continue;
        }
        visit[t.second] = true;
        if(t.second == N+1)
        {
            cout << std::fixed;
            cout << setprecision(11);
            cout << t.first << endl;
            return 0;
        }
        for(auto& e : g[t.second])
        {
            if(visit[e.second])
            {
                continue;
            }
            double d = t.first + e.first;
            q.push(make_pair(d, e.second));
        }
    }
    return 0;
}
