#include <stdio.h>
#define max(x,y) ((x>y)?x:y)

typedef struct {
	int parent;
	int left;
	int right;
} node_t;

node_t node[100];
int n;

void printTree();
int getSibling(int);
int getDegree(int);
int getDepth(int);
int getHeight(int);

int main() {
	int i;
	int ID, left, right;
	scanf("%d", &n);
	for (i = 0; i < n; i++) node[i].left = node[i].right = node[i].parent = -1;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &ID, &left, &right);
		node[ID].left = left;
		node[ID].right = right;

		if (left != -1) node[left].parent = ID;
		if (right != -1) node[right].parent = ID;
	}
	printTree();
}

void printTree() {
	int i;
	for (i = 0; i < n; i++) {
		printf("node %d: parent = %d, ", i, node[i].parent);
		printf("sibling = %d, ", getSibling(i));
		printf("degree = %d, ", getDegree(i));
		printf("depth = %d, ", getDepth(i));
		printf("height = %d, ", getHeight(i));
		
		if (node[i].parent == -1) printf("root");
		else if (node[i].left == -1 && node[i].right == -1) printf("leaf");
		else printf("internal node");
		printf("\n");
	}
}

int getSibling(int ID) {
	if (node[ID].parent != -1 && node[node[ID].parent].right != ID) return node[node[ID].parent].right;
	if (node[ID].parent != -1 && node[node[ID].parent].left != ID) return node[node[ID].parent].left;
	return -1;
}

int getDegree(int ID) {
	int count = 0;
	if (node[ID].right != -1) count++;
	if (node[ID].left != -1) count++;
	return count;
}

int getDepth(int ID) {
	int depth = 0;
	while (node[ID].parent != -1) {
		depth++;
		ID = node[ID].parent;
	}
	return depth;
}

int getHeight(int ID) {
	if (ID == -1) return -1; 
	return 1 + max(getHeight(node[ID].left), getHeight(node[ID].right));
}
