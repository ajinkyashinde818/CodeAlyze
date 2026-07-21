#include<stdio.h>
int main()
{
	int n,m,a[10001]={0},b[10001]={0},i,j,yobu;
	while(1){
		int fla[501]={0},flb[501]={0},f;
		yobu=0,f=0;
		scanf("%d",&n);
		scanf("%d",&m);
		if(n==0 && m==0)break;
		for(i=0;i<m;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]==1){
				fla[b[i]]=1,flb[b[i]]=1;
			}
		}
		for(i=0;i<m;i++){
			if(a[i]!=1){
				for(j=2;j<=n;j++){
					if(fla[j]==1 && fla[a[i]]==1)flb[b[i]]=1;
					if(fla[j]==1 && fla[b[i]]==1)flb[a[i]]=1;
				}
			}
		}
		for(i=2;i<=n;i++)if(flb[i]==1)++yobu;
		printf("%d\n",yobu);
	}
	return 0;
}
