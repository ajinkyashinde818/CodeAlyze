#include<stdio.h>
int main(void)
{
	int n,p[101],i,j,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(i=100;i>=1;i--){
		cnt=0;
		for(j=1;j<=n;j++){
			if(i<=p[j]){
				cnt++;
			}
		}
		if(cnt>=i)	break;
	}
	printf("%d\n",i);
	return 0;
}
