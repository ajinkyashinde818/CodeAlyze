#include <stdio.h>          // printf(), scanf()
#define MAX_N 25

typedef struct node_tbl
{
	int parent;
	int left;
	int right;
} node;

const int nil = -1;
node t[MAX_N];
int d[MAX_N];
int h[MAX_N];

void
set_depth(int u, int v)
{
	if (u == nil)
		return;

	d[u] = v;
	set_depth(t[u].left, v + 1);
	set_depth(t[u].right, v + 1);
}

int
set_height(int u)
{
	int h1 = 0, h2 = 0;
	if (t[u].left != nil)
		h1 = set_height(t[u].left) + 1;

	if (t[u].right != nil)
		h2 = set_height(t[u].right) + 1;

	return h[u] = (h1 > h2) ? h1 : h2;
}

int
get_sibling(int u)
{
	if (t[u].parent == nil)
		return nil;

	if (t[t[u].parent].left != u && t[t[u].parent].left != nil)
		return t[t[u].parent].left;

	if (t[t[u].parent].right != u && t[t[u].parent].right != nil)
		return t[t[u].parent].right;

	return nil;
}

void
print(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", t[u].parent);
	printf("sibling = %d, ", get_sibling(u));
	int deg = 0;
	if (t[u].left != nil)
		deg++;

	if (t[u].right != nil)
		deg++;

	printf("degree = %d, ", deg);
	printf("depth = %d, ", d[u]);
	printf("height = %d, ", h[u]);
	if (t[u].parent == nil)
		printf("root\n");

	else if (t[u].left == nil && t[u].right == nil)
		printf("leaf\n");

	else
		printf("internal node\n");
}

int
main(int argc, char** argv)
{
	int n;
	int root;
	int v;
	int l, r;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		t[i].parent = nil;

	for (i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &v, &l, &r);
		t[v].left = l;
		t[v].right = r;
		if (l != nil)
			t[l].parent = v;

		if (r != nil)
			t[r].parent = v;
	}

	for (i = 0; i < n; ++i)
	{
		if (t[i].parent == nil)
		{
			root = i;
			break;
		}
	}

	set_depth(root, 0);
	set_height(root);

	for (i = 0; i < n; ++i)
		print(i);

	return 0;
}
