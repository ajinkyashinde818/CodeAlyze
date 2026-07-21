#include <stdio.h>
int main(void){
	int a,i=0;
	int x[10000];
	while(1){
		scanf("%d",&a);
		x[i]=a;
		if(a==0)break;
		i++;
	}
	int j,b=0;
	for(j=0;j<i;j++){
		b++;
		printf("Case %d: %d\n",b,x[j]);
	}
	
	return 0;
}
