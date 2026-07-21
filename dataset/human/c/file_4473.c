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

void yesno(int ans) {
	if (ans == 1) {	printf("Yes\n");
	} else {		printf("No\n");	}
	return;
}

void okng(int ans) {
	if (ans == 1) { printf("OK\n");
	} else { 		printf("NG\n");	}
	return;
}

int D[101][2] = {0};
int main()
{
	int N = 0;
	scanf("%d", &N);
	int i = 0;
	memset(&D,0,sizeof(D));

	for (i = 0; i < N; i++) {
		scanf("%d %d", &D[i][0], &D[i][1]);
	}

	int same = 0, count = 0, ans = 0;
	for (i = 0; i < N; i++) {
		if (D[i][0] == D[i][1]) {
			same = 1;
		} else {
			same = 0;
			count = 0;
		}
		if (same == 1) {
			count++;
		}
		if (count == 3) {
			ans = 1;
		}
	}

	yesno(ans);
	return 0;
}
