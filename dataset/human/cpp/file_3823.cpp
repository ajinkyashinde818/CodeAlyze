#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 20;
int vis[maxn],n;
double x[maxn],y[maxn],r[maxn],dist[maxn],mp[maxn][maxn];

void SPFA(int s)
{
    queue<int>q;
    for(int i = 1;i <= n;i++) dist[i] = 1e10;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dist[s] = 0;
    vis[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for(int i = 1;i <= n;i++)
        {
            if(dist[i] > dist[v] + mp[v][i])
            {
                dist[i] = dist[v] + mp[v][i];
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2]) != EOF)
    {
        scanf("%d",&n);
        n += 2;
        r[1] = r[2] = 0;
        mp[1][2] = mp[2][1] = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]));
        for(int i = 3;i <= n;i++)
        {
            scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                mp[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                mp[i][j] -= r[i] + r[j];
                if(mp[i][j] < 0)
                {
                    mp[i][j] = 0;
                }
            }
        }
        SPFA(1);
        printf("%.10f\n",dist[2]);
    }
    return 0;
}
