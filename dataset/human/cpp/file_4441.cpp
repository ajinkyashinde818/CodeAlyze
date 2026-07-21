#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int n,ck=2,suma,sumb,tota,totb,fxor,ans,f[N],siz[N],a[N],b[N],lsha[N],lshb[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		lsha[i]=a[i];
		suma^=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		lshb[i]=b[i];
		sumb^=b[i];
		if(a[i]!=b[i])
			ans++;
	}
	if(!ans){
		puts("0");
		return 0;
	}
	++n;
	lsha[n]=a[n]=suma,lshb[n]=b[n]=sumb;
	sort(lsha+1,lsha+n+1);
	sort(lshb+1,lshb+n+1);
	for(int i=1;i<=n;i++){
		if(lsha[i]!=lshb[i]){
			puts("-1");
			return 0;
		}
	}
	tota=unique(lsha+1,lsha+n+1)-(lsha+1);
	for(int i=1;i<=tota;i++)
		siz[f[i]=i]=1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(lsha+1,lsha+tota+1,a[i])-lsha,b[i]=lower_bound(lsha+1,lsha+tota+1,b[i])-lsha;
		int fx=find(a[i]),fy=find(b[i]);
		if(fx!=fy){
			f[fx]=fy;
			siz[fy]+=siz[fx];
		}
	}
	if(a[n]==b[n]&&siz[find(a[n])]==1)
		ans++;
	for(int i=1;i<=n;i++){
		int fi=find(i);
		if(i==fi&&siz[fi]>1)
			ans++;
	}
	printf("%d",ans-1);
	return 0;
}
