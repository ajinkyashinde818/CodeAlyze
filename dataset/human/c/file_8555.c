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
	int x, y;
} data;

int n;
int vals[100000];

int sortfnci(const void *v1, const void *v2) {
	int *i1 = (int *)v1;
	int *i2 = (int *)v2;

	if (*i1 > *i2) {
		return 1;
	}
	else if (*i1 < *i2) {
		return -1;
	}

	return 0;
}

int fnc2() {
	int i;
	char s[128];

	n = geti();
	for (i = 0; i < n; i++) {
		vals[i] = geti();
	}
	qsort(vals, n, sizeof(int), sortfnci);

	if (n == 2) {
		outi(vals[1] - vals[0]);
		sprintf(s, "%d %d\n", vals[1], vals[0]);
		out(s);
		return 0;
	}

	int sum = 0;
	int now;
	if (vals[0] > 0) {
		for (i = 0; i < n; i++) {
			sum += vals[i];
		}
		sum -= vals[0] * 2;
		outi(sum);

		now = vals[0];
		for (i = 1; i < n - 1; i++) {
			sprintf(s, "%d %d\n", now, vals[i]);
			out(s);
			now -= vals[i];
		}
		sprintf(s, "%d %d\n", vals[n-1], now);
		out(s);
	}
	else if (vals[n-1] < 0) {
		for (i = 0; i < n; i++) {
			sum += abs(vals[i]);
		}
		sum -= abs(vals[n-1]) * 2;
		outi(sum);

		now = vals[n - 1];
		for (i = 0; i < n - 1; i++) {
			sprintf(s, "%d %d\n", now, vals[i]);
			out(s);
			now -= vals[i];
		}
	}
	else {
		for (i = 0; i < n; i++) {
			sum += abs(vals[i]);
		}
		outi(sum);

		now = vals[0];
		for (i = 1; i < n - 1; i++) {
			if (vals[i] >= 0) {
				sprintf(s, "%d %d\n", now, vals[i]);
				out(s);
				now -= vals[i];
			}
		}
		sprintf(s, "%d %d\n", vals[n - 1], now);
		out(s);
		now = vals[n - 1] - now;
		for (i = 1; i < n - 1; i++) {
			if (vals[i] < 0) {
				sprintf(s, "%d %d\n", now, vals[i]);
				out(s);
				now -= vals[i];
			}
		}
	}

	return 0;
}

int fnc1() {
	int ret = fnc2();
//	outi(ret);
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
