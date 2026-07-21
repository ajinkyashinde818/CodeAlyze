#include <stdio.h>
#define MAX 100005
#define NIL -1

struct Node { int p, l, r; };

struct Node  T[MAX];
int n, D[MAX],H[MAX];

void Depth(int u,int d) {
	if (u == NIL) return;
	D[u] = d;
	Depth(T[u].l,d+1);
	Depth(T[u].r,d+1);
}

int Height(int u) {
	int h1 = 0, h2 = 0;
	if (T[u].l != NIL) h1 = Height(T[u].l) + 1;
	if (T[u].r != NIL) h2 = Height(T[u].r) + 1;

	return H[u] = (h1 > h2 ? h1 : h2);
}

int getsibling(int u){
	if (T[u].p == NIL) return NIL;
	if (T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
	if (T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;

	return NIL;
}

void print(int u) {
	int i, c;

	printf("node %d:", u);
	printf(" parent = %d,", T[u].p);
    printf(" sibling = %d,",getsibling(u));
	int deg = 0;
	if (T[u].l != NIL) deg++;
	if (T[u].r != NIL) deg++;
	printf(" degree = %d,",deg);
	printf(" depth = %d,", D[u]);
	printf(" height = %d, ",H[u]);

	if (T[u].p == NIL) printf("root\n");
	else if (T[u].l == NIL && T[u].r== NIL) printf("leaf\n");
	else printf("internal node\n");
}

int main() {

	int n, i, j, node, nodenum, c, left, right;
	int root = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) T[i].p = NIL;

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &nodenum, &left, &right);
		T[nodenum].l = left;
		T[nodenum].r = right;
		if (left != NIL) T[left].p = nodenum;
		if (right != NIL) T[right].p = nodenum;
	}
	
	for (i = 0; i < n; i++) if (T[i].p == NIL) root = i;

	Depth(root,0);
	Height(root);

	for (i = 0; i < n; i++) print(i);
	return 0;
}
