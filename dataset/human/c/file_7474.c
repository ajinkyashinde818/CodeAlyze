#include <stdio.h>

int main(){

	int x[10000], i, temp;

	for(i=0;i<10000;i++){
		scanf("%d", &x[i]);
	}

	for(i=0;i<10000;i++){
		temp = x[i];
		if(temp == 0){
			break;
		}else{
			printf("Case %d: %d\n", i+1, temp);
		}
	}

	return 0;
}
