//#include"pch.h"
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<math.h>
#include<string.h>
#include<algorithm>

int main() {

	int A, B, K;
	int cnt = 0;

	scanf("%d %d %d", &A, &B, &K);

	for (int i = A; i > 0; i--) {
		if (A%i == 0 && B%i == 0)cnt++;
		if (cnt == K) {
			printf("%d", i);
			break;
		}
	}




	return(0);
}
