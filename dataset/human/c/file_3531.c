#include<stdio.h>
int main(void)
{
	int n,a[101];
	int cnt,max,i,j;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	max=1;
	for(i=1;i<=n;i++){
		cnt=0;
		for(j=1;j<=n;j++){
			if(i<=a[j]) cnt++;
		}
		if(cnt>=i&&max<i) max=i;
	}
	printf("%d\n",max);
}
