/*
 * main.c
 *
 *  Created on: 2019/03/03
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ans[100] = {0};

int main()
{
	int a = 0, b = 0, k = 0;
	int i = 1;
	int ar = 0, br = 0;
	int j = 0;
	scanf("%d %d %d", &a, &b, &k);

	for(i = 1; i <= 100; i++ ) {
		ar = a%i;
		br = b%i;
		if ((ar == 0) && (br == 0)) {
			ans[j] = i;
			// printf("%d\n",i);
			j++;
		}
	}
	printf("%d\n", ans[j-k]);
	return 0;
}
