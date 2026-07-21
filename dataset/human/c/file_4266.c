#define ll				long long
#define MOD				1000000007

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int outd(double d) {
	char s[128];
	sprintf(s, "%.10lf\n", d);
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

int getmin(int val1, int val2) {
	if (val1 < val2) {
		return val1;
	}
	else {
		return val2;
	}
}

int getmax(int val1, int val2) {
	if (val1 > val2) {
		return val1;
	}
	else {
		return val2;
	}
}

typedef struct data {
	char c;
	int cnt;
} data;

int a[100005];
int n, m;

int fnc2() {
	int i;
	int n = geti();
	int m = geti();
	for (i = 0; i < m; i++) {
		int no = geti();
		a[no] = -1;
	}

	a[0] = 1;
	for (i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (a[i + 1] >= 0) {
				a[i + 1] += a[i];
				a[i + 1] %= MOD;
			}
			if (a[i + 2] >= 0) {
				a[i + 2] += a[i];
			}
		}
	}

	return a[n];
}

int fnc1() {
	int ret = fnc2();
	outi(ret);
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
		fnc1();
		fclose(in);
		fclose(ans);
	}
	printf("end\n");
#else
	in = stdin;
	fnc1();
#endif

	return 0;
}
