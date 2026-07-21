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

int h[100001] = {0};

int main()
{
	int N = 0, K = 0, i = 0, ans = 0;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i ++) {
		int hight = 0;
		scanf("%d", &hight);
		if (K <= hight) {
			ans++;
		}
	}
	printf("%d\n", ans);
    return 0;
}
