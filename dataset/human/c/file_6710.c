#include<stdio.h>
int main(void)
{
	int n,m,s[10001],x[10001],flg[10001],i,cnt;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		for(i=1;i<=m;i++){
			scanf("%d%d",&s[i],&x[i]);
		}
		for(i=1;i<=n;i++){
			flg[i]=0;
		}
		for(i=1;i<=m;i++){
			if(s[i]==1){
				flg[x[i]]=1;
			}
			if(x[i]==1){
				flg[s[i]]=1;
			}
		}
		for(i=1;i<=m;i++){
			if(flg[s[i]]==1 && flg[x[i]]==0){
				flg[x[i]]=2;
			}
			if(flg[x[i]]==1 && flg[s[i]]==0){
				flg[s[i]]=2;
			}
		}
		cnt=0;
		for(i=2;i<=n;i++){
			if(flg[i]==1||flg[i]==2){
				cnt++;
	//			printf("%d\n",i);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
