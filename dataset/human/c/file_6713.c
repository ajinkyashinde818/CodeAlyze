#include<stdio.h>
int a[10000],b[10000];
int main(void)
{
int n,k,i,c,x[501];
	while(1){
		c=0;
		scanf("%d",&n);
		scanf("%d",&k);
		if(n==0&&k==0){
			break;
		}
		for(i=0;i<=n;i++){
			a[i]=0;
			b[i]=0;
			x[i]=0;
		}
		x[1]=1;
		for(i=0;i<k;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]==1){
				x[b[i]]=1;
				c++;
			}
		}
		for(i=0;i<k;i++){
			if(x[a[i]]==1&&x[b[i]]==0){
				x[b[i]]=3;
				c++;
			}
			if(x[b[i]]==1&&x[a[i]]==0){
				x[a[i]]=3;
				c++;
			}
		}
		printf("%d\n",c);
		}
return 0;
}
