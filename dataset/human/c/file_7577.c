#include <stdio.h>
#define N 10000

int main(void)
{
	int a[N];
	int i=0, j;
	
	do{
		scanf("%d", &a[i]);
		i++;
	}while(a[i-1]!=0);
	
	for(j=0; j<i-1; j++){
		printf("Case %d: %d\n", j+1, a[j]);
	}
	return 0;
}
