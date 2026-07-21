/*
 * main.c
 *
 *  Created on: 2019/07/21
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int A[21] = {0};
int B[21] = {0};
int C[21] = {0};


int main()
{
	int N = 0, i = 0, ans = 0, prev = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	for (i = 0; i < N-1; i++) {
		scanf("%d", &C[i]);
	}
	for (i = 0; i < N; i++) {
		//printf("A %d\n", A[i]);
		ans  += B[A[i]-1];
		//printf("B %d\n", B[A[i]-1]);
		if (i != 0) {
			if ((prev + 1) == A[i]) {
				//printf("prev =%d C %d\n", prev, C[prev-1]);
				ans += C[prev-1];
			}
		}
		prev = A[i];
	}
	printf("%d\n",ans);
    return 0;
}
