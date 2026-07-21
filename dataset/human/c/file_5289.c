#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treetype {
	int parent;
	int sibling;
	int degree;
	int depth;
	int height;
	char type[20];
	int left;
	int right;
};

int main(void) {
	int n;
	struct treetype tree[26];
	int i, j, k;
	int depthmax = 0;
	int number = 0;
	int roottr = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		tree[i].parent = -2;
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &number);
		scanf("%d %d", &tree[number].left, &tree[number].right);

		tree[tree[number].left].parent = number; //親決定
		tree[tree[number].left].sibling = tree[number].right;
		tree[tree[number].right].parent = number;
		tree[tree[number].right].sibling = tree[number].left;
		tree[number].degree = 0;
		tree[number].height = 0;
		if (tree[number].left >= 0) {
			tree[number].degree += 1;
		}
		if (tree[number].right >= 0) {
			tree[number].degree += 1;
		}
	}

	for (i = 0; i < n; i++) {
		if (tree[i].parent == -2 && roottr == 0) {
			strcpy(tree[i].type, "root");
			tree[i].sibling = -1;
			tree[i].parent = -1;
			roottr = 1;
		}
		else if (tree[i].left >= 0 || tree[i].right >= 0) {
			strcpy(tree[i].type, "internal node");
		}
		else {
			strcpy(tree[i].type, "leaf");
		}
	}

	for (i = 0; i < n; i++) {
		k = i;
		for (j = 0; 1; j++) {
			if (tree[k].parent < 0) {
				tree[i].depth = j;
				if (depthmax < tree[i].depth) {
					depthmax = tree[i].depth;
				}
				break;
			}
			k = tree[k].parent;
		}
	}

	for (i = 0; i < n; i++) {
		if (strcmp(tree[i].type, "leaf") == 0) {
			k = i;
			for (j = 1; 1; j++) {
				if (tree[k].parent < 0) {
					break;
				}
				else {
					k = tree[k].parent;
				}
				if (j > tree[k].height) {
					tree[k].height = j;
				}
			}
		}
	}

	for (number = 0; number < n; number++) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", number, tree[number].parent, tree[number].sibling, tree[number].degree, tree[number].depth, tree[number].height, tree[number].type);
	}

	return 0;
}
