#include <stdio.h>
int main(void){
	int x,i,j,d[10000];
	i=0;
	j=0;
	scanf("%d",&x);
	while(x!=0){
		d[j]=x;
		j=j+1; i=i+1;
		scanf("%d",&x);
	}
	for (j=0; j<i; j++){
		printf("Case %d: %d\n",j+1,d[j]);
	}
	return 0;
}
