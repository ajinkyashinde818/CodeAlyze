#include <stdio.h>
#include <stdlib.h>

#define max_number 100000
#define NIL -1

typedef struct {
	int parent, left, right;
} node;

node array[max_number];
int depth[max_number];

int GetDepth(int i) {
	if (array[i].parent == NIL) {
		return 0;
	}
	return GetDepth(array[i].parent) + 1;
}

int main() {
	int i, j, k, ID, temp, m, array_size;
	scanf("%d", &array_size);

	//set values to NIL for scanning later on
	for (i = 0; i != array_size; i++) {
		array[i].parent = array[i].left = array[i].right = NIL;
	}

	//assigning values from input
	for (i = 0; i != array_size; i++) {
		scanf("%d %d", &ID, &k);
		for (j = 0; j != k; j++) {
			scanf("%d", &m);
			if (j == 0) {
				array[ID].left = m;
				array[m].parent = ID;
				temp = m;
			}
			else {
				array[temp].right = m;
				array[m].parent = ID;
				temp = m;
			}
		}
	}

	//get depth
	for (i = 0; i != array_size; i++) {
		depth[i] = GetDepth(i);
	}

	//printing
	for (i = 0; i != array_size; i++) {
		printf("node %d: parent = %d, depth = %d, ", i, array[i].parent, depth[i]);
		if (array[i].parent == NIL) {
			printf("root, [");
		}
		else if (array[i].left == NIL) {
			printf("leaf, [");
		}
		else
			printf("internal node, [");
		if (array[i].left != NIL) {
			printf("%d", array[i].left);
			temp = array[i].left;
			while (1) {
				if (array[temp].right == NIL) {
					break;
				}
				printf(", %d", array[temp].right);
				temp = array[temp].right;
			}
		}
		printf("]\n");
	}

	return 0;

}
