#include <stdio.h>
#include <cstdio>
int main(){
	int input[10000],i,j;
	i=0;
	do {
		scanf("%d",&input[i]);
		i++;
	}while (input[i-1]!=0);
	for(j=1;j<=i-1;j++){
		printf("Case %d: %d\n",j,input[j-1]);
	}
	return 0;
}
