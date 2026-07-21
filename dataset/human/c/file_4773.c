#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define max 26
typedef struct {
	int node, left, right, depth, parent, height, sub, deg;
}tre;

tre tree[30];

int getheight(int i) {
	int h1 = 0, h2 = 0;
	if (tree[i].left != NIL)
		h1 = getheight(tree[i].left) + 1;
	if (tree[i].right != NIL)
		h2 = getheight(tree[i].right) + 1;
	return tree[i].height = (h1 > h2 ? h1 : h2);
}

int getsib(int i) {
	if (tree[i].parent == NIL) return NIL;
	if (tree[tree[i].parent].left != i && tree[tree[i].parent].left != NIL)
		return tree[tree[i].parent].left;
	if (tree[tree[i].parent].right != i && tree[tree[i].parent].right != NIL)
		return tree[tree[i].parent].right;
	return NIL;
}

void getdepth(int i, int j) {
	if (i == NIL) return;
	tree[i].depth = j;
	getdepth(tree[i].left, j + 1);
	getdepth(tree[i].right, j + 1);
}


int main() {
	int i, size, base;
	scanf("%d", &size);

	//set all to NIL
	for (i = 0; i != size; i++) {
		tree[i].node = tree[i].left = tree[i].right =
			tree[i].depth = tree[i].parent = tree[i].height =
			tree[i].sub = tree[i].deg = NIL;
	}

	//reading input
	int node, left, right;
	for (i = 0; i != size; i++) {
		scanf("%d %d %d", &node, &left, &right);
		tree[node].left = left;
		tree[node].right = right;
		if (left != -1) tree[left].parent = node;
		if (right != -1) tree[right].parent = node;
	}

	//processing
	for (int i = 0; i != size; i++)
		if (tree[i].parent == NIL) base = i;
	getdepth(base, 0);
	getheight(base);

	//printing
	for (i = 0; i != size; i++) {
		printf("node %d: ", i);
		printf("parent = %d, ", tree[i].parent);
		printf("sibling = %d, ", getsib(i));
		int deg = 0;
		if (tree[i].left != NIL) deg++;
		if (tree[i].right != NIL) deg++;
		printf("degree = %d, ", deg);
		printf("depth = %d, ", tree[i].depth);
		printf("height = %d, ", tree[i].height);

		if (tree[i].parent == NIL) {
			printf("root\n");
		}
		else if (tree[i].left == NIL && tree[i].right == NIL) {
			printf("leaf\n");
		}
		else {
			printf("internal node\n");
		}
	}

	return 0;
}
