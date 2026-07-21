#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<queue>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
struct graph
{
    struct edge
    {
        int v; double w;
        edge(int v, double w):v(v),w(w){}
        bool operator>(const edge& other)const
        {
            return this->w > other.w;
        }
    };
    int n; 
    vector<vector<edge>> adj;
    graph(int n):n(n){ adj.resize(n); }
    void add_edge(int u, int v, double w)
    {
        adj[u].push_back(edge(v,w));
        adj[v].push_back(edge(u,w));
    }
    double SSSP(int s, int t)
    {
        vector<double> d(n,INF);
        vector<bool> vis(n,false);

        priority_queue<edge,vector<edge>,greater<edge>> frontier;
        frontier.push({s,0});
        d[s] = 0;

        while(!frontier.empty())
        {
            int u = frontier.top().v;
            frontier.pop();

            if(!vis[u])
            {
                vis[u] = true;
                for(const edge& e : adj[u])
                    if(d[u]+e.w < d[e.v])
                    {
                        d[e.v] = d[u]+e.w;
                        frontier.push({e.v,d[e.v]});
                    }
            }
        }
        return d[t];
    }
};
struct circle
{
    struct point
    {
        LL x, y; 
        point(){}
        point(LL x, LL y):x(x),y(y){}
        const point operator-(point& other)const
        {
            return point(this->x-other.x, this->y-other.y);
        }
        LL dist2() const
        {
            return x*x + y*y;
        }
        double dist() const
        {
            return sqrt(dist2());
        }
    };
    point c; LL r;
    circle():r(0){}
    circle(LL x, LL y, LL r):r(r){ c.x = x, c.y = y; }
};
double dist(circle& c1, circle& c2)
{
    // if r1 + r1 >= dist(c1,c2)
    if((c1.r+c2.r)*(c1.r+c2.r) >= (c1.c-c2.c).dist2())
        return 0;
    else
        return (c1.c-c2.c).dist() - (c1.r+c2.r);
}
int main()
{
    circle s, t;
    cin >> s.c.x >> s.c.y >> t.c.x >> t.c.y;

    int n; cin >> n;
    graph g(n+2);

    vector<circle> pt = {s}; pt.reserve(n+2);
    for(int u = 1; u <= n; u++)
    {
        LL x, y, r; cin >> x >> y >> r;
        pt.push_back(circle(x,y,r));
    }
    pt.push_back(t);

    for(int u = 0; u < n+2; u++)
        for(int v = u+1; v < n+2; v++)
            g.add_edge(u,v,dist(pt[u],pt[v]));  

    cout<<fixed<<setprecision(20)<<g.SSSP(0,n+1)<<endl;

    return 0;
}
