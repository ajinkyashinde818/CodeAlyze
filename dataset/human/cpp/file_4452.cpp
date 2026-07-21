#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
using namespace std;

const int maxn=100010;
int n;
int a[maxn], b[maxn];
int s;
map<int,int> mp;
vector<int> g[maxn];
int ans;
int vis[maxn];

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}

int res;
int num[maxn], cnt;
int main(){

	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), s^=a[i], mp[a[i]]++;
	mp[s]++;
	for(int i=1;i<=n;i++) num[++cnt]=a[i];
	num[++cnt]=s;
	sort(num+1,num+1+cnt);
	cnt=unique(num+1, num+1+cnt)-num-1;
	for(int i=1;i<=n;i++){
		scanf("%d", &b[i]);
		if(!mp.count(b[i])){ puts("-1"); return 0; }
		if(!mp[ b[i] ]){ puts("-1"); return 0; }
		mp[ b[i] ]--;
	}
	for(int i=1;i<=n;i++) if(mp[ a[i] ]) res=a[i];
	if(!res) res=s;
	int x, y;
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]) continue;
		ans++;
		x=lower_bound(num+1, num+1+cnt, a[i])-num;
		y=lower_bound(num+1, num+1+cnt, b[i])-num;
		g[x].push_back(y);
	}
	x=lower_bound(num+1, num+1+cnt, s)-num;
	y=lower_bound(num+1, num+1+cnt, res)-num;
	g[x].push_back(y); ans++;
	// printf("%d\n", ans);
	for(int i=1;i<=cnt;i++){
		if(!vis[i] && g[i].size()) dfs(i), ans++;
	}
	printf("%d", ans-2);
	return 0;
}
