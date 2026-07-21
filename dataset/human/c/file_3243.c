/*
 * main.c
 *
 *  Created on: 2020/03/28
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a > b ? b : a)
typedef long long int ll;
typedef unsigned long long int ull;

int sort_inc(const void *a, const void *b) { return (*(int*)a - *(int*)b);}
int sort_dec(const void* a, const void* b) { return (*(int*)b - *(int*)a);}
int sort_dec_ll(const void *a, const void *b) {
    ll da = *(ll*)a, db = *(ll*)b;    int val = 0;
    if(da > db) { val = -1; }
    else if (da == db) { val = 0; }
    else { val = 1; }
    return val;
}
int sort_inc_ll(const void *a, const void *b) {
    ll da = *(ll*)a, db = *(ll*)b;    int val = 0;
    if(da > db) { val = 1; }
    else if (da == db) { val = 0; }
    else { val = -1; }
    return val;
}
int sort_dic(const void *a, const void *b) {
    char *pa = (char *)a;    char *pb = (char *)b;    int i = 0, val = 0, N = 10;
    for (i = 0; i < N; i++) {
    	char da = pa[i], db = pb[i];
    	if (da == db) continue;
  		if (da > db) val = 1; else val = -1;
        break;
    }
    return val;
}


ll A[200002] = {0};
int main()
{
	ll K = 0, N = 0, i = 0, ans = 2000000, temp = 0;
	scanf("%lld %lld", &K, &N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	temp = K - A[N-1] + A[0];
	for (i = 0; i < N; i++) {
		ll index = 0, len1 = 0, add = 0;
		if (i == 0) {
			index = N - 1;
			add = 0;
			len1 = A[index] - A[i];
		} else {
			index = i - 1;
			add = temp;
			len1 = K - (A[i] - A[index]);
		}
		//printf("1 e=%lld s=%lld len1=%lld add=%lld\n", index, i, len1, add);
		ans = MIN(ans, len1);
	}
	for (i = 0; i < N; i++) {
		ll index = 0, len1 = 0, add = 0;
		if (i == (N - 1)) {
			add = 0;
			len1 = A[i] - A[0];
		} else {
			index = i + 1;
			add = temp;
			len1 = K - (A[index] - A[i]);
		}
		//printf("2 e=%lld s=%lld len1=%lld add=%lld\n", index, i, len1, add);
		ans = MIN(ans, len1);
	}
	printf("%lld\n", ans);
    return 0;
}
