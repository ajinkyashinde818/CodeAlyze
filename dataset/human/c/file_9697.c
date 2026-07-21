#include <stdio.h>

#define MAX 100000

typedef struct {
	int parent;
	int left;
	int right;
} node;

node nodes[MAX] = {0};

int n;



int getDepth(int num) {
	int d = 0;
	while (nodes[num].parent != -1) {
		num = nodes[num].parent;
		++d;
	}
	return d;
}

void printChilde(int num) {
	int c, flag = 0;
	c = nodes[num].left;

	while (c != -1) {
		if (flag) {
			printf(", ");
		}
		flag = 1;
		printf("%d", c);
		c = nodes[c].right;
	}
	printf("]\n");
	return;
}

void show_node(int num) {
	if (nodes[num].parent == -1) {
		printf("node %d: parent = %d, depth = %d, root, [", num, nodes[num].parent, getDepth(num));
	} else if (nodes[num].left == -1) {
		printf("node %d: parent = %d, depth = %d, leaf, [", num, nodes[num].parent, getDepth(num));
	} else {
		printf("node %d: parent = %d, depth = %d, internal node, [", num, nodes[num].parent, getDepth(num));
	}
	printChilde(num);
}

int main(void) {
	int i, j, tmp, right, left, num;
	int m;
	node init_node;
	init_node.parent = init_node.left = init_node.right = -1;

	for (i = 0; i < MAX; ++i) {
		nodes[i] = init_node;
	}
	
	scanf("%d", &n);	

	for (i = 0; i < n; ++i) {
		scanf(" %d", &num);
		scanf(" %d", &m);
		for (j = 0; j < m; ++j) {
			scanf(" %d", &tmp);
//			printf("j = %d, tmp = %d\n", j, tmp);
			nodes[tmp].parent = num;
			if (j == 0) {
				nodes[num].left = tmp;
				left = tmp;
			} else {
				nodes[left].right = tmp;
				left = tmp;
//				printf("tmp = %d, right = %d\n", tmp, nodes[tmp].right);
			}
		}
	}
//	printf("test\n");

	for (i = 0; i < n; ++i) {
		show_node(i);
	}
	return 0;
}
