#include <stdio.h>

int main(void){
	int times;
	int rate;

	scanf("%d %d", &times, &rate);
	if(times<10){
		printf("%d", rate + 100 * (10 - times));
	}else{
		printf("%d", rate);
	}
	printf("\n");

	return 0;
}
