#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define  DPRINT printf
#else
#define DPRINT(...)
#endif

#define SWAP(a, b, v) v = a, a = b, b = v
#define PRED(a, b) ((a)->id < (b)->id)

typedef int ID;

typedef struct node {
	ID id;
	int parent;
	int depth;
	int cnum;
	int *cids;
} TYPE;

void
insert(TYPE **a, int n, TYPE *x)
{
	int i;

	for (i = n; i > 0; i--) {
		if (PRED(a[i - 1], x))
			break;
		a[i] = a[i - 1];
	}
	a[i] = x;
}

int /* index */
find(TYPE **a, int n, ID id)
{
	int lb = 0, rb = n - 1;
	int p;

	while (p = (lb + rb) / 2, lb < rb) {
		if (a[p]->id == id)
			return p;
		if (a[p]->id < id)
			lb = p + 1;
		else
			rb = p - 1;
	}

	return a[p]->id == id ? p : -1;
}

void
define_tree(TYPE **a, int n, int r, int p)
{
	int i;
	if (a[p]->parent != -1)
		return;
	a[p]->parent = r;

	for (i = 0; i < a[p]->cnum; i++) {
		int ind = find(a, n, a[p]->cids[i]);
		DPRINT("id:%d ind %d\n", a[p]->cids[i], ind);
		if (ind >= 0)
			define_tree(a, n, p, ind);
	}
}

int
depth(TYPE **a, int p)
{
	if (a[p]->depth != -1)
		return a[p]->depth;

	a[p]->depth = a[p]->parent == -1 ? 0 : depth(a, a[p]->parent) + 1;

	return a[p]->depth;
}

int
main(void)
{
	int i, j, n;
	TYPE **a;

	scanf("%d", &n);

	a = (TYPE **)malloc(sizeof(TYPE *) * n);
	if (a == NULL)
		return 1;

	for (i = 0; i < n; i++) {
		TYPE *arg = (TYPE *)malloc(sizeof(TYPE));

		if (arg == NULL)
			return 1;
		scanf("%d%d", &arg->id, &arg->cnum);
		arg->parent = -1;
		arg->depth = -1;

		if (arg->cnum > 0) {
			arg->cids = (int *)malloc(sizeof(int) * arg->cnum);
			if (arg->cids == NULL)
				return 1;
			for (j = 0; j < arg->cnum; j++)
				scanf("%d", arg->cids + j);
		} else {
			arg->cids = NULL;
		}
		insert(a, i, arg);
	}

	for (i = 0; i < n; i++)
		define_tree(a, n, -1, i);

	for (i = 0; i < n; i++) {
		printf("node %d: ", a[i]->id);
		printf("parent = %d, depth = %d, %s, [",
		       a[i]->parent, depth(a, i),
		       a[i]->parent == -1 ? "root" :
		       a[i]->cnum > 0 ? "internal node" : "leaf");
		for (j = 0; j < a[i]->cnum; j++)
			printf("%s%d", j ? ", " : "", a[i]->cids[j]);
		puts("]");
	}

	return 0;
}
