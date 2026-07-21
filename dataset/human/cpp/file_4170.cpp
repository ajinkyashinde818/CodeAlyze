#include <bits/stdc++.h>
     
using namespace std;

double dist[1005];
struct circle
{
	double x,y,r;
};
const double INF = 1e12;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	double sx,sy,ex,ey;
	circle c;
	vector <circle> v;
	int n;

	cin >> sx >> sy >> ex >> ey;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> c.x >> c.y >> c.r;
		v.push_back(c);
	}

	c.x = sx;
	c.y = sy;
	c.r = 0;
	v.push_back(c);
	c.x = ex;
	c.y = ey;
	c.r = 0;
	v.push_back(c);

	fill(dist,dist+1005,INF);
	dist[n] = 0;
	priority_queue <pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pque;
	pque.push(make_pair(dist[n],n));

	while(!pque.empty())
	{
		int now = pque.top().second;
		if(pque.top().first > dist[now])
		{
			pque.pop();
			continue;
		}
		pque.pop();

		for(int i=0;i<v.size();i++)
		{
			double d = ((v[i].x - v[now].x)*(v[i].x - v[now].x) + (v[i].y - v[now].y)*(v[i].y - v[now].y));
			double rr = v[i].r + v[now].r;
			d = sqrt(d);
			d-=rr;
			if(d<0)
			{
				d = 0;
			}
			if(dist[i] > dist[now] + d)
			{
				dist[i] = dist[now] + d;
				pque.push(make_pair(dist[i],i));
			}
		}
	}

	cout << fixed;
	cout.precision(16);

	cout << dist[n+1] << '\n';

	return 0;
}
