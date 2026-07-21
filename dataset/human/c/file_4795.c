#include <stdio.h>

#define N 100001
#define NIL -1

#define INNER_NODE 1
#define LEAF -1
#define ROOT 0

typedef struct {
	int parent;
	int left;
	int right;
} Node;

Node node[N];

void initNode(int n) {
	int i;

	for (i = 0; i < n; i++) {
		node[i].parent = NIL;
		node[i].left = NIL;
		node[i].right = NIL;
	}
}

void createTree(int n) {
	int nodeId, i;

	for (i = 0; i < n; i++) {
		scanf("%d", &nodeId);
		scanf("%d %d", &node[nodeId].left, &node[nodeId].right);
		if (node[nodeId].left != NIL) {
			node[node[nodeId].left].parent = nodeId;
		}
		if (node[nodeId].right != NIL) {
			node[node[nodeId].right].parent = nodeId;
		}
	}
}

int getSibling(int id) {

	if (node[id].parent != NIL) {
		if (node[node[id].parent].left == id) {
			return node[node[id].parent].right;
		} else {
			return node[node[id].parent].left;
		}
	}

	return NIL;
}

int getDegree(int id) {

	int degree = 0;

	if (node[id].left != NIL) {
		degree++;
	}
	if (node[id].right != NIL) {
		degree++;
	}

	return degree;
}

int getDepth(int d, int depth) {

	if (node[d].parent == NIL) {
		return depth;
	}

	depth++;
	getDepth(node[d].parent, depth);
}

int judgeNode(Node node) {

	if (node.parent == NIL) {
		return ROOT;
	} else if (node.left == NIL && node.right == NIL) {
		return LEAF;
	} else {
		return INNER_NODE;
	}

	return 0;
}

int getHeight(int id) {
	int leftHeight = 0;
	int rightHeight = 0;

	if (judgeNode(node[id]) == LEAF) {
		return 0;
	}

	if (node[id].left != NIL) {
		leftHeight = getHeight(node[id].left) + 1;
	}
	if (node[id].right != NIL) {
		rightHeight = getHeight(node[id].right) + 1;
	}

	if (leftHeight > rightHeight) {
		return leftHeight;
	} else {
		return rightHeight;
	}
}

void displayNode(int id) {

	printf("node %d: parent = %d, ", id, node[id].parent);
	printf("sibling = %d, ", getSibling(id));
	printf("degree = %d, ", getDegree(id));
	printf("depth = %d, ", getDepth(id, 0));
	printf("height = %d, ", getHeight(id));

	switch (judgeNode(node[id])) {
	// nodeが内部ノードの場合
	case INNER_NODE:
		puts("internal node");
		break;
	// nodeがリーフの場合
	case LEAF:
		puts("leaf");
		break;
	// nodeがルートの場合
	case ROOT:
		puts("root");
		break;
	}
}

int main() {
	int i, n;

	scanf("%d", &n);

	initNode(n);
	createTree(n);

	for (i = 0; i < n; i++) {
		displayNode(i);
	}

	return 0;
}
