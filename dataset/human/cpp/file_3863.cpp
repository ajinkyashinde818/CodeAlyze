#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

double DP1[1005];
double DP2[1005];

double doublemax(double a, double b){
  if(a>b) return a;
  else return b;
}

double doublemin(double a, double b){
  if(a>b) return b;
  else return a;
}

int main() {
  double xs, ys, xt, yt;
  cin>>xs>>ys>>xt>>yt;
  int N;
  cin>>N;
  double x[N], y[N], r[N];
  for(int i=0;i<N;++i){
    cin>>x[i]>>y[i]>>r[i];
  }
  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que1, que2;
  for(int i=0;i<N;++i){
    que1.push(mp(doublemax(0, sqrt(pow(xs-x[i], 2) + pow(ys-y[i], 2))-r[i]), i));
    que2.push(mp(doublemax(0, sqrt(pow(xt-x[i], 2) + pow(yt-y[i], 2))-r[i]), i));
  }
  map<int, int> amap1, amap2;
  int num;
  double dist;
  while(!que1.empty()){
    dist = que1.top().fi;
    num = que1.top().se;
    que1.pop();
    if(amap1[num]>0) continue;
    DP1[num] = dist;
    amap1[num]++;
    for(int i=0;i<N;++i){
      if(amap1[i]>0) continue;
      que1.push(mp(dist+doublemax(0, sqrt(pow(x[num]-x[i], 2)+pow(y[num]-y[i], 2))-r[num]-r[i]), i));
    }
  }
  while(!que2.empty()){
    dist = que2.top().fi;
    num = que2.top().se;
    que2.pop();
    if(amap2[num]>0) continue;
    DP2[num] = dist;
    amap2[num]++;
    for(int i=0;i<N;++i){
      if(amap2[i]>0) continue;
      que2.push(mp(dist+doublemax(0, sqrt(pow(x[num]-x[i], 2)+pow(y[num]-y[i], 2))-r[num]-r[i]), i));
    }
  }
  double ans = DP1[0]+DP2[0];
  for(int i=1;i<N;++i){
    ans = doublemin(ans, DP1[i]+DP2[i]);
  }
  cout<<setprecision(20)<<doublemin(ans, sqrt(pow(xs-xt, 2)+pow(ys-yt, 2)))<<endl;
}
