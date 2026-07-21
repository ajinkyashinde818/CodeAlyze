#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265358979323846



int main(void) {
	char S[4];
	scanf("%s", &S);
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < 3; i++) {
		if (S[i] == 'a') {
			count1++;
		}
		else if (S[i] == 'b') {
			count2++;
		}
		else if (S[i] == 'c') {
			count3++;
		}
	}
	if (count1 == 1 && count2 == 1 && count3 == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}



	return 0;
}
