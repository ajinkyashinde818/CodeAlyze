#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int N;
struct edge{int to;double cost;};
vector<edge> G[100010];
double D[100010];
void dijkstra(int S){
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> que;
  rep(i,N+2) D[i]=1001001001001001;
  D[S]=0;
  que.push(mp(0,S));
  while(!que.empty()){
    PII P=que.top();
    que.pop();
    int X=P.second;
    if(D[X]<P.first) continue;
    rep(i,G[X].size()){
      edge E=G[X][i];
      if(D[E.to]>D[X]+E.cost){
        D[E.to]=D[X]+E.cost;
        que.push(mp(D[E.to],E.to));
      }
    }
  }
}

int main(){
  int X,Y,Z,W;
  cin>>X>>Y>>Z>>W;
  cin>>N;
  vector<double> A(N),B(N),C(N);
  rep(i,N) cin>>A[i]>>B[i]>>C[i];
  A.pb(X);
  A.pb(Z);
  B.pb(Y);
  B.pb(W);
  C.pb(0);
  C.pb(0);
  rep(i,N+2) rep(j,N+2){
    if(i==j) continue;
    double dis=sqrt((A[i]-A[j])*(A[i]-A[j])+(B[i]-B[j])*(B[i]-B[j]));
    double tmp=max(0.0,dis-C[i]-C[j]);
    edge E={(int)j,tmp};
    G[i].pb(E);
  }
  dijkstra(N);
  cout<<setprecision(10)<<D[N+1]<<endl;
}
