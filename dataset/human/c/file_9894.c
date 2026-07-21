#include <stdio.h>
#define MAX 100000
typedef struct { int pa, le, ri; } Node;
Node T[MAX];
int n,D[MAX];

void print(int u) {
	int i, c;
	printf("node %d: parent = %d, depth = %d, ", u, T[u].pa, D[u]);
	if (T[u].pa == EOF) printf("root, ");
	else if (T[u].le == EOF) printf("leaf, ");
	else printf("internal node, ");

	printf("[");
	for (i = 0, c = T[u].le; c != EOF; i++, c = T[c].ri) {
		if (i) printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}

void rec(int u, int p) {
	D[u] = p;
	if (T[u].ri != EOF) rec(T[u].ri, p);
	if (T[u].le != EOF) rec(T[u].le, p + 1);
}

int main() {
	int i,j,k,v,c,l,r;
	scanf("%d", &n);
	for (i=0; i<n; i++)  T[i].pa = T[i].le = T[i].ri = EOF;

	for (i = 0; i < n; i++) {
		scanf("%d %d", &v, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &c);
			if (j == 0) T[v].le = c;
			else T[l].ri = c;
			l = c;
			T[c].pa = v;
		}
	}
	for (i = 0; i < n; i++) {
		if (T[i].pa == EOF) r = i;
	}
	rec(r, 0);
	for (i = 0; i < n; i++) print(i);
}
