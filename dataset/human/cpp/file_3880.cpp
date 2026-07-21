#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<double,int> pdi;
struct cir {
    ll x, y, r;
    cir(){x=y=r=0;}
    cir(ll x, ll y, ll r):x(x),y(y),r(r){}
};

cir arr[1100];
double dist[1100][1100];
double dd[1100];
bool visit[1100];
const double eps = 1e-10;
int n;

double mabs(double a) {return a<0?-a:a;}
double dis(cir a, cir b) {
    return max(sqrt(max(0.0,1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))-a.r-b.r,0.0);
}

int main() {
    int i, j;

    scanf("%lld%lld%lld%lld",&arr[0].x,&arr[0].y,&arr[1].x,&arr[1].y);
    scanf("%d",&n);
    for (i=2;i<n+2;i++) scanf("%lld%lld%lld",&arr[i].x,&arr[i].y,&arr[i].r);
    n+=2;
    for (i=0;i<n;i++) {
        dist[i][i] = 0.0;
        for (j=i+1;j<n;j++) {
            dist[i][j] = dist[j][i] = dis(arr[i],arr[j]);
        }
    }
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    for (i=0;i<n;i++) dd[i] = 1e18;
    dd[0] = 0; pq.push(pdi(0,0));
    while(!pq.empty()) {
        pdi tmp = pq.top();
        pq.pop();
        int here = tmp.second;
        visit[here] = true;
        double d = tmp.first;
        if (mabs(dd[here]-d)>eps) continue;
        for (i=0;i<n;i++) {
            if (visit[i]) continue;
            if (dd[i]>eps+dd[here]+dist[here][i]) {
                dd[i]=dd[here]+dist[here][i];
                pq.push(pdi(dd[i],i));
            }
        }
    }
    printf("%.15lf\n",dd[1]);

    return 0;
}
