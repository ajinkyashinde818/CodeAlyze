#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

const int maxn=1005;
const double eps=1e-8;

struct edge {
    int next,to;
    double dist;
};

struct node {
    double x,y,r;
} p[maxn];

int fr[maxn];
int inq[maxn];
double ds[maxn];
edge e[maxn*maxn*4];
int tote=0;

inline int dcmp(double x) {
    if(fabs(x)<eps) return 0;
    return x>0?1:-1;
}

inline void addone(int u,int v,double w) {
    ++tote;e[tote].next=fr[u];fr[u]=tote;e[tote].to=v;e[tote].dist=w;
}

inline double euDist(double xi,double xj,double yi,double yj) {
    return sqrt((xj-xi)*(xj-xi)+(yj-yi)*(yj-yi));
}

inline double getDist(int i,int j) {
    if(dcmp(euDist(p[i].x,p[j].x,p[i].y,p[j].y)-p[i].r-p[j].r)<=0) return 0;
    return euDist(p[i].x,p[j].x,p[i].y,p[j].y)-p[i].r-p[j].r;
}

int q[maxn*maxn*4];

int main() {
    read(p[1].x);read(p[1].y);p[1].r=0;
    read(p[2].x);read(p[2].y);p[2].r=0;
    int n;
    read(n);
    REP(i,1,n) read(p[i+2].x),read(p[i+2].y),read(p[i+2].r);
    n+=2;
    memset(fr,-1,sizeof(fr));
    REP(i,1,n) REP(j,1,n) addone(i,j,getDist(i,j));
    REP(i,1,n) ds[i]=1e12;
    ds[1]=0;inq[1]=1;
    int l=1,r=0;q[++r]=1;
    for(;l<=r;) {
        int x=q[l++];inq[x]=0;
        RAL(i,x) if(dcmp(ds[e[i].to]-ds[x]-e[i].dist)>0) {
            ds[e[i].to]=ds[x]+e[i].dist;
            if(!inq[e[i].to]) {
                inq[e[i].to]=1;q[++r]=e[i].to;
            }
        }
    }
    printf("%.10lf\n",ds[2]);
    return 0;
}
