#include<stdio.h>

int main(){
	int a,k=1,x[10000];

	while(1){
		scanf("%d",&x[k]);
		if( x[k] == 0 ) break;
		k += 1;
	}

	for(a = 1; a < k ;a++){
		printf("Case %d: %d\n",a,x[a]);
	}

	return 0;
}
