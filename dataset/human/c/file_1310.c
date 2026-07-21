#include<stdio.h>
int n,m,f,i,a,b,x[200000],y[2000000];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a==1)x[b]=1;
		if(b==n)y[a]=1;
	}
	f=0;
	for(i=1;i<=n+1;i++){
		//printf("%d %d\n",x[i],y[i]);
		if((x[i]==1)&&(y[i]==1)){
			f=1;
			puts("POSSIBLE");
			break;
		}
	}
	
	if(f==0){
		puts("IMPOSSIBLE");
	}
	
	return 0;
}
