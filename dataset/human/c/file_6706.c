#include<stdio.h>
int main(void)
{
	int n,m,i,j,cnt,flg;
	int a[10001],b[10001],flgk[501];
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		cnt=0; flg=0;
		for(i=1;i<=n;i++) flgk[i]=0;
		for(i=1;i<=m;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]==1){
				cnt++; flgk[b[i]]=1;
				flgk[a[i]]=1;
			}
			if(b[i]==1){
				cnt++; flgk[a[i]]=1;
				flgk[b[i]]=1;
			}	
		}
		if(cnt==0) flg=1;
		if(flg==0){
			for(i=1;i<=n;i++){
				if(flgk[i]==1){
					for(j=1;j<=m;j++){
						if(i==a[j]&&flgk[b[j]]==0){
							flgk[b[j]]=2;
							cnt++;
						}
					}
					for(j=1;j<=m;j++){
						if(i==b[j]&&flgk[a[j]]==0){
							flgk[a[j]]=2;
							cnt++;
						}
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
