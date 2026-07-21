#include<stdio.h>
int d[500];
int x[10000];
int y[10000];
int min(int a,int b){return a<b?a:b;}
int main(){
	int n,m,i;
	while(1){
	scanf("%d",&n);
	scanf("%d",&m);
	if(n==0)return 0;
	for(i=0;i<n;i++)d[i]=3;
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==1)d[b-1]=1;
		x[i]=a-1;
		y[i]=b-1;
	}
	for(i=0;i<m;i++){
		if(d[x[i]]==1)d[y[i]]=min(d[y[i]],2);
		if(d[y[i]]==1)d[x[i]]=min(d[x[i]],2);
	}
	int ans=0;
	for(i=1;i<n;i++)if(d[i]<=2)ans++;
	printf("%d\n",ans);
	}
}
