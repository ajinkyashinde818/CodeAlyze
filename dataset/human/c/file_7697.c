#include <stdio.h>

int main(){

	int i,x[10000];

	for(i = 1; i <= 10000; i++){
		scanf("%d",&x[i]);

		if(x[i] == 0){
			break;
		}
	}

	for(i = 1; i <= 10000; i++){
		if(x[i] != 0){
			printf("Case %d: %d\n",i,x[i]);
		}else{
			break;
		}
	}

	return 0;
}
