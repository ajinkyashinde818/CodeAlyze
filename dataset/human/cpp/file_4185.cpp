#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int x[1010], y[1010], r[1010];
int n;
double D[1010][1010];
double dis[1010];
int chk[1010];

void solve(){
	scanf("%d%d%d%d", x+1, y+1, x+2, y+2);
	scanf("%d", &n);
	for(int i=3;i<=n+2;i++)scanf("%d%d%d", x+i, y+i, r+i);
	n += 2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ll L = (ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]);
			if(L <= (ll)(r[i] + r[j]) * (r[i] + r[j]))D[i][j] = 0;
			else D[i][j] = sqrt(L) - r[i] - r[j];
		}
	}
	for(int i=2;i<=n;i++)dis[i] = 1e14;
	for(int i=1;i<=n;i++){
		int mn = -1;
		for(int j=1;j<=n;j++)if(chk[j] == 0){
			if(mn == -1 || dis[mn] > dis[j])mn = j;
		}
		for(int j=1;j<=n;j++)if(chk[j] == 0){
			if(dis[mn] + D[mn][j] < dis[j])dis[j] = dis[mn] + D[mn][j];
		}
		chk[mn] = 1;
	}
	printf("%.12f", dis[2]);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
