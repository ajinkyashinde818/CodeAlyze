#include <stdio.h>
int main () {
	int n=1,k,i,sum=0;
	scanf("%d %d",&n,&k);
	int h[100000]={0};
	for (i=0;i<n;i++) {
		scanf("%d",&h[i]);
	}
	for (i=0;i<n;i++) {
		if(h[i]>=k) sum++;
	}
	printf("%d\n",sum);
	return 0;
}
