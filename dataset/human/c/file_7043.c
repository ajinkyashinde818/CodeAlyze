#include <stdio.h>

int main(void){

	int t;
	int x[256], y[256];
	for(t = 0; t < 256 ; t++){
		scanf("%d %d", &x[t], &y[t]);
		if(x[t] == 0){
			break;
		}
	}
	int i, j;
	t = 0;
	while(1){
		for(i = 0; i < x[t] ; i++){
			if((i % 2) == 0){
				for(j = 0; j < y[t] ; j++){
					if((j % 2) == 0){
						printf("#");
					}else{
						printf(".");
					}
				} 
			}else{
				for(j = 0; j < y[t] ; j++){
					if((j % 2) == 0){
						printf(".");
					}else{
						printf("#");
					}
				} 
			}
			printf("\n");
		}
		t++;
		printf("\n");
		if(x[t] == 0){
			break;
		}
	}
	return 0;
}
