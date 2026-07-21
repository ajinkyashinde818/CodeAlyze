/*
 * main.c
 *
 *  Created on: 2019/12/29
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a > b ? b : a)
typedef long long int ll;

int main()
{
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	if (N == M) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
    return 0;
}
