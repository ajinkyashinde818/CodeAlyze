#include<stdio.h>
int main(void)
{
	int i,j,n,p[100],w,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(i=n;i>=1;i--){
		cnt=0;
		for(j=1;j<=n;j++){
			if(p[j]>=i){
				cnt++;
			}
		}
		if(i<=cnt){
			break;
		}
	}
	printf("%d\n",i);
	return 0;
}
