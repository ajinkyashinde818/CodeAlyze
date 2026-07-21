#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int id;
	int parent;
	int depth;
	const char *kind;
	int degree;
	int *childs;
};
typedef struct node_t Node;

void calc_depth(Node *data, int i) {
	int j, idx;

	for (j = 0; j < data[i].degree; j++) {
		idx = data[i].childs[j];
		data[idx].depth += 1;
		calc_depth(data, idx);
	}
}

void print_node(Node *p) {
	int i;
	const char *fmt = "%d";

	printf(
		"node %d: parent = %d, depth = %d, %s, [",
		p->id, p->parent, p->depth, p->kind);

	for (i = 0; i < p->degree; i++) {
		printf(fmt, p->childs[i]);
		fmt = ", %d";
	}
	puts("]");
}

int main(void) {
	Node *data, *p;
	int n, id, degree, i, j;

	scanf("%d", &n);
	data = malloc(sizeof(Node)*n);
	for (i = 0; i < n; i++) {
		data[i].parent = -1;
		data[i].depth = 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d %d", &id, &degree);
		p = &data[id];
		p->id = id;
		p->degree = degree;
		p->kind = degree ? "internal node" : "leaf";
		p->childs = malloc(sizeof(int)*degree);
		for (j = 0; j < degree; j++) {
			scanf("%d", p->childs+j);
			data[p->childs[j]].parent = id;
		}
	}

	for (i = 0; i < n; i++) {
		calc_depth(data, i);
	}

	for (i = 0; i < n; i++) {
		if (data[i].depth == 0) {
			data[i].kind = "root";
		}
		print_node(data+i);
	}
	return 0;
}
