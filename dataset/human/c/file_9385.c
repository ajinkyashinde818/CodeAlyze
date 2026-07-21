#include <stdio.h>

int main(void) {
	int n,d,x,a[101],sum=0;
	scanf("%d%d%d",&n,&d,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=(d-1)/a[i]+1;
	}
	printf("%d",sum+x);
}
