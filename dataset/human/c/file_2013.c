#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define pai 3.1415926535


int main(void) {
	
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	int sum = 0;
	if (B >= C) {
		sum += B + C;
		printf("%d", sum);
		return 0;
	}
	else {
		sum += 2*B;
		C-= B;
	}

	if (A >= C) {
		sum += C;
		
	}
	else {
		sum += A;
		sum++;
	}
	
	printf("%d", sum);




	return 0;


}
