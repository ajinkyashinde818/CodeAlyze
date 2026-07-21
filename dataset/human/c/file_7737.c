#include <stdio.h>

int main(void) {
	int a, b, c, i, j, n; 
	scanf("%d", &j);
	for(i= 1; i <= j ;i++){
		scanf("%d%d", &a, &b);
		c = a / b;
		if (a % b==0){
			n = b;
		}
		else{
			n = a - c * b;
		}
		printf("%d\n", n);
	}
	
	return 0;
}
