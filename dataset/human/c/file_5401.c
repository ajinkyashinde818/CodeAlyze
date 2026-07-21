#include <stdio.h>
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)

int c[20];
int a[20][20];

int main(){
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++){
		scanf("%d",c+i);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	}
	
	int ans=1e9;
	for(int b=0;b<1<<n;b++){
		int temp[20]={};
		int cost=0;
		for(int i=0;i<n;i++)if(bit(b,i)){
			cost+=c[i];
			for(int j=0;j<m;j++)temp[j]+=a[i][j];
		}
		int flag=1;
		for(int j=0;j<m;j++)flag&=temp[j]>=x;
		if(flag)ans=min(ans,cost);
	}
	
	if(ans==1e9)puts("-1");
	else printf("%d",ans);
}
