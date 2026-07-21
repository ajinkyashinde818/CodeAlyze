#include <stdio.h>
#define n 10000
int main(void){
	int a[n];
	int i=1,j;
	while(i<=n){
		scanf("%d",&a[i]);
		if(a[i]==0)break;
		i++;
	}
	for(j=1;j<i;j++)printf("Case %d: %d\n",j,a[j]);
	return 0;
}
