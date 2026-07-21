#include<stdio.h>
int main (void)
{
	int i=0,j, array[10000];
	do{
		scanf("%d",&array[i]);
		i++;
	}
	while(array[i-1]!=0) ;
	for(j=1;j<i;j++){
		printf("Case %d: %d\n",j,array[j-1]);
	}
	return 0;
}
