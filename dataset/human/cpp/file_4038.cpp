#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

vector<pair<int,double> > way[SIZE];

int main(){
  int xs,ys,xt,yt;
  int n,x[SIZE],y[SIZE],r[SIZE];

  scanf("%d%d%d%d%d",&xs,&ys,&xt,&yt,&n); 
  
  for(int i=0;i<n;i++){
    scanf("%d%d%d",x+i,y+i,r+i);
  }
  x[n] = xs;
  y[n] = ys;
  x[n+1] = xt;
  y[n+1] = yt;
  r[n] = r[n+1] = 0;


  for(int i=0;i<n+2;i++){
    for(int j=i+1;j<n+2;j++){
      double dis = sqrt((ll)(x[i]-x[j])*(x[i]-x[j]) + (ll)(y[i]-y[j])*(y[i]-y[j]));
      
      dis = max(0.0, dis - r[i] - r[j]);

      way[i].push_back({j,dis});
      way[j].push_back({i,dis});
    }
  }

  priority_queue<pair<double,int> > pq;
  bool used[SIZE] = {};
  
  pq.push({0,n});
  
  while(pq.size()){
    pair<double,int> p = pq.top();
    pq.pop();

    double dis = p.first;
    int now = p.second;

    if(used[now]) continue;
    used[now] = true;
    
    if(now == n+1){
      if(abs(dis) < 1e-12){
        printf("%.10lf\n",0.0);
      }else{
        printf("%.10lf\n",-dis);
      }
      return 0;
    }

    for(int i=0;i<(int)way[now].size();i++){
      pq.push({dis-way[now][i].second, way[now][i].first});
    }
  }

  printf("-1");

  assert(false);
  
  return 0;
}
