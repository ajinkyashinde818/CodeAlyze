#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct s
{
    int x, y, r;
};
long double cost[1005];
struct z
{
    int idx;
    bool operator < (const z &o) const
    {
        return cost[idx] > cost[o.idx] ;
    }
};
s f;
s p[(int)1005];
long double dist(s x, s y)
{
    long double X = x.x-y.x;
    X*=X;
    long double Y = x.y-y.y;
    Y*=Y;
    X+=Y;
    X = sqrt(X);
    X -= x.r;
    X -= y.r;
    return max((long double) 0.0000,X);
}
int main()
{
    for(int i = 0 ; i < 1005; i++) cost[i] = 1e18;
    cin >>p[0].x >> p[0].y ;
    p[0].r = 0;
    cin >> f.x >> f.y;
    f.r = 0 ;
    int n ;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >>p[i].x >> p[i].y >> p[i].r;
    p[n+1].x = f.x;
    p[n+1].y = f.y;
    p[n+1].r = 0;
    priority_queue<z> pq;
    cost[0] = 0;
    pq.push({0});
    bool vis[1005] = {};
    while(!pq.empty())
    {
        z tp = pq.top();
        pq.pop();
        if(vis[tp.idx]) continue;
        vis[tp.idx] = 1;
//        cout << tp.idx << " " << tp.cost << endl;
        for(int i = 0 ; i <= n+1 ; i++)
        {
            if(i == tp.idx) continue;
            if(cost[i] > cost[tp.idx]+dist(p[i],p[tp.idx])>= 1e-13)
            {
                vis[i] = 0;
                cost[i] = cost[tp.idx]+dist(p[i],p[tp.idx]);
                pq.push({i});
            }
        }
    }
    cout << fixed << setprecision(13) << cost[n+1] << "\n";
}
