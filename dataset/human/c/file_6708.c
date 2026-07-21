#include<stdio.h>
int main(void){
	int n,m,i,j,h=0;
	int cnt=0;
	int a[100000],b[100000],flg[100000],bt[100000];
	int max=0;
	scanf("%d",&n);
	scanf("%d",&m);
	while(n!=0 && m!=0){
		cnt=0;
		h=0;
		max=0;
		for(i=1;i<=n;i++){
			flg[i]=0;
		}
		for(i=1;i<=m;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]==1){
				bt[h]=b[i];
				h++;
				max++;
			}
		}
		for(h=0;h<max;h++){
			flg[bt[h]]=2;
		}
		for(h=0;h<max;h++){
			for(i=1;i<=m;i++){
				if(a[i]==bt[h] && flg[b[i]]!=2){
					flg[b[i]]=1;
				}
				if(b[i]==bt[h] && flg[a[i]]!=2){
					flg[a[i]]=1;
				}
			}
		}
		for(i=2;i<=n;i++){
			if(flg[i]>0){
				//printf("%d=%d\n",i,flg[i]);
				cnt++;
			}
		}
		printf("%d\n",cnt);
		scanf("%d %d",&n,&m);
	}
	return 0;
}
