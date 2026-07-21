#include <stdio.h>
int main(void){
	int x[10000] ,i = 1,j ;
	scanf("%d",&x);
	while(x[i-1] != 0){
		scanf("%d",&x[i]);
		i++;
	}
	for(j = 1 ;j < i ;j++){
	printf("Case %d: %d\n",j,x[j-1]);
	}
	return 0;
}
