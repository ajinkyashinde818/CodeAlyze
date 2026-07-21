#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

struct link {
	struct link *next;
	int val;
};

struct link *newval(struct link *prev, int val)
{
	struct link *p = prev, *pp = NULL;
	for (; p; pp = p, p = p->next) {
		if (p->val == val)
			return prev;
		if (p->val > val)
			break;
	}
	struct link *l = malloc(sizeof(struct link *));
	if (pp) {
		pp->next = l;
		l->next = p;
		l->val = val;
		return prev;
	}
	l->next = prev;
	l->val = val;
	return l;
}

struct link *update(struct link *me, struct link *prev, int diff)
{
	for (struct link *p = prev; p; p = p->next) {
		me = newval(me, abs(p->val + diff));
		me = newval(me, abs(p->val - diff));
	}
	return me;
}

int main(int argc, char **argv)
{
	int H, W;
	scanf("%d %d", &H, &W);
	int A[80][80], B[80][80];
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++)
			scanf("%d", &A[h][w]);
	}
	int D[80][80];
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			scanf("%d", &B[h][w]);
			// get diff
			D[h][w] = abs(A[h][w] - B[h][w]);
		}
	}
#if 0
	struct link *p[80][80] = {0}; // NULL
	p[0][0] = newval(NULL, D[0][0]);
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (h > 0)
				p[h][w] = update(p[h][w], p[h - 1][w], D[h][w]);
			if (w > 0)
				p[h][w] = update(p[h][w], p[h][w - 1], D[h][w]);
		}
	}
	for (struct link *l = p[H-1][W-1]; l; l = l->next)
		fprintf(stderr, "%d\n", l->val);
	printf("%d\n", p[H-1][W-1]->val);
#endif
	static int p[80][80][80*80*2 + 128] = {0};
	int hw = D[0][0];
	p[0][0][hw] = 1;
	int m = hw;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			for (int k = 0; k <= m; k++) {
				int k1 = abs(k + D[h][w]);
				int k2 = abs(k - D[h][w]);
				if (h>0 && p[h-1][w][k]) {
					p[h][w][k1] = 1;
					p[h][w][k2] = 1;
					if (k1 > m)
						m = k1;
					if (k2 > m)
						m = k2;
				}
				if (w>0 && p[h][w-1][k]) {
					p[h][w][k1] = 1;
					p[h][w][k2] = 1;
					if (k1 > m)
						m = k1;
					if (k2 > m)
						m = k2;
				}
			}
		}
	}
	for (int k = 0; k <= m; k++) {
		if (p[H-1][W-1][k]) {
			printf("%d\n", k);
			return 0;
		}
	}
	return 0;
}
