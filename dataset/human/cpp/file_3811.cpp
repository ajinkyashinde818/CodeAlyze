#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double > pdd;
typedef pair<int,pii > pipdd;
typedef pair<int,double> pid;
typedef pair<pii,pdd> ppiipdd;

typedef pair<double,int> pdi;

vector<ppiipdd> V;
vector<pid> G[1010];

int N;
double sx,sy,gx,gy;
double D[1010];

int main()
{
    scanf("%lf%lf%lf%lf",&sx,&sy,&gx,&gy);
    scanf("%d",&N);
    for(int i = 0; i < N + 2; i++)
    {
        D[i] = -1;
    }
    V.push_back(make_pair(make_pair(N,0),make_pair(sx,sy)));
    V.push_back(make_pair(make_pair(N + 1,0),make_pair(gx,gy)));
    for(int i = 0; i < N; i++)
    {
        double x,y;
        int r;
        scanf("%lf%lf%d",&x,&y,&r);
        V.push_back(make_pair(make_pair(i,r),make_pair(x,y)));
    }
    for(int i = 0; i < V.size(); i++)
    {
        for(int j = i; j < V.size(); j++)
        {
            double x = (V[i].second.first - V[j].second.first) * (V[i].second.first - V[j].second.first);
            double y = (V[i].second.second - V[j].second.second) * (V[i].second.second - V[j].second.second);
            double length = max(0.0,sqrt(x + y) - (double)V[i].first.second - (double)V[j].first.second);
            G[V[i].first.first].push_back(make_pair(V[j].first.first,length));
            G[V[j].first.first].push_back(make_pair(V[i].first.first,length));
        }
    }
    priority_queue<pdi ,vector<pdi>,greater<pdi> >  Q;
    Q.push(make_pair(0,N));
    while(Q.size())
    {
        pdi now = Q.top();
        Q.pop();
        if(D[now.second] != -1)
        {
            continue;
        }
        D[now.second] = now.first;
        for(int i = 0; i < G[now.second].size(); i++)
        {
            Q.push(make_pair(now.first + G[now.second][i].second,G[now.second][i].first));
        }
    }
    printf("%.10lf\n",D[N + 1]);
    return 0;
}
