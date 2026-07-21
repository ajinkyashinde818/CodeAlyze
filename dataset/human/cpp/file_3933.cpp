#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

typedef long double dbl;
typedef long long int lli;

const dbl inf = 170705091707.00;

vector<vector<lli>> A;
vector<vector<dbl>> graph;
vector<dbl> D;

dbl dist(lli a, lli b)
{
	dbl res = sqrt((A[a][0]-A[b][0])*(A[a][0]-A[b][0])+(A[a][1]-A[b][1])*(A[a][1]-A[b][1]));
	return max(dbl(0.00), res-A[a][2]-A[b][2]);
}

int main(void)
{
	lli n, xs, ys, xt, yt;
	scanf("%lld%lld%lld%lld%lld", &xs, &ys, &xt, &yt, &n);
	A.clear(); A.resize(n+2, vector<lli>(3));
	graph.clear(); graph.resize(n+3, vector<dbl>(n+3));
	D.clear(); D.resize(n+3, inf);
	A[0][0] = xs; A[0][1] = ys;
	A[n+1][0] = xt; A[n+1][1] = yt;
	A[0][2] = A[n+1][2] = 0;
	for(lli i = 1;i <= n;i++)
	{
		scanf("%lld%lld%lld", &A[i][0], &A[i][1], &A[i][2]);
	}
	
	for(lli i = 0;i < n+2;i++)
	{
		for(lli j = 0;j < n+2;j++)
		{
			if(i != j)
			{
				graph[i][j] = dist(i, j);
				//cout << i << " " << j << " " << graph[i][j] << "\n";
			}
		}
	}

	set<pair<dbl, lli>> Q;
	D[0] = 0.00;
	Q.insert({D[0], 0});

	while(!Q.empty())
	{
		pair<dbl, lli> top = *Q.begin();
		//cout << top.second << "\n";
		Q.erase(Q.begin());

		for(lli i = 0;i < n+2;i++)
		{
			if(D[i] > top.first+graph[top.second][i])
			{
				if(D[i] != inf) Q.erase({D[i], i});
				D[i] = top.first+graph[top.second][i];
				Q.insert({D[i], i});
			}
		}
	}

	printf("%.20Lf\n", D[n+1]);
}
