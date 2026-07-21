#include<stdio.h>
int main(void)
{
	int n,a[200001],i,cnt,s,flg[200001],flg1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cnt=0; s=1; flg1=0;
	while(1){
		s=a[s];
		cnt++;
		if(s==2){
			flg1=1;
			break;
		}
		if(flg[s]==1) break;
		else flg[s]=1;
		
	}
	if(flg1==1) printf("%d\n",cnt);
	else printf("-1\n");
	return 0;
}
