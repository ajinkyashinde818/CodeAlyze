#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long double ld;

ld xs, ys, xt, yt;

int n;

ld x[1010],y[1010],r[1010];

typedef pair<ld,int> P;

vector<P> edges[1020];


void input()
{
	cin >> xs >> ys >> xt >> yt;

	cin >> n;

	x[0] = xs;
	y[0] = ys;

	x[n + 1] = xt;
	y[n + 1] = yt;

	for(int i = 1;i <= n;i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}

	cout << fixed << setprecision(10);
}

ld dist[1010];

ld zero = 0;

int main()
{
	input();

	for(int i = 0;i <= n + 1;i++)
	{
		for(int j = i + 1;j <= n + 1;j++)
		{
			ld dx = x[i] - x[j];
			ld dy = y[i] - y[j];
			ld len = sqrt(dx * dx + dy * dy);
			len = max(len - r[i] - r[j] , zero);
			edges[i].push_back(P(len,j));
			edges[j].push_back(P(len,i));

			cerr << i << "-" << j << "=" << len << endl;
		}
	}

	priority_queue<P,vector<P>,greater<P>> que;

	que.push(P(0,0));

	fill(dist,dist + 1010,1e11);

	while(!que.empty())
	{
		ld d = que.top().first;
		int v = que.top().second;
		que.pop();

		if(d > dist[v]) continue;

		for(P& p : edges[v])
		{
			if(d + p.first < dist[p.second])
			{
				dist[p.second] = d + p.first;
				que.push(P(dist[p.second],p.second));
			}
		}

	}

	cout << dist[n + 1] << endl;
	return 0;
}
