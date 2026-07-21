#include<cstdio>
#include<algorithm>
using namespace std;
int a[100100];
int b[100100];
int c[100100],d[100100];
int f[100100];
bool vis[100100];
int fa(int x){
	if(f[x]==x) return x;
	return f[x]=fa(f[x]);
}
int main(){
//	freopen("D.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[n+1]^=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[n+1]^=b[i];
	}
	for(int i=1;i<=n+1;i++)
		c[i]=a[i],d[i]=b[i];
	sort(c+1,c+n+2);
	sort(d+1,d+n+2);
	for(int i=1;i<=n+1;i++){
		if(c[i]!=d[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n+1;i++)
		f[i]=i;
	for(int i=1;i<=n+1;i++)
	{
		a[i]=lower_bound(c+1,c+n+2,a[i])-c;
		b[i]=lower_bound(d+1,d+n+2,b[i])-d;
	}
	int ans=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=b[i])
		{
			f[fa(a[i])]=fa(b[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])
		{
			ans++;
			if(!vis[fa(a[i])]){
				if(fa(a[n+1])!=fa(a[i]))
					ans++;
				vis[fa(a[i])]=1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
