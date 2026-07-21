#include<stdio.h>
int main(void)
{
	int n,m;
	int a[10001],b[10001];
	int flg[10001];
	int i;
	int c;
	
	scanf("%d",&n);
	scanf("%d",&m);
	while(n!=0 && m!=0){
		c=0;
		for(i=2;i<=n;i++){
			flg[i]=0;
		}
		flg[1]=2;
		for(i=1;i<=m;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]==1){
				c++;
				flg[b[i]]=1;
			}
		}
		for(i=1;i<=m;i++){
			if(flg[a[i]]==1 && flg[b[i]]==0){
					c++;
					flg[b[i]]=2;
			}
		}
		for(i=1;i<=m;i++){
			if(flg[a[i]]==0 && flg[b[i]]==1){
					c++;
					flg[a[i]]=2;
			}
		}
		printf("%d\n",c);
		scanf("%d",&n);
		scanf("%d",&m);
	}
	return 0;
}
