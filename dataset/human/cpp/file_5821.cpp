#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define repp(i, n) for(int i=1;i<=n;i++)
#define all(x) x.begin(), x.end()

#define geti1(X) scanf("%d",&X)
#define geti2(X,Y) scanf("%d%d",&X,&Y)
#define geti3(X,Y,Z) scanf("%d%d%d",&X,&Y,&Z)
#define geti4(X,Y,Z,W) scanf("%d%d%d%d",&X,&Y,&Z,&W)

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define geti(...) GET_MACRO(__VA_ARGS__, geti4, geti3, geti2, geti1) (__VA_ARGS__)

#define INF 987654321
#define IINF 987654321987654321

int N; ll C;
ll x[100500], v[100500];
ll lsum[100500], rsum[100500];
ll lmx[100500], rmx[100500];


int main(){
	ios::sync_with_stdio(false);
	cin >> N >> C;
	repp(i,N) cin >> x[i] >> v[i];

	ll ans = 0;
	ll sum = 0; 
	for(int i=1;i<=N;i++) lsum[i] = lsum[i-1] + v[i];
	for(int i=N;i>=1;i--) rsum[i] = rsum[i+1] + v[i];

	for(int i=1;i<=N;i++) ans = max(ans, lsum[i] - x[i]);
	for(int i=N;i>=1;i--) ans = max(ans, rsum[i] - (C-x[i]));


	for(int i=1;i<=N;i++) lmx[i] = max(lmx[i-1], lsum[i] - x[i]);
	for(int i=N;i>=1;i--) rmx[i] = max(rmx[i+1], rsum[i] - (C-x[i]) );
	for(int i=1;i<=N;i++) ans = max(ans, lsum[i] - x[i] + rmx[i+1] - x[i] );
	for(int i=N;i>=1;i--) ans = max(ans, rsum[i] - (C-x[i]) + lmx[i-1] - (C-x[i]) );


	
	cout << ans << endl;

}
