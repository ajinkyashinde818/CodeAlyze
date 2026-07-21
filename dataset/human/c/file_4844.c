#include <stdio.h>

#define MAX 30
#define NIL -1

struct Node {
	int parent;
	int left;
	int right;
	int sibling;
	int degree;
	int depth;
	int height;
};

void setDepth(struct Node *tree, int cur, int depth) {
	if (cur == NIL) return;
	tree[cur].depth = depth;
	setDepth(tree, tree[cur].left, depth + 1);
	setDepth(tree, tree[cur].right, depth + 1);
}

int setHeight(struct Node *tree, int cur) {
	int heightL, heightR;
	if (cur == NIL) return 0;
	heightL = setHeight(tree, tree[cur].left);
	heightR = setHeight(tree, tree[cur].right);
	tree[cur].height = heightL > heightR ? heightL : heightR;
	return tree[cur].height + 1;
}

int getStatus(struct Node *p) {
	if (p->parent == NIL) return 0;
	if (p->left == NIL && p->right == NIL) return 1;
	return 2;
}

void print(struct Node *tree, int cur) {
	char strtype[3][14] = { "root","leaf","internal node" };

	printf("node %d: ", cur);
	printf("parent = %d, ", tree[cur].parent);
	printf("sibling = %d, ", tree[cur].sibling);
	printf("degree = %d, ", tree[cur].degree);
	printf("depth = %d, ", tree[cur].depth);
	printf("height = %d, ", tree[cur].height);
	printf("%s\n", strtype[getStatus(&tree[cur])]);

}
int main() {
	int i, n, id, left, right, root;
	struct Node tree[MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		tree[i].parent = tree[i].left = tree[i].right = tree[i].sibling = NIL;
		tree[i].degree = 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &id, &left, &right);
		if (left != NIL) {
			tree[left].parent = id;
			tree[left].sibling = right;
			tree[id].left = left;
			tree[id].degree++;
		}
		if (right != NIL) {
			tree[right].parent = id;
			tree[right].sibling = left;
			tree[id].right = right;
			tree[id].degree++;
		}
	}

	root = NIL;
	for (i = 0; i < n; i++) {
		if (tree[i].parent == NIL) {
			root = i;
			break;
		}
	}

	setDepth(tree, root, 0);
	setHeight(tree, root);

	for (i = 0; i < n; i++) {
		print(tree, i);
	}

	return 0;
}
