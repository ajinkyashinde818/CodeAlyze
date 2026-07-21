#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef pair<lld,int> P;
#define EPS 1e-9
#define sq(x) ((x)*(x))

int n;
lld xt,yt,xs,ys;
lld x[1111];
lld y[1111];
lld r[1111];

lld d[1111];
priority_queue<P,vector<P>,greater<P> > que;

int main(void){
  scanf("%Lf%Lf%Lf%Lf",&xt,&yt,&xs,&ys);
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    scanf("%Lf%Lf%Lf",x+i,y+i,r+i);
  }
  x[0] = xt;
  y[0] = yt;
  x[n+1] = xs;
  y[n+1] = ys;
  r[0] = r[n+1] = 0;
  n += 2;

  for(int i = 0; i < 1111; i++){
    d[i] = 1e11;
  }
  d[0] = 0.0;
  que.push(make_pair(0.0,0));
  while(!que.empty()){
    lld c = que.top().first;
    int v = que.top().second;
    que.pop();
    if(d[v]+EPS < c) continue;
    for(int i = 0; i < n; i++){
      if(i == v) continue;
      lld dd = max(0.0L,sqrt(sq(x[v]-x[i])+sq(y[v]-y[i]))-r[v]-r[i]);
      if(d[i] > d[v] + dd){
	d[i] = d[v] + dd;
	que.push(make_pair(d[i],i));
      }
    }
  }
  printf("%.10Lf\n",d[n-1]);
}
