#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GYOU_MAX 256



int   isInt(double a) {

	if ((int)a == a) {
		return 1;
	}
	else {
		return 0;
	}
}



int main(void)
{
	
	int R, G, B, N;
	scanf("%d%d%d%d", &R, &G, &B, &N);

	int count = 0;
	double x;
	for (int i = 0;; i++) {
		if (R*i > N) {
			break;
		}

		for (int j = 0;; j++) {

			x = (double)(N - (R * i + G * j)) / B;

			//printf("%d %d %f\n", i, j, x);
			if (isInt(x)==1 && x >= 0) {
				count++;
				//printf("[%d %d %d]\n", i, j,(int) x);
			}
			if (R*i + G * j > N) {
				break;
			}
		}
	}

	printf("%d\n", count);

	
	return 0;
}
