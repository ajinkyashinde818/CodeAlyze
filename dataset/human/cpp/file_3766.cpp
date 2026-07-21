//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll sx, sy, ex, ey;
int n;
pll a[2000];
ll r[2000];

double d[1005][1005];

double sq(double x){return x*x;}

double dis(pll x, pll y)
{
	return sqrt(sq(x.first-y.first)+sq(x.second-y.second));
}

double rd[1005];
int check[1005];
typedef pair<double, int> pdi;
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

int main()
{
	int i, j, k, l;
	cin>>sx>>sy>>ex>>ey;
	cin>>n;
	for(i=0;i<n;i++) scanf("%lld%lld%lld", &a[i].first, &a[i].second, &r[i]);
	for(i=0;i<n;i++) for(j=0;j<n;j++)
	{
		if(i == j) d[i][j]=0;
		else
		{
			double dx=dis(a[i], a[j]);
			if(dx >= r[i]+r[j]) d[i][j]=dx-r[i]-r[j];
			else d[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		double dx=dis(mp(sx, sy), a[i]);
		rd[i]=max(0., dx-r[i]);
		pq.emplace(rd[i], i);
	}
	while(pq.size())
	{
		int tar=pq.top().second;
		pq.pop();
		if(check[tar]) continue;
		check[tar]=1;
		for(i=0;i<n;i++)
		{
			if(!check[i] && rd[i] > rd[tar]+d[tar][i])
			{
				rd[i]=rd[tar]+d[tar][i];
				pq.emplace(rd[i], i);
			}
		}
	}
	double ans=dis(mp(sx, sy), mp(ex, ey));
	for(i=0;i<n;i++)
	{
		double dx=dis(mp(ex, ey), a[i]);
		ans=min(ans, rd[i]+max(0., dx-r[i]));
	}
	printf("%.20lf\n", ans);
	return 0;
}
//*/
