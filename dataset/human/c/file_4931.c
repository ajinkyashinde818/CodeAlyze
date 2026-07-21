#include <stdio.h>

#define MAX 25

typedef struct {
	int parent;
	int left;
	int right;
} node;

node nodes[MAX] = {0};
int H[MAX];


int getDepth(int num) {
	int d = 0;
	while (nodes[num].parent != -1) {
		num = nodes[num].parent;
		++d;
	}
	return d;
}

int getDegree(int num) {
	if (nodes[num].left == -1 && nodes[num].right == -1) return 0;
	if (nodes[num].left != -1 && nodes[num].right != -1) return 2;
	return 1;
}

int getSibling(int num) {
	int parent ;
	parent = nodes[num].parent;
	if (parent == -1) return -1;
	if (nodes[parent].right == num) return nodes[parent].left;
	return nodes[parent].right;
}

int setHeight(int num) {
	int h1, h2;
	h1 = h2 = 0;
	if (nodes[num].right != -1) {
		h1 = setHeight(nodes[num].right) + 1;
	}

	if (nodes[num].left != -1) {
		h2 = setHeight(nodes[num].left) + 1;
	}

	return (h1 > h2) ? h1 : h2;
}

void show_node(int num) {
	int parent = nodes[num].parent;
	if (parent == -1) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", num, nodes[num].parent, getSibling(num), getDegree(num), getDepth(num), setHeight(num));
	} else if (nodes[num].right == -1 && nodes[num].left == -1) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", num, nodes[num].parent, getSibling(num), getDegree(num), getDepth(num), setHeight(num));
	} else {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", num, nodes[num].parent, getSibling(num), getDegree(num), getDepth(num), setHeight(num));
	}
	return;
}

int main(void) {
	int n;
	int i, tmp;
	node init_node;
	init_node.parent = init_node.right = init_node.left = -1;
	for (i = 0; i < MAX; ++i) {
		nodes[i] = init_node;
	}
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		scanf("%d", &nodes[tmp].left);
		scanf("%d", &nodes[tmp].right);
		if (nodes[tmp].left != -1) {
			nodes[nodes[tmp].left].parent = tmp;
		}
		if (nodes[tmp].right != -1) {
			nodes[nodes[tmp].right].parent = tmp;
		}
	}

	for (i = 0; i < n; ++i) {
//		setHeight(i);
		show_node(i);
	}
	return 0;
}
