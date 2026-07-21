#define ll				long long
#define MOD				1000000007

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct data {
	int a;
	int b;
} data;

FILE *in, *ans;
int tno;

int out(const char *s) {
#ifdef TEST
	char buf[8192];
	fgets(buf, sizeof(buf), ans);
	if (strcmp(buf, s)) {
		printf("err\n");
	}
#else
	printf(s);
#endif
	return 0;
}

int outi(int i) {
	char s[128];
	sprintf(s, "%d\n", i);
	out(s);
	return 0;
}

int outll(ll l) {
	char s[128];
	sprintf(s, "%lld\n", l);
	out(s);
	return 0;
}

int geti() {
	int i;
	fscanf(in, "%d", &i);
	return i;
}

ll getll() {
	ll l;
	fscanf(in, "%lld", &l);
	return l;
}

int getstr(char *s) {
	fscanf(in, "%s", s);
	return 0;
}

int getgcd(int v1, int v2) {

	int w;
	if (v1 < v2) {
		w = v1;
		v1 = v2;
		v2 = w;
	}
	while (v2 > 0) {
		w = v1 % v2;
		v1 = v2;
		v2 = w;
	}

	return v1;
}

int i;
int n;

int fnc() {

	n = geti();
	int icnt = 0;
	int zcnt = 0;
	ll sum = 0;
	int min = INT_MAX;
	for (i = 0; i < n; i++) {
		int v = geti();
		if (v < 0) {
			icnt++;
		}
		else if (v == 0) {
			zcnt++;
		}
		v = abs(v);
		sum += v;
		if (min > v) {
			min = v;
		}
	}
	if (icnt % 2 == 1) {
		if (zcnt == 0) {
			sum -= min * 2;
		}
	}

	outll(sum);

	return 0;
}

int main() {

#ifdef TEST
	for (tno = TEST_SNO; tno <= TEST_ENO; tno++) {
		char str[128];
		sprintf(str, "test%d.txt", tno);
		in = fopen(str, "r");
		sprintf(str, "ans%d.txt", tno);
		ans = fopen(str, "r");
		fnc();
		fclose(in);
		fclose(ans);
	}
	printf("end\n");
#else
	in = stdin;
	fnc();
#endif

	return 0;
}
