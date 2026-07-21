#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

using ll = long long;

struct point
{
	ll x, y;
};

double dist(point a, point b, int rr)
{
	auto ret = sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) - rr;
	if (ret < 0)return 0.0;
	return (double)ret;
}

struct circle
{
	point center;
	ll radius;
};
circle cc[1234];
ll n;
struct edge
{
	ll to;
	double cost;
};
vector<edge>graph[1234];
double memo[1234];
double dijkstra()
{
	fill(memo, memo + 1234, 1e18);
	memo[0] = 0.0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>que;
	que.push({ 0.0,0 });
	while (!que.empty())
	{
		auto pp = que.top();
		que.pop();
		int nowv = pp.second;
		if (memo[nowv] < pp.first)continue;
		for (auto ed : graph[nowv])
		{
			if (memo[ed.to] > memo[nowv] + ed.cost)
			{
				memo[ed.to] = memo[nowv] + ed.cost;
				que.push({ memo[ed.to],ed.to });
			}
		}
	}
	return memo[n + 1];
}

int main(void)
{
	ll xs, ys, xt, yt;
	scanf("%lld %lld %lld %lld", &xs, &ys, &xt, &yt);
	scanf("%lld", &n);
	cc[0] = { {xs,ys},0 };
	cc[n + 1] = { {xt,yt},0 };
	for (int i = 0; i < n; ++i)
	{
		ll x, y, r;
		scanf("%lld %lld %lld", &x, &y, &r);
		cc[i + 1] = { {x,y},r };
	}
	for (int i = 0; i <= n + 1; ++i)
	{
		for (int j = 0; j <= n + 1; ++j)
		{
			if (i == j)continue;
			double cost = dist(cc[i].center, cc[j].center, cc[i].radius + cc[j].radius);
			graph[i].push_back({ j,cost });
			//graph[j].push_back({ i,cost });
		}
	}
	double ans = dijkstra();
	printf("%.12lf\n", ans);
	return 0;
}
