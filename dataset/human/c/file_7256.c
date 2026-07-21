#include <stdio.h>
#define PI 3.14159265358979323846264338

int main(){

	int a,b;
	int i,j;

	while(1) {
		scanf("%d %d", &a, &b);
		if(a==0 && b==0)
			break;
		for (i=0;i<a;i++){
			for(j=0;j<b;j++) {
				if(i%2 == j%2)
					printf("#");
				else
					printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;

}
