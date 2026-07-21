#include <stdio.h>

struct node_t {
	int id;
	int parent;
	int sibling;
	int degree;
	int depth;
	int childs[2];
	int height;
	const char *type;
};
typedef struct node_t Node;

int calc_depth(Node *data, int index) {
	int cidx, h, height = 0, i;

	for (i = 0; i < 2; i++) {
		cidx = data[index].childs[i];
		if (cidx >= 0) {
			data[cidx].depth += 1;
			data[cidx].sibling = data[index].childs[1-i];
			h = calc_depth(data, cidx);
			height = height > h ? height : h;
		}
	}
	if (data[index].type[0] == 'l') {
		data[index].height = 0;
	} else {
		data[index].height = height;
	}
	return data[index].height + 1;
}

void print_node(Node *p) {
	printf("node %d: parent = %d, ", p->id, p->parent);
	printf("sibling = %d, degree = %d, ", p->sibling, p->degree);
	printf("depth = %d, height = %d, %s\n", p->depth, p->height, p->type);
}

int main(void) {
	int n, i, j, id;
	Node *p;

	scanf("%d ", &n);

	Node data[n];

	for (i = 0; i < n; i++) {
		data[i].parent = -1;
		data[i].sibling = -1;
		data[i].degree = 0;
		data[i].depth = 0;
		data[i].height = 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d ", &id);
		p = &data[id];
		p->id = id;
		scanf("%d %d ", &p->childs[0], &p->childs[1]);
		for (j = 0; j < 2; j++) {
			if (p->childs[j] >= 0) {
				data[p->childs[j]].parent = id;
				(p->degree)++;
			}
		}
		p->type = p->degree ? "internal node" : "leaf";
	}

	for (i = 0; i < n; i++) {
		calc_depth(data, i);
	}

	for (i = 0; i < n; i++) {
		if (data[i].parent == -1) {
			data[i].type = "root";
		}
		print_node(data+i);
	}
	return 0;
}
