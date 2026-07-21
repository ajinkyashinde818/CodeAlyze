#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
typedef pair<double, int> pid;
vector<pid> e[maxn];
typedef pair<double, double> pdd;
double dist[maxn];
double r[maxn];
pdd c[maxn];
int s = 0, t = 1001;
#define y second
#define x first

double sqr(double x) {return x * x;}

double _(pdd a, pdd b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main()
{
	scanf("%lf%lf", &c[0].x, &c[0].y);
	scanf("%lf%lf", &c[t].x, &c[t].y);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= t; i++) dist[i] = 1e20;
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", &c[i].x, &c[i].y, &r[i]);
	c[n + 1] = c[t];
	t = n + 1;
	for (int i = 0; i <= t; i++)
		for (int j = 0; j <= t; j++)
			if (i != j)
				e[i].push_back(pid(max(0., _(c[i], c[j]) - r[i] - r[j]), j));
	priority_queue<pid, vector<pid>, greater<pid> > pq;
	pq.push(pid(dist[0] = 0, 0));
	while (!pq.empty())
	{
		auto tp = pq.top();pq.pop();
		if (tp.x > dist[tp.y]) continue;
		for (pid v : e[tp.y])
		{
			if (v.x + dist[tp.y] < dist[v.y])
			{
				dist[v.y] = v.x + dist[tp.y];
				pq.push(pid(dist[v.y], v.y));
			}
		}
	}
	printf("%.10f\n", dist[t]);
	return 0;
}
