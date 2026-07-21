#include <stdio.h>

int main (void)
{
	int a[10000];
	int i;

	for(i=0;i<10000;i++){
		scanf("%d", &a[i]);
		if (a[i]==0) break;
	}
	
	i=0;
	while(a[i]!=0){
		printf("Case %d: %d\n",i+1,a[i]);
		i++;
	}

	return 0;
}
