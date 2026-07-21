#include <stdio.h>

int main(int argc, char* argv[]){
	int x[10000];
	int i, j = 0;
	int a;
	
	do{
		scanf("%d", &a);
		x[i] = a;
		i++;
	}while(a != 0);

	for(j = 0; j < i - 1; j++){
		printf("Case %d: %d\n", j + 1, x[j]);
	}

	return 0;
}
