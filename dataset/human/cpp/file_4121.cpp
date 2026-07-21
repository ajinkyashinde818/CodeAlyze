#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1005;

int n; 
pi a[MAXN];
int r[MAXN];
bool vis[MAXN];
double dis[MAXN];

double cost(int x, int y){
	return max(hypot(a[x].second - a[y].second, a[x].first - a[y].first) - r[x] - r[y], 0.0);
}

int main(){
	scanf("%d %d %d %d",&a[0].first,&a[0].second,&a[1].first,&a[1].second);
	scanf("%d",&n);
	for(int i=2; i<=n+1; i++){
		scanf("%d %d %d",&a[i].first,&a[i].second,&r[i]);
	}
	fill(dis, dis + n + 2, 1e18);
	dis[0] = 0;
	while(true){
		int x = -1;
		double k = 1e18;
		for(int j=0; j<n+2; j++){
			if(!vis[j] && k > dis[j]){
				k = dis[x = j];
			}
		}
		vis[x] = 1;
		if(x == 1){
			printf("%.10f\n", dis[1]);
			return 0;
		}
		for(int j=0; j<n+2; j++) dis[j] = min(dis[j], dis[x] + cost(x, j));
	}
}
