// AOJ 2412: Village
// 2017.12.8 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

#define HASHSIZ 900007
typedef struct { long long t; } HASH;
HASH hash[HASHSIZ+2], *hashend = hash+HASHSIZ;

int insert(int x, int y)
{
	long long t = ((long long)x << 32) | y;
	HASH *p = hash + (int)(t % HASHSIZ);

	while (p->t) {
		if (p->t == t) return 0;
		if (++p == hashend) p = hash;
	}
	p->t = t;
	return 1;
}

int lookup(int x, int y)
{
	long long t = ((long long)x << 32) | y;
	HASH *p = hash + (int)(t % HASHSIZ);

if (x <= 0 || y <= 0) printf("x %d, y %d, t %lld\n", x, y, t);
	while (p->t) {
		if (p->t == t) return 1;
		if (++p == hashend) p = hash;
	}
	return 0;
}

#define BASE 1000010
int ans;
int mv[8][2] = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
char buf[30], *p;

int getdbl()
{
	int minus = 0;
	int n = 0;

	if (*p == '-') minus = 1, p++;
	while (*p >= '0') n = (n<<3)+(n<<1) + (*p++ & 0xf);
	if (*p == '.') p++;
	while (*p >= '0') n = (n<<3)+(n<<1) + (*p++ & 0xf);
	p++;
	if (minus) n = -n;
	return n;
}

int main()
{
	int n, r, x0, y0, x, y, i;

	fgets(p=buf, 30, stdin);
	n = atoi(p); while (*p >= '0') p++; p++;
	r = getdbl();
	while (n--) {
		fgets(p=buf, 30, stdin);
#if 0
		x0 = getdbl(), y0 = getdbl();
		if (x0 < 0) x = (x0+1)/r-1; else x = x0/r;
		if (y0 < 0) y = (y0+1)/r-1; else y = y0/r;
#else
		x = BASE+getdbl()/r, y = BASE+getdbl()/r;
#endif
		if (insert(x, y)) {
			for (i = 0; ; i++) {
				if (i == 8) { ans++; break; }
				if (lookup(x+mv[i][0], y+mv[i][1])) break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
