#include <bits/stdc++.h>

typedef long long ll;
const int MAXN = 1e5+10;
const double inf = 1e18+10;

using  namespace std;

double dis[1010][1010];

double x[MAXN],y[MAXN],r[MAXN];
int vis[1100];
double dds[MAXN];
double dist(double x,double y)
{
    return sqrt(x*x+y*y);
}
int main()
{
    int n;
    double sx,sy,px,py;
    cin>>sx>>sy>>px>>py;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    int st = n+1;
    int ed = n+2;
    dis[st][ed] = dist(sx-px,sy-py);
    for(int i = 1;i<=n;i++)
    {
        dis[i][st] = dis[st][i] = max(0.0, dist(x[i]-sx,y[i]-sy)-r[i]);
        dis[i][ed] = dis[ed][i] = max(0.0, dist(x[i]-px,y[i]-py)-r[i]);
        for(int j = 1;j<=n;j++)
        {
            dis[i][j]  = max(0.0, dist( (x[i]-x[j]),(y[i]-y[j]) )-r[i]-r[j]);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i = 1; i<= n+2;i++)
    {
        dds[i] = inf;
    }
    dds[st] = 0;
    int u = -1;

	for (int i = 1; i <= n+2; i++)
    {
        u = -1;
		for(int j = 1; j <= n+2; j++)
        {
			if (!vis[j] && ( u == -1 || dds[u] > dds[j]))
                u = j;
		}
		vis[u] = 1;
		for (int j = 1; j <= n+2; j++)
        {
            dds[j] = min(dds[j], dds[u] + dis[u][j]);
        }

	}
    printf("%.10f\n",dds[ed]);
    return 0;
}
