#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 1010;
const lli INF = 1000000000000000000LL;

int n;
int xs, ys;
int xt, yt;

int X[MAXN];
int Y[MAXN];
int R[MAXN];

double dist[MAXN];
double cost[MAXN][MAXN];

set< pair<double,int> > s;

void Dijsktra()
{
	for(int i = 1 ; i <= n ; i++)
		dist[i] = INF;

	for(int i = 0 ; i <= n ; i++)
		s.insert( { dist[i] , i } );

	while( !s.empty() )
	{
		int cur = s.begin()->second;
		s.erase( s.begin() );

		for(int i = 0 ; i <= n ; i++)
		{
			if( dist[i] > dist[cur] + cost[i][cur] )
			{
				s.erase( { dist[i] , i } );
				dist[i] = dist[cur] + cost[i][cur];
				s.insert( { dist[i] , i } );
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d",&X[0],&Y[0],&X[1],&Y[1]);
	scanf("%d",&n);

	n++;

	for(int i = 2 ; i <= n ; i++)
		scanf("%d %d %d",&X[i],&Y[i],&R[i]);

	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= n ; j++)
		{
			lli dx = X[i] - X[j];
			lli dy = Y[i] - Y[j];

			lli dist = dx*dx + dy*dy;

			cost[i][j] = sqrtl( dist );

			cost[i][j] -= R[i];
			cost[i][j] -= R[j];

			cost[i][j] = max( cost[i][j] , 0.0 );
		}
	}

	Dijsktra();

	printf("%.10f\n",dist[1]);
}
