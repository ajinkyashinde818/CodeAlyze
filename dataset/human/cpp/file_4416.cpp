#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;

const int N=200005;

int n,sz,ans;
int a[N],b[N],c[N];
bool vis[N];
map<int,int> c1,c2;
vector<int> lev[N];

void dfs(int k){
	int j;
	vis[k]=1;
	for (j=0;j<lev[k].size();j++)
		if (!vis[lev[k][j]]) dfs(lev[k][j]);
}

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),a[n+1]^=a[i];
	for (i=1;i<=n;i++) scanf("%d",&b[i]),b[n+1]^=b[i];
	n++;
	for (i=1;i<=n;i++) c1[a[i]]++;
	for (i=1;i<=n;i++) c2[b[i]]++;
	for (i=1;i<=n;i++) if (c1[a[i]]!=c2[a[i]]){
		printf("-1\n");
		return 0;
	}
	for (i=1;i<=n;i++) c[++sz]=a[i];
	for (i=1;i<=n;i++) c[++sz]=b[i];
	sort(c+1,c+1+sz); sz=unique(c+1,c+1+sz)-c-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(c+1,c+1+sz,a[i])-c;
	for (i=1;i<=n;i++) b[i]=lower_bound(c+1,c+1+sz,b[i])-c;
	for (i=1;i<n;i++) if (a[i]!=b[i]){
		lev[a[i]].push_back(b[i]);
		ans++;
	}
	lev[a[n]].push_back(b[n]);
	if (!ans){
		printf("0\n");
		return 0;
	}
	for (i=1;i<=n;i++)
		if (!vis[a[i]]&&lev[a[i]].size()){
			dfs(a[i]);
			ans++;
		}
	printf("%d\n",ans-1);
	return 0;
}
