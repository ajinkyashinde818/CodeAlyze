#include <stdio.h>
#include <stdlib.h>

struct node {
	int car;
	int cdr;
	int height;
	int depth;
	int degree;
	int parent;
	int sibling;
};

int
depth(struct node *a, int p)
{
	if (a[p].depth != -1)
		return a[p].depth;

	a[p].depth = a[p].parent == -1 ? 0 : depth(a, a[p].parent) + 1;

	return a[p].depth;
}

int
height(struct node *a, int p, int d)
{
	int c0 = a[p].car < 0 ? 0 : height(a, a[p].car, d + 1);
	int c1 = a[p].cdr < 0 ? 0 : height(a, a[p].cdr, d + 1);

	a[p].depth = d;
	a[p].height = c0 < c1 ? c1 : c0;

	return a[p].height + 1;
}

int
main(void)
{
	int i, j, n;
	struct node *a;

	scanf("%d", &n);

	a = (struct node *)malloc(sizeof(struct node) * n);
	if (a == NULL)
		return 1;

	for (i = 0; i < n; i++) {
		a[i].parent = -1;
		a[i].sibling = -1;
		a[i].height = 0;
		a[i].depth = -1;
	}

	for (i = 0; i < n; i++) {
		int id, car, cdr;
		scanf("%d%d%d", &id, &car, &cdr);
		a[id].car = car;
		a[id].cdr = cdr;
		car >= 0 && (a[car].parent = id);
		cdr >= 0 && (a[cdr].parent = id);
		if (car >= 0 && cdr >= 0)
			a[cdr].sibling = car, a[car].sibling = cdr;
		a[id].degree = (car >= 0) + (cdr >= 0);
	}

	for (i = 0; i < n; i++)
		if (a[i].parent == -1) {
			height(a, i, 0);
			break;
		}

	for (i = 0; i < n; i++) {
		printf("node %d", i);
		printf(": parent = %d", a[i].parent);
		printf(", sibling = %d", a[i].sibling);
		printf(", degree = %d", a[i].degree);
		printf(", depth = %d", a[i].depth);
		printf(", height = %d", a[i].height);
		printf(", %s\n",
		       a[i].parent == -1 ? "root" :
		       a[i].degree > 0 ? "internal node" : "leaf");
	}

	return 0;
}
