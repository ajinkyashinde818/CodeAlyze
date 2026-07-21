#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//#define MOD (int)(1e5 + 7)
#define MOD (100007)

static inline void done(const char *s)
{
	puts(s);
	exit(0);
}

#define yes() done("Yes");
#define no() done("No");
#define invalid() done("-1");

static int comp(const void *a, const void *b)
{
	int *pa = (int *)a;
	int *pb = (int *)b;
	return *pa < *pb;
}

static inline int *readNint(int n)
{
	int *a = calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return a;
}

static inline long *readNlong(int n)
{
	long *a = calloc(sizeof(long), n);
	for (int i = 0; i < n; i++)
		scanf("%ld", &a[i]);
	return a;
}

char S[200000 + 100000 + 200000];

int main(int argc, char **argv)
{
	int st = 200000;
	scanf("%s", &S[st]);
	int L = strlen(&S[st]);
	int lt = st + L;
	fprintf(stderr, "%d %s\n", L, &S[st]);
	int dir = 1;
	int Q;
	scanf("%d", &Q);
	char buf[256];
	fgets(buf, 256, stdin); // discard
	for (int q = 0; q < Q; q++) {
		char buf[256];
		fgets(buf, 256, stdin);
		fprintf(stderr, "%d %s\n", q, buf);
		char T = buf[0];
		char F = buf[2];
		char C = buf[4];
		if (T == '1') {
			dir = -dir;
			continue;
		}
		if (F == '1') {
			if (dir == 1) {
				--st;
				S[st] = C;
			} else {
				S[lt] = C;
				++lt;
			}
		} else {
			if (dir == -1) {
				--st;
				S[st] = C;
			} else {
				S[lt] = C;
				++lt;
			}
		}
	}
	if (dir == 1) {
		printf("%s\n", &S[st]);
	} else {
		for (int i = lt - 1; i >= st; i--) {
			printf("%c", S[i]);
		}
		printf("\n");
	}
	return 0;
}
