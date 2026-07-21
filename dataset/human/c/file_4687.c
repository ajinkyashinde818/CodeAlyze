#include <stdio.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

typedef struct { int parent; int sibling; int depth, height; int k; int c[2]; } TREE;
TREE tree[30];

void calc_depth(int node, int d)
{
	int i;
	tree[node].depth = d;
	for (i = 0; i < tree[node].k; i++) calc_depth(tree[node].c[i], d+1);
}

int calc_height(int node)
{
	int i, h, t;

	h = 0;
	for (i = 0; i < tree[node].k; i++) {
		if ((t = calc_height(tree[node].c[i])+1) > h) h = t;
	}
	tree[node].height = h;
	return h;
}

int main()
{
	int n, i, id;
	int root, left, right;

	n = in();
	for (i = 0; i < n; i++) {
		id = in(), left = in(), right = in();
		if (left < 0 && right < 0) tree[id].k = 0;
		else if (left >= 0 && right >= 0) {
			tree[id].k = 2;
			tree[id].c[0] = left, tree[id].c[1] = right;
			tree[left].parent = id+1;
			tree[left].sibling = right+1;
			tree[right].parent = id+1;
			tree[right].sibling = left+1;
		} else {
			if (left < 0) left = right;
			tree[id].k = 1;
			tree[id].c[0] = left;
			tree[left].parent = id+1;

		}
	}
	for (root = 0; root < n; root++) {
		if (tree[root].parent == 0) break;
	}
	calc_depth(root, 0);
	calc_height(root);

	for (i = 0; i < n; i++) {
		printf("node %d:", i);
		printf(" parent = %d,", tree[i].parent-1);
		printf(" sibling = %d,", tree[i].sibling-1);
		printf(" degree = %d,", tree[i].k);
		printf(" depth = %d,", tree[i].depth);
		printf(" height = %d,", tree[i].height);
		if (i == root)          printf(" root");
		else if (tree[i].k == 0) printf(" leaf");
		else                    printf(" internal node");
		putchar('\n');
	}
	return 0;
}
