#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int n,a[100005],b[100005],fa[100005];
pair<int,int> c[100005],d[100005];
int find(int k){
	if(fa[k]!=k) fa[k]=find(fa[k]);
	return fa[k];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[n+1]^=a[i];
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),b[n+1]^=b[i];
	for(int i=1;i<=n+1;i++) c[i]=make_pair(a[i],i),d[i]=make_pair(b[i],i);
	sort(c+1,c+n+2);
	sort(d+1,d+n+2);
	for(int i=1,cnt=0;i<=n+1;i++){
		if(i==1||c[i].first!=c[i-1].first) cnt++;
		a[c[i].second]=cnt;
		b[d[i].second]=cnt;
		if(c[i].first!=d[i].first){
			puts("-1");return 0;
		}
	}
	int sum=0,t=0;
	for(int i=1;i<=n;i++) if(a[i]!=b[i]){
		int x=find(a[i]),y=find(b[i]);
		if(!x) fa[a[i]]=a[i],x=a[i];
		if(!y) fa[b[i]]=b[i],y=b[i];
		fa[x]=y;
		sum++;
		if(b[i]==a[n+1]&&i<=n) t=1;
	}
	if(!sum) return puts("0"),0;
	int ans=0;
	for(int i=1;i<=n+1;i++) if(find(i)==i) ans++;
	printf("%d",ans+sum-t);
	return 0;
}
