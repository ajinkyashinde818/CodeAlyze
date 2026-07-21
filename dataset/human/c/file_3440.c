#include <stdio.h>
#define LL long long
#define maxn 200010
LL k,t;
int n,a[maxn],vis[maxn];
int main(){
	int i,nx,s,b,c;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	nx=1;
	while(1){
		vis[nx]=1,nx=a[nx];
		if(vis[nx]){s=nx;break;}
	}
	nx=s;
	for(i=1;i<=n;i++)vis[i]=0;
	while(1){
		vis[nx]=1,nx=a[nx],t++;
		if(vis[nx])break;
	}
	b=0,nx=1;
	while(1){
		if(nx==s)break;
		nx=a[nx],b++;
	}
	c=0;
	if(k<=b){
		nx=1;
		while(1){
			if(k==c)break;
			nx=a[nx],c++;
		}
		printf("%d\n",nx);
		return 0;
	}
	k-=b;k%=t;
	{
		nx=s;
		c=0;
		while(1){
			if(k==c)break;
			nx=a[nx],c++;
		}
		printf("%d\n",nx);
	}
}
