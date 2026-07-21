/*
 * main.c
 *
 *  Created on: 2019/04/27
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long int uint64_t;

long long int A[100001] = {0};

int main()
{
	int N = 0, i = 0;
	int minus_count = 0, zero_count=0;
	long long int min = 1000000000;
	uint64_t sum = 0;
	scanf("%d",&N);
	for(i = 0; i < N; i++) {
		scanf("%lld",&A[i]);
		if(A[i] < 0) {
			minus_count++;
		}
		if(A[i] == 0){
			zero_count++;
		}
		if(abs(A[i]) < min) {
			min = abs(A[i]);
		}
		sum += abs(A[i]);
	}
	//printf("sum=%llu minus=%d zero=%d min=%d\n", sum, minus_count, zero_count, min);


	if(((minus_count%2) != 0) && (zero_count == 0)) {
		sum -= (min*2);
	}
	printf("%llu", sum);
    return 0;
}
