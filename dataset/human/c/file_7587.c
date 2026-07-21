#include <stdio.h>
int main(void){
	int i,x,y;
	x=1;
	int z[10000];
	for(i=0;x!=0;i++){
		scanf("%d",&x);
		z[i]=x;
	}
	for(y=0;y<i-1;y++){
		printf("Case %d: %d\n",y+1,z[y]);
	}
	return 0;
}
