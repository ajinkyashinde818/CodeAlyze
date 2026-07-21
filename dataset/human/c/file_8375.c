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

int fnc() {

	int n = geti();
	char s[16];
	getstr(s);
	int k = geti();
	
	for (int i = 0; i < n; i++) {
		if (s[i] != s[k - 1]) {
			s[i] = '*';
		}
	}
	s[n] = '\n';
	s[n + 1] = '\0';
	out(s);

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
