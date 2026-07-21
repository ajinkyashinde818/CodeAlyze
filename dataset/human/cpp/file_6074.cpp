#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <iostream>

using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)	   for(int i = 0; i < (n); ++i)
#define all(c)		   begin(c), end(c)
#define rall(c)		   rbegin(c), rend(c)
#define SZ(a)		   ((ll) a.size())

typedef long long		   ll;
typedef unsigned long long ull;


int main(){
  ll N,C;
  cin >> N >> C;
  vector<ll> x(N+2,0);
  vector<ll> v(N+2,0);
  rep(i,N) scanf("%lld %lld",&x[i+1],&v[i+1]);
  x[N+1]=C;

  vector<ll> A(N+1,0);
  vector<ll> B(N+1,0);
  vector<ll> maA(N+1,0);
  vector<ll> maB(N+1,0);
  vector<ll> X(N+1,0);
  vector<ll> Y(N+1,0);
  rep(i, N) A[i+1] = A[i] + v[i+1] - (x[i+1]-x[i]);
  rep(i, N) B[i+1] = B[i] + v[N-i] - ((C-x[N-i])-(C-x[N-i+1]));

  rep(i,N) maA[i+1] = max(maA[i],A[i+1]);
  rep(i,N) maB[i+1] = max(maB[i],B[i+1]);
  rep(i,N) X[i+1] = A[i+1] - x[i+1] + maB[N-i-1];
  rep(i,N) Y[i+1] = B[i+1] - (C-x[N-i]) + maA[N-i-1];
  cout << max(max(*max_element(all(A)),*max_element(all(B))),max(*max_element(all(X)),*max_element(all(Y))));

}
